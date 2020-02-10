/*----------------------------------------------------------------------------*/
/* Copyright (c) 2019 FIRST. All Rights Reserved.                             */
/* Open Source Software - may be modified and shared by FRC teams. The code   */
/* must be accompanied by the FIRST BSD license file in the root directory of */
/* the project.                                                               */
/*----------------------------------------------------------------------------*/

//SUbsystem which handles the hardware portion of the shooting for 2020. Designed around a shooter utilizing 2 Falcon motors,
// one top and one bottom.

#include "subsystems/Shoot.h"

// this is the constructor for the shoot subsystem.
Shoot::Shoot() {  

  // create individual motor control objects - assign unique CAN address to each motor drive
  m_MotorTop = new WPI_TalonFX(FRONT_LEFT_MOTOR_CANID);
  m_MotorBottom = new WPI_TalonFX(REAR_LEFT_MOTOR_CANID);


  // configure motor drives with factory default settings
  m_MotorTop->ConfigFactoryDefault();
  m_MotorBottom->ConfigFactoryDefault();

}

void Shoot::SetSpeed(double TopSpeed, double BottomSpeed){
    m_MotorTop->Set(ControlMode::PercentOutput,TopSpeed);
    m_MotorBottom->Set(ControlMode::PercentOutput,BottomSpeed);
}

void Shoot::Stop(void) {
    m_MotorTop->Set(ControlMode::PercentOutput,0);
    m_MotorBottom->Set(ControlMode::PercentOutput,0);
}
/* // idk really why these don't work, they're just copypastas of the shuffleboard code from MainDrive.cpp, but with renamed variables.
void Shoot::InitShuffleboard(void) {
      // Main Tab
    ShuffleboardTab *Tab = &Shuffleboard::GetTab("Shoot");
    
    ShuffleboardLayout *l1 = &Tab->GetLayout("ShooterSpeeds", BuiltInLayouts::kList);
    l1->WithPosition(0,0);
    l1->WithSize(1,2);
    TopSpeed = l1->Add("Top", 0.0).GetEntry();
    BottomSpeed = l1->Add("Bottom", 0.0).GetEntry();
}

void Shoot::UpdateShuffleboard(void) {
    // write speed of top and bottom motors.
    TopSpeed.SetDouble(m_MotorTop->GetMotorOutputPercent());
    BottomSpeed.SetDouble(m_MotorBottom->GetMotorOutputPercent());
}
*/