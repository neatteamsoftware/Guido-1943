/*----------------------------------------------------------------------------*/
/* Copyright (c) 2019 FIRST. All Rights Reserved.                             */
/* Open Source Software - may be modified and shared by FRC teams. The code   */
/* must be accompanied by the FIRST BSD license file in the root directory of */
/* the project.                                                               */
/*----------------------------------------------------------------------------*/

#include "RobotContainer.h"

RobotContainer::RobotContainer()
{
	ConfigureAutonomous();
	ConfigureButtonBindings();
	ConfigureCommands();
}

void RobotContainer::ConfigureAutonomous()
{
	m_chooser.AddOption("No Autonomous", nullptr);
	Shuffleboard::GetTab("Autonomous").Add(m_chooser);
}

void RobotContainer::ConfigureButtonBindings()
{
	JoystickButton btnA{&m_controller, BTN_A};
	JoystickButton btnB{&m_controller, BTN_B};
	JoystickButton btnX{&m_controller, BTN_X};
	JoystickButton btnY{&m_controller, BTN_Y};
	JoystickButton bumperLeft{&m_controller, BUMPER_LEFT};
	JoystickButton bumperRight{&m_controller, BUMPER_RIGHT};

	btnA.WhileHeld([this] { m_gatheringSubsystem.TakeIn(); }).WhenReleased([this] { m_gatheringSubsystem.Stop(); });
	btnA.WhileHeld([this] { m_gatheringSubsystem.TakeOut(); }).WhenReleased([this] { m_gatheringSubsystem.Stop(); });
}

void RobotContainer::ConfigureCommands()
{
	m_driveSubsystem.SetDefaultCommand(RunCommand([this] { m_driveSubsystem.ArcadeDrive(); }, {&m_driveSubsystem}));
	m_ejectionSubsystem.SetDefaultCommand(RunCommand([this] { m_ejectionSubsystem.Run(); }, {&m_ejectionSubsystem}));
	m_telescopeSubsystem.SetDefaultCommand(RunCommand([this] { m_telescopeSubsystem.Run(); }, {&m_telescopeSubsystem}));
}

Command *RobotContainer::GetAutonomousCommand()
{
	return m_chooser.GetSelected();
}
