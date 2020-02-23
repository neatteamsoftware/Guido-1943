/*----------------------------------------------------------------------------*/
/* Copyright (c) 2019 FIRST. All Rights Reserved.                             */
/* Open Source Software - may be modified and shared by FRC teams. The code   */
/* must be accompanied by the FIRST BSD license file in the root directory of */
/* the project.                                                               */
/*----------------------------------------------------------------------------*/

#include "commands/autonomous/DriveTimeCommand.h"

DriveTimeCommand::DriveTimeCommand(DriveSubsystem *subsystem, double timeout, bool reverse)
	: m_subsystem{subsystem}
{
	m_timeout = timeout;
	m_reverse = reverse;

	AddRequirements({subsystem});
}

void DriveTimeCommand::Initialize()
{
	m_subsystem->ArcadeDrive(0.0, 0.0);
	m_timer.Reset();
	m_timer.Start();
}

void DriveTimeCommand::Execute()
{
	m_subsystem->ArcadeDrive(m_reverse ? -0.7 : 0.7, 0);
}

void DriveTimeCommand::End(bool interrupted)
{
	m_subsystem->ArcadeDrive(0.0, 0.0);
}

bool DriveTimeCommand::IsFinished() { return (double)m_timer.Get() >= m_timeout; }
