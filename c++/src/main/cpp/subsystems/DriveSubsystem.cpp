/*----------------------------------------------------------------------------*/
/* Copyright (c) 2019 FIRST. All Rights Reserved.                             */
/* Open Source Software - may be modified and shared by FRC teams. The code   */
/* must be accompanied by the FIRST BSD license file in the root directory of */
/* the project.                                                               */
/*----------------------------------------------------------------------------*/

#include "subsystems/DriveSubsystem.h"

DriveSubsystem::DriveSubsystem(frc::XboxController *controller)
	: m_controller{controller},
	  m_motorsLeft{dc::kMotorsLeft},
	  m_motorsRight{dc::kMotorsRight},
	  m_robotDrive{m_motorsLeft, m_motorsRight}
{
}

void DriveSubsystem::ArcadeDrive()
{
	m_robotDrive.ArcadeDrive(-m_controller->GetY(frc::GenericHID::JoystickHand::kLeftHand),
							 m_controller->GetX(frc::GenericHID::JoystickHand::kLeftHand),
							 m_controller->GetRawButtonPressed(ioc::kBtnLeftStick));
}

void DriveSubsystem::TankDrive()
{
	m_robotDrive.TankDrive(m_controller->GetY(frc::GenericHID::JoystickHand::kLeftHand),
						   m_controller->GetY(frc::GenericHID::JoystickHand::kRightHand));
}

void DriveSubsystem::ArcadeDrive(double mag, double rot)
{
	m_robotDrive.ArcadeDrive(mag, rot);
}

void DriveSubsystem::TankDrive(double left, double right)
{
	m_robotDrive.TankDrive(left, right);
}

void DriveSubsystem::SetMaxOutput(double maxOutput)
{
	m_robotDrive.SetMaxOutput(maxOutput);
}
