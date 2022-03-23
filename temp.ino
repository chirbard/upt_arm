#if defined(ARDUINO) && ARDUINO >= 100
  #include "Arduino.h"
#else
  #include <WProgram.h>
#endif

#include <ros.h>
#include <std_msgs/UInt16.h>
#include <sensor_msgs/JointState.h>
#include <FlexyStepper.h>

ros::NodeHandle  nh;

FlexyStepper stepperA1;
FlexyStepper stepperA2;
FlexyStepper stepperA3;
FlexyStepper stepperA4;
FlexyStepper stepperA5;
FlexyStepper stepperA6;

double A1_angle=0;
double A2_angle=0;
double A3_angle=0;
double A4_angle=0;
double A5_angle=0;
double A6_angle=0;

const int MOTOR_A1_STEP_PIN =      2 ;
const int MOTOR_A1_DIRECTION_PIN = 3 ;
const int MOTOR_A2_STEP_PIN =      4 ;
const int MOTOR_A2_DIRECTION_PIN = 5 ;
const int MOTOR_A3_STEP_PIN =      6 ;
const int MOTOR_A3_DIRECTION_PIN = 7 ;
const int MOTOR_A4_STEP_PIN =      8 ;
const int MOTOR_A4_DIRECTION_PIN = 9 ;
const int MOTOR_A5_STEP_PIN =      10 ;
const int MOTOR_A5_DIRECTION_PIN = 11 ;
const int MOTOR_A6_STEP_PIN =      12 ;
const int MOTOR_A6_DIRECTION_PIN = 13 ;

double radiansToTurns(float position_radians)
{

  // position_radians = position_radians + 1.6;
  double degrees = position_radians * 57.2958;

  return degrees / 360;

}


void servo_cb(const sensor_msgs::JointState& cmd_msg){
  A1_angle=radiansToTurns(cmd_msg.position[0]);
  A2_angle=radiansToTurns(cmd_msg.position[1]);
  A3_angle=radiansToTurns(cmd_msg.position[2]);
  A4_angle=radiansToTurns(cmd_msg.position[3]);
  A5_angle=radiansToTurns(cmd_msg.position[4]);
  A6_angle=radiansToTurns(cmd_msg.position[5]);

  stepperA1.setTargetPositionInRevolutions(A1_angle);
  stepperA2.setTargetPositionInRevolutions(A2_angle);
  stepperA3.setTargetPositionInRevolutions(A3_angle);
  stepperA4.setTargetPositionInRevolutions(A4_angle);
  stepperA5.setTargetPositionInRevolutions(A5_angle);
  stepperA6.setTargetPositionInRevolutions(A6_angle);

  while((!stepperA1.motionComplete()) || 
        (!stepperA2.motionComplete()) ||
        (!stepperA3.motionComplete()) || 
        (!stepperA4.motionComplete()) ||
        (!stepperA5.motionComplete()) ||  
        (!stepperA6.motionComplete()))
  {
    stepperA1.processMovement();
    stepperA2.processMovement();
    stepperA3.processMovement();
    stepperA4.processMovement();
    stepperA5.processMovement();
    stepperA6.processMovement();
  }
}


ros::Subscriber<sensor_msgs::JointState> sub("joint_states", servo_cb);

void setup(){
  nh.getHardware()->setBaud(115200);
  nh.initNode();
  nh.subscribe(sub);

  stepperA1.connectToPins(MOTOR_A1_STEP_PIN, MOTOR_A1_DIRECTION_PIN);
  stepperA2.connectToPins(MOTOR_A2_STEP_PIN, MOTOR_A2_DIRECTION_PIN);
  stepperA3.connectToPins(MOTOR_A3_STEP_PIN, MOTOR_A3_DIRECTION_PIN);
  stepperA4.connectToPins(MOTOR_A4_STEP_PIN, MOTOR_A4_DIRECTION_PIN);
  stepperA5.connectToPins(MOTOR_A5_STEP_PIN, MOTOR_A5_DIRECTION_PIN);
  stepperA6.connectToPins(MOTOR_A6_STEP_PIN, MOTOR_A6_DIRECTION_PIN);

  delay(1);

  stepperA1.setStepsPerRevolution(61440);
  stepperA2.setStepsPerRevolution(76800);
  stepperA3.setStepsPerRevolution(17920);
  stepperA4.setStepsPerRevolution(3840);
  stepperA5.setStepsPerRevolution(1200);
  stepperA6.setStepsPerRevolution(400);
  
  stepperA1.setSpeedInRevolutionsPerSecond(0.03);
  stepperA2.setSpeedInRevolutionsPerSecond(0.03);
  stepperA3.setSpeedInRevolutionsPerSecond(0.03);
  stepperA4.setSpeedInRevolutionsPerSecond(0.03);
  stepperA5.setSpeedInRevolutionsPerSecond(0.03);
  stepperA6.setSpeedInRevolutionsPerSecond(0.03);
  
  stepperA1.setAccelerationInRevolutionsPerSecondPerSecond(0.2);
  stepperA2.setAccelerationInRevolutionsPerSecondPerSecond(0.2);
  stepperA3.setAccelerationInRevolutionsPerSecondPerSecond(0.2);
  stepperA4.setAccelerationInRevolutionsPerSecondPerSecond(0.2);
  stepperA5.setAccelerationInRevolutionsPerSecondPerSecond(0.2);
  stepperA6.setAccelerationInRevolutionsPerSecondPerSecond(0.2);
}

void loop(){
  nh.spinOnce();
}
