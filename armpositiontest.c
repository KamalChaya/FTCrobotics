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


//#include "joysticklib.c"

#include "servolib.c"
#include "drivelibrary.c"
//#include "armjoysticktest.c"
#include "ArmLib.c"
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
 // waitForStart();

  // move arm up
  //artTask(ArmUpTask);
  ArmToPositionEx(scoreheight);
  wait1Msec(20000);
  ResetArm();
  StopAllTasks();
  //stop all the motors from moving.
  StopAllMotors();

}