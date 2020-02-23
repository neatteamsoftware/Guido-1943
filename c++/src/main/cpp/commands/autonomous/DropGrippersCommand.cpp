/*----------------------------------------------------------------------------*/
/* Copyright (c) 2019 FIRST. All Rights Reserved.                             */
/* Open Source Software - may be modified and shared by FRC teams. The code   */
/* must be accompanied by the FIRST BSD license file in the root directory of */
/* the project.                                                               */
/*----------------------------------------------------------------------------*/

#include "commands/autonomous/DropGrippersCommand.h"

DropGrippersCommand::DropGrippersCommand(GatheringSubsystem *subsystem) : m_subsystem{subsystem}
{
	m_timeout = 1.5;

	AddRequirements({subsystem});
}

void DropGrippersCommand::Initialize()
{
	m_subsystem->Stop();
	m_timer.Reset();
	m_timer.Start();
}

void DropGrippersCommand::Execute()
{
	m_subsystem->TakeOut();
}

void DropGrippersCommand::End(bool interrupted)
{
	m_subsystem->Stop();
}

bool DropGrippersCommand::IsFinished() { return (double)m_timer.Get() >= m_timeout; }
