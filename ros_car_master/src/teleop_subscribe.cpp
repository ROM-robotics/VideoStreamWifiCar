/*
*	SIGNAL          FUNCTION
*====================================
*     0               STOP
*     1 		FORWARD FULL SPEED
*     2			FORWARD HALF SPEED
*     3			BACKWARD FULL SPEED
*     4			BACKWARD HALF SPEED
*     5 		   RIGHT FORWARD
*     6 		   LEFT  FORWARD
*	  7			   RIGHT BACKWARD
*     8 	       LEFT  BACKWARD
*====================================
*/
#define STOP    0
#define FWFULL  1
#define FWHALF  2
#define BWFULL  3
#define BWHALF  4
#define RIGHTFW 5
#define LEFTFW  6
#define RIGHTBW 7
#define LEFTBW  8

#include "ros/ros.h"
#include "std_msgs/Int16.h"
#include "geometry_msgs/Twist.h"

class Ghost{
public:
	Ghost();
private:
	void callback(const geometry_msgs::Twist::ConstPtr& twist);
	int checkCommand(float fb, float lr);
	ros::NodeHandle nh;
	ros::Publisher command_pub;
	ros::Subscriber sub;
	std_msgs::Int16 c,s;
};
Ghost::Ghost() {
	command_pub = nh.advertise<std_msgs::Int16>("/ros_car_master/command",1);
	sub = nh.subscribe<geometry_msgs::Twist>("/cmd_vel",10,&Ghost::callback, this);
}
void Ghost::callback(const geometry_msgs::Twist::ConstPtr& twist) {

	float front_back = twist->linear.x;
	float left_right = twist->angular.z;

	c.data = checkCommand(front_back,left_right);

	
	command_pub.publish(c);
}
int Ghost::checkCommand(float fb, float lr) {
	// FORWARD	
	if( fb > 0 ) {
		if( fb > 0.5 ) {
			if ( lr > 0.3 ) {
				// forward right turn
				return LEFTFW;
			}				
			else if( lr < -0.3 ) {
				// forward left turn				
				return RIGHTFW;
			}
			else {
				// forward full speed
				return FWFULL;
			}				
		}
		//else if( fb < 0.5 ) 
		else {
			if ( lr > 0.3 ) {
				// forward right turn
				return LEFTFW;
			}				
			else if( lr < -0.3 ) {
				// forward left turn				
				return RIGHTFW;
			}
			else {
				// forward half speed
				return FWHALF;
			}
		}
	}
	// BACKWARD
	else if( fb < 0 ) {
		if( fb < -0.5 )  {
			if ( lr > 0.3 ) {
				// backward right turn
				return LEFTBW;
			}				
			else if( lr < -0.3 ) {
				// backward left turn
				return RIGHTBW;
			}
			else {
				// backward full speed
				return BWFULL;
			}	
		}
		else {
			if ( lr > 0.3 ) {
				// backward right turn
				return LEFTBW;
			}				
			else if( lr < -0.3 ) {
				// backward left turn
				return RIGHTBW;
			}
			else {
				// backward half speed
				return BWHALF;
			}
		}
	}
	else{ return STOP; }
}
int main(int argc,char **argv)
{
	ros::init(argc,argv,"teleop_subscribe");
	Ghost gh;
	ros::spin();
}