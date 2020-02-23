/*----------------------------------------------------------------------------*/
/* Copyright (c) 2019 FIRST. All Rights Reserved.                             */
/* Open Source Software - may be modified and shared by FRC teams. The code   */
/* must be accompanied by the FIRST BSD license file in the root directory of */
/* the project.                                                               */
/*----------------------------------------------------------------------------*/

#include "subsystems/EjectionSubsystem.h"

EjectionSubsystem::EjectionSubsystem(frc::XboxController *controller)
	: m_controller{controller},
	  m_motorStrip{ec::kMotorEjection},
	  m_motorGripperLeft{ec::kMotorGrippers[0]},
	  m_motorGripperRight{ec::kMotorGrippers[1]}
{
}

void EjectionSubsystem::Run()
{
	double power = m_controller->GetTriggerAxis(frc::GenericHID::JoystickHand::kRightHand) -
				   m_controller->GetTriggerAxis(frc::GenericHID::JoystickHand::kLeftHand);

	if (power >= 0.8)
	{
		m_motorGripperLeft.Set(0.8);
		m_motorGripperRight.Set(0.8);
		power *= 0.65;
	}
	else
	{
		m_motorGripperLeft.Set(0.0);
		m_motorGripperRight.Set(0.0);
		power *= 0.8;
	}

	m_motorStrip.Set(power);
}

void EjectionSubsystem::Stop()
{
	m_motorStrip.Set(0.0);
	m_motorGripperLeft.Set(0.0);
	m_motorGripperRight.Set(0.0);
}

void EjectionSubsystem::Eject()
{
	m_motorStrip.Set(0.8);
	m_motorGripperLeft.Set(0.8);
	m_motorGripperRight.Set(0.8);
}
