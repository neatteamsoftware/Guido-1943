/*----------------------------------------------------------------------------*/
/* Copyright (c) 2019 FIRST. All Rights Reserved.                             */
/* Open Source Software - may be modified and shared by FRC teams. The code   */
/* must be accompanied by the FIRST BSD license file in the root directory of */
/* the project.                                                               */
/*----------------------------------------------------------------------------*/

#include "subsystems/EjectionSubsystem.h"

EjectionSubsystem::EjectionSubsystem(XboxController *controller) : m_controller{controller} {}

void EjectionSubsystem::Run()
{
	double power = m_controller->GetTriggerAxis(GenericHID::JoystickHand::kRightHand) -
				   m_controller->GetTriggerAxis(GenericHID::JoystickHand::kLeftHand);

	m_motorStrip.Set(power);

	if (power >= 0.5)
	{
		m_motorGripperLeft.Set(1);
		m_motorGripperRight.Set(1);
	}
	else
	{
		m_motorGripperLeft.Set(0);
		m_motorGripperRight.Set(0);
	}
}
