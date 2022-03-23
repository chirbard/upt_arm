#include <FlexyStepper.h>

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


char rx_byte;

void setup() {
  Serial.begin(9600);

  stepperA1.connectToPins(MOTOR_A1_STEP_PIN, MOTOR_A1_DIRECTION_PIN);
  stepperA2.connectToPins(MOTOR_A2_STEP_PIN, MOTOR_A2_DIRECTION_PIN);
  stepperA3.connectToPins(MOTOR_A3_STEP_PIN, MOTOR_A3_DIRECTION_PIN);
  stepperA4.connectToPins(MOTOR_A4_STEP_PIN, MOTOR_A4_DIRECTION_PIN);
  stepperA5.connectToPins(MOTOR_A5_STEP_PIN, MOTOR_A5_DIRECTION_PIN);
  stepperA6.connectToPins(MOTOR_A6_STEP_PIN, MOTOR_A6_DIRECTION_PIN);

  stepperA1.setStepsPerRevolution(61440);
  stepperA2.setStepsPerRevolution(76800);
  stepperA3.setStepsPerRevolution(17920);
  stepperA4.setStepsPerRevolution(3840);
  stepperA5.setStepsPerRevolution(1200);
  stepperA6.setStepsPerRevolution(400);
  
  stepperA1.setSpeedInRevolutionsPerSecond(0.03);
  stepperA2.setSpeedInRevolutionsPerSecond(0.03);
  stepperA3.setSpeedInRevolutionsPerSecond(0.03);
  stepperA4.setSpeedInRevolutionsPerSecond(0.09);
  stepperA5.setSpeedInRevolutionsPerSecond(0.09);
  stepperA6.setSpeedInRevolutionsPerSecond(0.09);
  
  stepperA1.setAccelerationInRevolutionsPerSecondPerSecond(0.2);
  stepperA2.setAccelerationInRevolutionsPerSecondPerSecond(0.2);
  stepperA3.setAccelerationInRevolutionsPerSecondPerSecond(0.2);
  stepperA4.setAccelerationInRevolutionsPerSecondPerSecond(0.2);
  stepperA5.setAccelerationInRevolutionsPerSecondPerSecond(0.2);
  stepperA6.setAccelerationInRevolutionsPerSecondPerSecond(0.2);

  stepperA1.setTargetPositionInRevolutions(0);
  stepperA2.setTargetPositionInRevolutions(0);
  stepperA3.setTargetPositionInRevolutions(0);
  stepperA4.setTargetPositionInRevolutions(0);
  stepperA5.setTargetPositionInRevolutions(0);
  stepperA6.setTargetPositionInRevolutions(0);
}

void loop() {
  if (Serial.available() > 0) {
    rx_byte = Serial.read();
    Serial.print("You typed: ");
    Serial.println(rx_byte);
    if (rx_byte == '0') {
      stepperA1.setTargetPositionInRevolutions(0);
      stepperA2.setTargetPositionInRevolutions(0);
      stepperA3.setTargetPositionInRevolutions(0);
      stepperA4.setTargetPositionInRevolutions(0);
      stepperA5.setTargetPositionInRevolutions(0);
      stepperA6.setTargetPositionInRevolutions(0);
    }
    else if (rx_byte == '1') {
      stepperA1.setTargetPositionInRevolutions(radiansToTurns(-0.00));
      stepperA2.setTargetPositionInRevolutions(radiansToTurns(-0.37));
      stepperA3.setTargetPositionInRevolutions(radiansToTurns(0.98));
      stepperA4.setTargetPositionInRevolutions(radiansToTurns(-1.57));
      stepperA5.setTargetPositionInRevolutions(radiansToTurns(-0.62));
      stepperA6.setTargetPositionInRevolutions(radiansToTurns(1.57));
    }
    else if (rx_byte == '2') {
      stepperA1.setTargetPositionInRevolutions(radiansToTurns(0.00));
      stepperA2.setTargetPositionInRevolutions(radiansToTurns(-0.75));
      stepperA3.setTargetPositionInRevolutions(radiansToTurns(0.95));
      stepperA4.setTargetPositionInRevolutions(radiansToTurns(-1.57));
      stepperA5.setTargetPositionInRevolutions(radiansToTurns(-0.21));
      stepperA6.setTargetPositionInRevolutions(radiansToTurns(1.57));
    }
    else if (rx_byte == '3') {
      stepperA1.setTargetPositionInRevolutions(radiansToTurns(-0.84));
      stepperA2.setTargetPositionInRevolutions(radiansToTurns(-0.24));
      stepperA3.setTargetPositionInRevolutions(radiansToTurns(0.11));
      stepperA4.setTargetPositionInRevolutions(radiansToTurns(0.11));
      stepperA5.setTargetPositionInRevolutions(radiansToTurns(-0.85));
      stepperA6.setTargetPositionInRevolutions(radiansToTurns(-0.16));
    }
    else if (rx_byte == '4') {
      stepperA1.setTargetPositionInRevolutions(radiansToTurns(-0.79));
      stepperA2.setTargetPositionInRevolutions(radiansToTurns(-1.25));
      stepperA3.setTargetPositionInRevolutions(radiansToTurns(-0.04));
      stepperA4.setTargetPositionInRevolutions(radiansToTurns(0.76));
      stepperA5.setTargetPositionInRevolutions(radiansToTurns(-1.37));
      stepperA6.setTargetPositionInRevolutions(radiansToTurns(-1.37));
    }
    else if (rx_byte == 't') {
      stepperA1.setTargetPositionInRevolutions(radiansToTurns(0));
      stepperA2.setTargetPositionInRevolutions(radiansToTurns(0));
      stepperA3.setTargetPositionInRevolutions(radiansToTurns(-1.30));
      stepperA4.setTargetPositionInRevolutions(radiansToTurns(0));
      stepperA5.setTargetPositionInRevolutions(radiansToTurns(0));
      stepperA6.setTargetPositionInRevolutions(radiansToTurns(0));
    }
  }

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
   
