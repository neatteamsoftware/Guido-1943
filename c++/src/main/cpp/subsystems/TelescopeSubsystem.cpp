/*----------------------------------------------------------------------------*/
/* Copyright (c) 2019 FIRST. All Rights Reserved.                             */
/* Open Source Software - may be modified and shared by FRC teams. The code   */
/* must be accompanied by the FIRST BSD license file in the root directory of */
/* the project.                                                               */
/*----------------------------------------------------------------------------*/

#include "subsystems/TelescopeSubsystem.h"

TelescopeSubsystem::TelescopeSubsystem(frc::XboxController *controller)
	: m_controller{controller},
	  m_motor{tc::kMotorTelescope}
{
}

void TelescopeSubsystem::Run()
{
	double value = m_controller->GetY(frc::GenericHID::JoystickHand::kRightHand);
	if (abs(value) > 0.1)
		m_motor.Set(value);
	else
		m_motor.Set(0);
}
