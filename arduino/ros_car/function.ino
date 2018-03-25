/*
*  SIGNAL          FUNCTION           FUNCTION_NAME
*====================================================
*     0               STOP            stopAll()
*     1     FORWARD FULL SPEED        fwFullSpeed()
*     2     FORWARD HALF SPEED        fwHalfSpeed()
*     3     BACKWARD FULL SPEED       bwFullSpeed()
*     4     BACKWARD HALF SPEED       bwHalfSpeed()
*     5        RIGHT FORWARD          RightFw()
*     6        LEFT  FORWARD          LeftFw()
*     7        RIGHT BACKWARD         RightBw()
*     8        LEFT  BACKWARD         LeftBw()
*=====================================================
*/

void moveFunction(int c){
  switch(c){
    case 0:
      stopAll();
      break;  
    case 1:
      fwFullSpeed();
      break;
    case 2:
      fwHalfSpeed();
      break;
    case 3:
      bwFullSpeed();
      break;
    case 4:
      bwHalfSpeed();
      break;
    case 5:
      RightFw();
      break;
    case 6:
      LeftFw();
      break;
    case 7:
      RightBw();
      break;
    case 8:
      LeftBw();
      break;
    default:
      stopAll();
      break;
  } 
  command = 0;
}
//Case 1
void fwFullSpeed(){
  motorSpeedSet(full_speed,full_speed);
  rightMotor_1.run(FORWARD);
  rightMotor_2.run(FORWARD);
   leftMotor_3.run(FORWARD);
   leftMotor_4.run(FORWARD);
}
//Case 2
void fwHalfSpeed(){
  motorSpeedSet(half_speed,half_speed);
  rightMotor_1.run(FORWARD);
  rightMotor_2.run(FORWARD);
   leftMotor_3.run(FORWARD);
   leftMotor_4.run(FORWARD);
}
//Case 3
void bwFullSpeed(){
  motorSpeedSet(full_speed,full_speed);
  rightMotor_1.run(BACKWARD);
  rightMotor_2.run(BACKWARD);
   leftMotor_3.run(BACKWARD);
   leftMotor_4.run(BACKWARD);
}
//Case 4
void bwHalfSpeed(){
  motorSpeedSet(half_speed,half_speed);
  rightMotor_1.run(BACKWARD);
  rightMotor_2.run(BACKWARD);
   leftMotor_3.run(BACKWARD);
   leftMotor_4.run(BACKWARD);
}
//Case 5
void RightFw(){
  motorSpeedSet(half_speed,half_speed);
  rightMotor_1.run(BACKWARD);
  rightMotor_2.run(BACKWARD);
   leftMotor_3.run(FORWARD);
   leftMotor_4.run(FORWARD);
}
//Case 6
void LeftFw(){
  motorSpeedSet(half_speed,half_speed);
  rightMotor_1.run(FORWARD);
  rightMotor_2.run(FORWARD);
   leftMotor_3.run(BACKWARD);
   leftMotor_4.run(BACKWARD);
}
//Case 7
void RightBw(){
  motorSpeedSet(half_speed,half_speed);
  rightMotor_1.run(RELEASE);
  rightMotor_2.run(RELEASE);
   leftMotor_3.run(BACKWARD);
   leftMotor_4.run(BACKWARD);
}
//Case 8
void LeftBw(){
  motorSpeedSet(half_speed,half_speed);
  rightMotor_1.run(BACKWARD);
  rightMotor_2.run(BACKWARD);
   leftMotor_3.run(RELEASE);
   leftMotor_4.run(RELEASE);
}
//Case 0
void stopAll(){
  rightMotor_1.run(RELEASE);
  rightMotor_2.run(RELEASE);
   leftMotor_3.run(RELEASE);
   leftMotor_4.run(RELEASE);
}

void motorSpeedSet(int right,int left){
  rightMotor_1.setSpeed(right);
  rightMotor_2.setSpeed(right);
   leftMotor_3.setSpeed(left);
   leftMotor_4.setSpeed(left);
}

