/*----------------------------------------------------------------------------*/
/* Copyright (c) 2019 FIRST. All Rights Reserved.                             */
/* Open Source Software - may be modified and shared by FRC teams. The code   */
/* must be accompanied by the FIRST BSD license file in the root directory of */
/* the project.                                                               */
/*----------------------------------------------------------------------------*/

#include "commands/autonomous/EjectCommand.h"

EjectCommand::EjectCommand(EjectionSubsystem *subsystem) : m_subsystem{subsystem}
{
	m_timeout = 2.0;

	AddRequirements({subsystem});
}

void EjectCommand::Initialize()
{
	m_subsystem->Stop();
	m_timer.Reset();
	m_timer.Start();
}

void EjectCommand::Execute()
{
	m_subsystem->Eject();
}

void EjectCommand::End(bool interrupted)
{
	m_subsystem->Stop();
}

bool EjectCommand::IsFinished() { return (double)m_timer.Get() >= m_timeout; }
