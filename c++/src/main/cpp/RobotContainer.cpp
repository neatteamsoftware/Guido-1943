/*----------------------------------------------------------------------------*/
/* Copyright (c) 2019 FIRST. All Rights Reserved.                             */
/* Open Source Software - may be modified and shared by FRC teams. The code   */
/* must be accompanied by the FIRST BSD license file in the root directory of */
/* the project.                                                               */
/*----------------------------------------------------------------------------*/

#include "RobotContainer.h"

RobotContainer::RobotContainer()
	: m_controller{ioc::kControllerPort},
	  m_driveSubsystem{&m_controller},
	  m_ejectionSubsystem{&m_controller},
	  m_telescopeSubsystem{&m_controller},
	  m_servoPressCommand{&m_gatheringSubsystem},
	  m_servoReleaseCommand{&m_gatheringSubsystem}
{
	frc::CameraServer::GetInstance()->StartAutomaticCapture(0);
	frc::CameraServer::GetInstance()->StartAutomaticCapture(1);

	ConfigureAutonomous();
	ConfigureButtonBindings();
	ConfigureCommands();
}

void RobotContainer::ConfigureAutonomous()
{
	m_chooser.AddOption("No Autonomous", nullptr);
	m_chooser.AddOption("Line", new frc2::ParallelCommandGroup(DriveTimeCommand(&m_driveSubsystem, 1.0, true),
															   DropGrippersCommand(&m_gatheringSubsystem)));
	m_chooser.AddOption("Line & Eject", new frc2::SequentialCommandGroup(
											frc2::ParallelCommandGroup(DriveTimeCommand(&m_driveSubsystem, 2.0, false),
																	   DropGrippersCommand(&m_gatheringSubsystem)),
											EjectCommand(&m_ejectionSubsystem),
											DriveTimeCommand(&m_driveSubsystem, 2.0, true)));

	frc::Shuffleboard::GetTab("Autonomous").Add(m_chooser);
}

void RobotContainer::ConfigureButtonBindings()
{
	frc2::JoystickButton btnA{&m_controller, ioc::kBtnA};
	frc2::JoystickButton btnB{&m_controller, ioc::kBtnB};
	frc2::JoystickButton btnX{&m_controller, ioc::kBtnX};
	frc2::JoystickButton btnY{&m_controller, ioc::kBtnY};
	frc2::JoystickButton btnHome{&m_controller, ioc::kBtnHome};

	btnA.WhenPressed([this] {
			m_servoPressCommand.Cancel();
			m_servoReleaseCommand.Schedule();
			m_toggleServo = true;
		})
		.WhileHeld([this] {
			m_gatheringSubsystem.TakeIn();
		})
		.WhenReleased([this] {
			m_gatheringSubsystem.Stop();
			m_servoPressCommand.Schedule();
			m_servoReleaseCommand.Cancel();
			m_toggleServo = false;
		});

	btnB.WhileHeld([this] { m_gatheringSubsystem.TakeOut(); }).WhenReleased([this] { m_gatheringSubsystem.Stop(); });

	btnX.WhenPressed([this] {
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

	btnY.WhileHeld([this] {
			m_ascensionSubsystem.Ascend();
		})
		.WhenReleased([this] {
			m_ascensionSubsystem.Stop();
		});
	btnHome.WhileHeld([this] {
			   m_ascensionSubsystem.Descend();
		   })
		.WhenReleased([this] {
			m_ascensionSubsystem.Stop();
		});
}

void RobotContainer::ConfigureCommands()
{
	m_driveSubsystem.SetDefaultCommand(frc2::RunCommand([this] { m_driveSubsystem.ArcadeDrive(); }, {&m_driveSubsystem}));
	m_ejectionSubsystem.SetDefaultCommand(frc2::RunCommand([this] { m_ejectionSubsystem.Run(); }, {&m_ejectionSubsystem}));
	m_telescopeSubsystem.SetDefaultCommand(frc2::RunCommand([this] { m_telescopeSubsystem.Run(); }, {&m_telescopeSubsystem}));
}

frc2::Command *RobotContainer::GetAutonomousCommand()
{
	return m_chooser.GetSelected();
}
