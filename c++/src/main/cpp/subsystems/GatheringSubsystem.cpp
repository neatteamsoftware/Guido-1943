/*----------------------------------------------------------------------------*/
/* Copyright (c) 2019 FIRST. All Rights Reserved.                             */
/* Open Source Software - may be modified and shared by FRC teams. The code   */
/* must be accompanied by the FIRST BSD license file in the root directory of */
/* the project.                                                               */
/*----------------------------------------------------------------------------*/

#include "subsystems/GatheringSubsystem.h"

GatheringSubsystem::GatheringSubsystem()
	: m_motor{gc::kMotorGathering},
	  m_servoLeft{gc::kServoPorts[0]},
	  m_servoRight{gc::kServoPorts[1]}
{
}

void GatheringSubsystem::TakeIn()
{
	m_motor.Set(-0.6);
}

void GatheringSubsystem::TakeOut()
{
	m_motor.Set(0.6);
}

void GatheringSubsystem::Stop()
{
	m_motor.Set(0.0);
}

void GatheringSubsystem::StopServos()
{
	m_servoLeft.StopMotor();
	m_servoRight.StopMotor();
}

void GatheringSubsystem::PressServos()
{
	m_servoLeft.Set(0.7);
	m_servoRight.Set(1.1);
}

void GatheringSubsystem::ReleaseServos()
{
	m_servoLeft.Set(0.1);
	m_servoRight.Set(0.4);
}
