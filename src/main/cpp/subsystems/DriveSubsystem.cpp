/*----------------------------------------------------------------------------*/
/* Copyright (c) 2019 FIRST. All Rights Reserved.                             */
/* Open Source Software - may be modified and shared by FRC teams. The code   */
/* must be accompanied by the FIRST BSD license file in the root directory of */
/* the project.                                                               */
/*----------------------------------------------------------------------------*/

#include "subsystems/DriveSubsystem.h"

DriveSubsystem::DriveSubsystem(XboxController *controller) : m_controller{controller} {}

void DriveSubsystem::ArcadeDrive()
{
	m_robotDrive.ArcadeDrive(-m_controller->GetY(GenericHID::JoystickHand::kLeftHand),
							 m_controller->GetX(GenericHID::JoystickHand::kLeftHand));
}

void DriveSubsystem::ArcadeDrive(double mag, double rot)
{
	m_robotDrive.ArcadeDrive(mag, rot);
}

void DriveSubsystem::SetMaxOutput(double max)
{
	m_robotDrive.SetMaxOutput(max);
}
