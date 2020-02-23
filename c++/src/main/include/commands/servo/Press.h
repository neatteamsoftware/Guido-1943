/*----------------------------------------------------------------------------*/
/* Copyright (c) 2019 FIRST. All Rights Reserved.                             */
/* Open Source Software - may be modified and shared by FRC teams. The code   */
/* must be accompanied by the FIRST BSD license file in the root directory of */
/* the project.                                                               */
/*----------------------------------------------------------------------------*/

#pragma once

#include <frc/Timer.h>
#include <frc/TimedRobot.h>
#include <frc2/command/CommandBase.h>
#include <frc2/command/CommandHelper.h>

#include "Constants.h"

#include "subsystems/GatheringSubsystem.h"

class Press : public frc2::CommandHelper<frc2::CommandBase, Press>
{
public:
	Press(GatheringSubsystem *subsystem);

	void Initialize() override;
	void Execute() override;
	void End(bool interrupted) override;
	bool IsFinished() override;

private:
	GatheringSubsystem *m_subsystem;
};
