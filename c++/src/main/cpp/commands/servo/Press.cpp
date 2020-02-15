/*----------------------------------------------------------------------------*/
/* Copyright (c) 2019 FIRST. All Rights Reserved.                             */
/* Open Source Software - may be modified and shared by FRC teams. The code   */
/* must be accompanied by the FIRST BSD license file in the root directory of */
/* the project.                                                               */
/*----------------------------------------------------------------------------*/

#include "commands/servo/Press.h"

Press::Press(GatheringSubsystem *subsystem) : m_subsystem{subsystem}
{
}

void Press::Initialize()
{
	m_timer.Reset();
	m_timer.Start();
}

void Press::Execute()
{
	if (m_timer.Get() > 2.0)
	{
		m_subsystem->PressServos();
	}
}

void Press::End(bool interrupted)
{
	m_subsystem->StopServos();
}

bool Press::IsFinished() { return m_subsystem->IsServoFinished(SERVO_STATE_PRESS); }
