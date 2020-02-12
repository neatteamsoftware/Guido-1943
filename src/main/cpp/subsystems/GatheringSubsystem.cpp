/*----------------------------------------------------------------------------*/
/* Copyright (c) 2019 FIRST. All Rights Reserved.                             */
/* Open Source Software - may be modified and shared by FRC teams. The code   */
/* must be accompanied by the FIRST BSD license file in the root directory of */
/* the project.                                                               */
/*----------------------------------------------------------------------------*/

#include "subsystems/GatheringSubsystem.h"

#include <iostream>

using namespace std;

GatheringSubsystem::GatheringSubsystem()
{
}

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

void GatheringSubsystem::StopServos()
{
	m_servoLeft.StopMotor();
	m_servoRight.StopMotor();
}

void GatheringSubsystem::PressServos()
{
	m_servoLeft.Set(0.7);
	m_servoRight.Set(0.7);
}

void GatheringSubsystem::ReleaseServos()
{
	m_servoLeft.Set(0.1);
	m_servoRight.Set(0.1);
}

bool GatheringSubsystem::IsServoFinished(int state)
{
	return false;
}
