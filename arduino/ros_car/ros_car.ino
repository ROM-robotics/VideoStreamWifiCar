#include <ros.h>
#include <std_msgs/Int16.h>
#include <AFMotor.h>

AF_DCMotor rightMotor_1(1),rightMotor_2(2);
AF_DCMotor leftMotor_3(3),leftMotor_4(4);

int command;
int full_speed = 255;
int half_speed = 180;
ros::NodeHandle nh;

void messageCB(const std_msgs::Int16& cmd){
  command = cmd.data; 
}

ros::Subscriber<std_msgs::Int16> sub("/ros_car_master/command",messageCB);

void setup() {  
  nh.initNode();
  nh.subscribe(sub);
}

void loop() {  
  nh.spinOnce();  
  delay(100);
  moveFunction(command);
}
