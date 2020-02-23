/*----------------------------------------------------------------------------*/
/* Copyright (c) 2019 FIRST. All Rights Reserved.                             */
/* Open Source Software - may be modified and shared by FRC teams. The code   */
/* must be accompanied by the FIRST BSD license file in the root directory of */
/* the project.                                                               */
/*----------------------------------------------------------------------------*/

#pragma once

#include <cameraserver/CameraServer.h>

#include <frc/XboxController.h>
#include <frc/shuffleboard/Shuffleboard.h>
#include <frc/smartdashboard/SendableChooser.h>

#include <frc2/command/Command.h>
#include <frc2/command/RunCommand.h>
#include <frc2/command/ParallelCommandGroup.h>
#include <frc2/command/button/JoystickButton.h>
#include <frc2/command/SequentialCommandGroup.h>

#include "Constants.h"

#include "commands/servo/Press.h"
#include "commands/servo/Release.h"
#include "commands/autonomous/EjectCommand.h"
#include "commands/autonomous/DriveTimeCommand.h"
#include "commands/autonomous/DropGrippersCommand.h"

#include "subsystems/DriveSubsystem.h"
#include "subsystems/EjectionSubsystem.h"
#include "subsystems/AscensionSubsystem.h"
#include "subsystems/GatheringSubsystem.h"
#include "subsystems/TelescopeSubsystem.h"

class RobotContainer
{
public:
	RobotContainer();

	void ResetServosOnInit();
	frc2::Command *GetAutonomousCommand();

private:
	frc::XboxController m_controller;

	DriveSubsystem m_driveSubsystem;
	EjectionSubsystem m_ejectionSubsystem;
	AscensionSubsystem m_ascensionSubsystem;
	GatheringSubsystem m_gatheringSubsystem;
	TelescopeSubsystem m_telescopeSubsystem;

	Press m_servoPressCommand;
	Release m_servoReleaseCommand;

	frc::SendableChooser<frc2::Command *> m_chooser;

	bool m_toggleServo = true;

	void ConfigureAutonomous();
	void ConfigureButtonBindings();
	void ConfigureCommands();
};
