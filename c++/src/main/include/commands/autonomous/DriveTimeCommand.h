/*----------------------------------------------------------------------------*/
/* Copyright (c) 2019 FIRST. All Rights Reserved.                             */
/* Open Source Software - may be modified and shared by FRC teams. The code   */
/* must be accompanied by the FIRST BSD license file in the root directory of */
/* the project.                                                               */
/*----------------------------------------------------------------------------*/

#pragma once

#include <frc2/Timer.h>
#include <frc2/command/CommandBase.h>
#include <frc2/command/CommandHelper.h>

#include "subsystems/DriveSubsystem.h"

class DriveTimeCommand : public frc2::CommandHelper<frc2::CommandBase, DriveTimeCommand>
{
public:
	DriveTimeCommand(DriveSubsystem *subsystem, double timeout, bool reverse);

	void Initialize() override;
	void Execute() override;
	void End(bool interrupted) override;
	bool IsFinished() override;

private:
	double m_timeout;
	bool m_reverse;

	frc2::Timer m_timer;
	DriveSubsystem *m_subsystem;
};
