++#pragma config(Sensor, S3,     HTGYRO,              sensorRawValue)
#pragma config(Hubs,  S1, HTMotor,  HTServo,  HTMotor,  none)
#pragma config(Sensor, S2,     Touch,               sensorTouch)
#pragma config(Motor,  mtr_S1_C1_1,     rightm,        tmotorNormal, PIDControl, reversed, encoder)
#pragma config(Motor,  mtr_S1_C1_2,     leftm,         tmotorNormal, PIDControl, encoder)
#pragma config(Motor,  mtr_S1_C3_1,     arm,           tmotorNormal, openLoop, encoder)
#pragma config(Motor,  mtr_S1_C3_2,     motorG,        tmotorNormal, openLoop)
#pragma config(Servo,  srvo_S1_C2_1,    trapdoor,             tServoStandard)
#pragma config(Servo,  srvo_S1_C2_2,    hoop,            tServoStandard)
#pragma config(Servo,  srvo_S1_C2_3,    lefthook,             tServoStandard)
#pragma config(Servo,  srvo_S1_C2_6,    claws,                tServoContinuousRotation)
//*!!Code automatically generated by 'ROBOTC' configuration wizard               !!*//

/////////////////////////////////////////////////////////////////////////////////////////////////////
//
//
//
////////////////////////////////////////////////////////////////////////////////////////////////////

//#include "JoystickDriver.c"  //Include file to "handle" the Bluetooth messages.

// Our Includes

#define MIN_POWER 20

#include "joysticklib.c"

#include "servolib.c"
#include "drivelibrary.c"
#include "armjoysticktest.c"
#include "GyroLib.c"
#include "Initialize.c"



void StopAllMotors()
{
  motor[leftm] = 0;
  motor[rightm] = 0;
  motor[arm] = 0;
}

task ArmUpTask()
{
  ArmToPositionEx(scoreheight);
}

task ArmDownTask1()
{
  // lower the arm
  MoveArm(-40);
  wait1Msec(2800);
  StopArm();
}


task main()
{
  initializeRobotAutoEx();
  waitForStart();

  // move arm up
  StartTask(ArmUpTask);
  // turn towards rolling goal
  spinClockWise(40, 500);

  // move forward a little
  moveFwd(90, 1700);

  //wait, to make sure arm is raised to it's target position
  wait1Msec(1700);

  // move towards goal
  moveFwd(70, 1150);

  // open trap the door to release bottons
  ServoRotate(trapdoor,175);
  wait1Msec(500);

    // move the arm up bit to clear any dangling batons
  MoveArm(100);
  wait1Msec(200);
  StopArm();

  ResetTrapdoor(); // close the trapdoor


  //pushing the rolling goal
  moveFwd(80,2000);

  // back little bit
  moveBwd(80,1250);

  // turn towards bridge
  spinAntiClockWise(80,2800);

   // lower the arm
  StartTask(ArmDownTask1);

  //Balance on bridge
  BalanceOnBridgeUsingGyro();

  StopAllTasks();
  //stop all the motors from moving.
  StopAllMotors();

}
