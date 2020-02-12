/*----------------------------------------------------------------------------*/
/* Copyright (c) 2019 FIRST. All Rights Reserved.                             */
/* Open Source Software - may be modified and shared by FRC teams. The code   */
/* must be accompanied by the FIRST BSD license file in the root directory of */
/* the project.                                                               */
/*----------------------------------------------------------------------------*/

#include "subsystems/TelescopeSubsystem.h"

TelescopeSubsystem::TelescopeSubsystem(XboxController *controller) : m_controller{controller} {}

void TelescopeSubsystem::Run()
{
	m_motor.Set(m_controller->GetY(GenericHID::JoystickHand::kRightHand) * 0.5);
}
