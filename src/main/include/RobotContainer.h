/*----------------------------------------------------------------------------*/
/* Copyright (c) 2019 FIRST. All Rights Reserved.                             */
/* Open Source Software - may be modified and shared by FRC teams. The code   */
/* must be accompanied by the FIRST BSD license file in the root directory of */
/* the project.                                                               */
/*----------------------------------------------------------------------------*/

#pragma once

#include <frc/XboxController.h>
#include <frc/shuffleboard/Shuffleboard.h>
#include <frc/smartdashboard/SendableChooser.h>

#include <frc2/command/Command.h>
#include <frc2/command/RunCommand.h>
#include <frc2/command/button/JoystickButton.h>

#include "Constants.h"

#include "subsystems/DriveSubsystem.h"
#include "subsystems/EjectionSubsystem.h"
#include "subsystems/AscensionSubsystem.h"
#include "subsystems/GatheringSubsystem.h"
#include "subsystems/TelescopeSubsystem.h"

using namespace ioc;
using namespace frc;
using namespace frc2;

class RobotContainer
{
public:
	RobotContainer();

	Command *GetAutonomousCommand();

private:
	XboxController m_controller{CONTROLLER_PORT};

	DriveSubsystem m_driveSubsystem{&m_controller};
	EjectionSubsystem m_ejectionSubsystem{&m_controller};
	AscensionSubsystem m_ascensionSubsystem;
	GatheringSubsystem m_gatheringSubsystem;
	TelescopeSubsystem m_telescopeSubsystem{&m_controller};

	SendableChooser<Command *> m_chooser;

	void ConfigureAutonomous();
	void ConfigureButtonBindings();
	void ConfigureCommands();
};
