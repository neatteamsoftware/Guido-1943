/*----------------------------------------------------------------------------*/
/* Copyright (c) 2019 FIRST. All Rights Reserved.                             */
/* Open Source Software - may be modified and shared by FRC teams. The code   */
/* must be accompanied by the FIRST BSD license file in the root directory of */
/* the project.                                                               */
/*----------------------------------------------------------------------------*/

#include "subsystems/AscensionSubsystem.h"

AscensionSubsystem::AscensionSubsystem() {}

void AscensionSubsystem::Ascend()
{
	m_motor.Set(1);
}

void AscensionSubsystem::Descend()
{
	m_motor.Set(-1);
}

void AscensionSubsystem::Stop()
{
	m_motor.Set(0);
}
