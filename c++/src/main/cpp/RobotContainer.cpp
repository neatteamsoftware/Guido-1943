/*----------------------------------------------------------------------------*/
/* Copyright (c) 2019 FIRST. All Rights Reserved.                             */
/* Open Source Software - may be modified and shared by FRC teams. The code   */
/* must be accompanied by the FIRST BSD license file in the root directory of */
/* the project.                                                               */
/*----------------------------------------------------------------------------*/

#include "RobotContainer.h"
#include <iostream>
using namespace std;

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
	JoystickButton btnHome{&m_controller, BTN_HOME};

	btnA.WhenPressed([this] {
			m_servoPressCommand.Cancel();
			m_servoReleaseCommand.Schedule();
			m_toggleServo = true;
		})
		.WhileHeld([this] { m_gatheringSubsystem.TakeIn(); })
		.WhenReleased([this] {
			m_gatheringSubsystem.Stop();
			m_servoPressCommand.Schedule();
			m_servoReleaseCommand.Cancel();
			m_toggleServo = false;
		});

	btnB.WhileHeld([this] { m_gatheringSubsystem.TakeOut(); }).WhenReleased([this] { m_gatheringSubsystem.Stop(); });
	btnX.WhileHeld([this] {
		if (m_toggleServo)
		{
			m_servoPressCommand.Schedule();
			m_servoReleaseCommand.Cancel();
			m_toggleServo = false;
		}
		else
		{
			m_servoPressCommand.Cancel();
			m_servoReleaseCommand.Schedule();
			m_toggleServo = true;
		}
	});
	btnY.WhileHeld([this] { m_ascensionSubsystem.Ascend(); }).WhenReleased([this] { m_ascensionSubsystem.Stop(); });
	btnHome.WhileHeld([this] { m_ascensionSubsystem.Descend(); }).WhenReleased([this] { m_ascensionSubsystem.Stop(); });
}

void RobotContainer::ConfigureCommands()
{
	m_driveSubsystem.SetDefaultCommand(RunCommand([this] { m_driveSubsystem.ArcadeDrive(); }, {&m_driveSubsystem}));
	m_ejectionSubsystem.SetDefaultCommand(RunCommand([this] { m_ejectionSubsystem.Run(); }, {&m_ejectionSubsystem}));
	m_telescopeSubsystem.SetDefaultCommand(RunCommand([this] { m_telescopeSubsystem.Run(); }, {&m_telescopeSubsystem}));
}

void RobotContainer::ResetServosOnInit()
{
	m_servoPressCommand.Cancel();
	m_servoReleaseCommand.Schedule();
}

Command *RobotContainer::GetAutonomousCommand()
{
	return m_chooser.GetSelected();
}
