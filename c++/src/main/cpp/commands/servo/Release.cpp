/*----------------------------------------------------------------------------*/
/* Copyright (c) 2019 FIRST. All Rights Reserved.                             */
/* Open Source Software - may be modified and shared by FRC teams. The code   */
/* must be accompanied by the FIRST BSD license file in the root directory of */
/* the project.                                                               */
/*----------------------------------------------------------------------------*/

#include "commands/servo/Release.h"

Release::Release(GatheringSubsystem *subsystem) : m_subsystem{subsystem}
{
}

void Release::Initialize() {}

void Release::Execute()
{
	m_subsystem->ReleaseServos();
}

void Release::End(bool interrupted)
{
	m_subsystem->StopServos();
}

bool Release::IsFinished() { return m_subsystem->IsServoFinished(SERVO_STATE_RELEASE); }
