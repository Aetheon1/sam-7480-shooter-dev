/*----------------------------------------------------------------------------*/
/* Copyright (c) 2019 FIRST. All Rights Reserved.                             */
/* Open Source Software - may be modified and shared by FRC teams. The code   */
/* must be accompanied by the FIRST BSD license file in the root directory of */
/* the project.                                                               */
/*----------------------------------------------------------------------------*/

#pragma once

#include <frc2/command/SubsystemBase.h>
#include "ctre/Phoenix.h"
#include "RobotMap.h"
#include <frc/Shuffleboard/Shuffleboard.h>

using namespace frc;

class Shoot : public frc2::SubsystemBase {
 private:

  // It's desirable that everything possible under private except
  // for methods that implement subsystem capabilities

  // define drive motors - assign each to specific PWN channel
  WPI_TalonFX *m_MotorTop;
  WPI_TalonFX *m_MotorBottom;

  // Shuffleboard Controls
  nt::NetworkTableEntry LeftDistance, RightDistance; 
  nt::NetworkTableEntry LeftSpeed, RightSpeed;
  nt::NetworkTableEntry LeftEncoder, RightEncoder;
  nt::NetworkTableEntry LeftCurrent, RightCurrent;

 public:

  // constructor - used to initialize specific hardware
  Shoot();

  //stop the motors all-together, should you ever want to do that.
  void Stop(void);

  //initialize shuffleboard
  //void InitShuffleboard(void);

  //update shuffleboard
  //void UpdateShuffleboard(void);

  // SetSpeed method used to set the top and bottom speeds of the motors. This is always passed as a pair.
  void SetSpeed(double TopSpeed, double BottomSpeed);

};