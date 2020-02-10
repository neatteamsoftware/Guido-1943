/*----------------------------------------------------------------------------*/
/* Copyright (c) 2019 FIRST. All Rights Reserved.                             */
/* Open Source Software - may be modified and shared by FRC teams. The code   */
/* must be accompanied by the FIRST BSD license file in the root directory of */
/* the project.                                                               */
/*----------------------------------------------------------------------------*/

#include "subsystems/GatheringSubsystem.h"

GatheringSubsystem::GatheringSubsystem() {}

void GatheringSubsystem::TakeIn()
{
	m_motor.Set(-0.75);
}

void GatheringSubsystem::TakeOut()
{
	m_motor.Set(0.75);
}

void GatheringSubsystem::Stop()
{
	m_motor.Set(0);
}
