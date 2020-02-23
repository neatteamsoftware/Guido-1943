/*----------------------------------------------------------------------------*/
/* Copyright (c) 2018-2019 FIRST. All Rights Reserved.                        */
/* Open Source Software - may be modified and shared by FRC teams. The code   */
/* must be accompanied by the FIRST BSD license file in the root directory of */
/* the project.                                                               */
/*----------------------------------------------------------------------------*/

package frc.robot;

import edu.wpi.first.cameraserver.CameraServer;
import edu.wpi.first.wpilibj.XboxController;
import edu.wpi.first.wpilibj.shuffleboard.Shuffleboard;
import edu.wpi.first.wpilibj.smartdashboard.SendableChooser;
import edu.wpi.first.wpilibj2.command.Command;
import edu.wpi.first.wpilibj2.command.RunCommand;
import edu.wpi.first.wpilibj2.command.button.JoystickButton;
import frc.robot.commands.PressCommand;
import frc.robot.commands.ReleaseCommand;
import frc.robot.commands.autonomous.CrossLineCommandGroup;
import frc.robot.commands.autonomous.DriveAutonomousCommand;
import frc.robot.subsystems.*;

import static frc.robot.Constants.IOC;

public class RobotContainer {

	private static XboxController controller;

	private static DriveSubsystem driveSubsystem;
	private static EjectionSubsystem ejectionSubsystem;
	private static AscensionSubsystem ascensionSubsystem;
	private static GatheringSubsystem gatheringSubsystem;
	private static TelescopeSubsystem telescopeSubsystem;

	private static SendableChooser<Command> chooser;

	private final PressCommand servoPressCommand;
	private final ReleaseCommand servoReleaseCommand;
	private final CrossLineCommandGroup autonomousLine;
	private final CrossLineCommandGroup autonomousLineEject;

	private boolean servoToggle;

	public RobotContainer() {
		controller = new XboxController(IOC.CONTROLLER_PORT);

		driveSubsystem = new DriveSubsystem();
		ejectionSubsystem = new EjectionSubsystem();
		ascensionSubsystem = new AscensionSubsystem();
		gatheringSubsystem = new GatheringSubsystem();
		telescopeSubsystem = new TelescopeSubsystem();

		chooser = new SendableChooser<>();

		servoPressCommand = new PressCommand(gatheringSubsystem);
		servoReleaseCommand = new ReleaseCommand(gatheringSubsystem);
		autonomousLine = new CrossLineCommandGroup(driveSubsystem, ejectionSubsystem, gatheringSubsystem, true);
		autonomousLineEject = new CrossLineCommandGroup(driveSubsystem, ejectionSubsystem, gatheringSubsystem, false);

		servoToggle = true;

		CameraServer.getInstance().startAutomaticCapture(0);
		CameraServer.getInstance().startAutomaticCapture(1);

		configureAutonomous();
		configureButtonBindings();
		configureCommands();
	}

	private void configureAutonomous() {
		chooser.addOption("No Autonomous", null);
		chooser.addOption("Line", autonomousLine);
		chooser.addOption("Line & Eject", autonomousLineEject);

		Shuffleboard.getTab("Autonomous").add(chooser);
	}

	private void configureButtonBindings() {
		JoystickButton btnA = new JoystickButton(controller, IOC.BTN_A);
		JoystickButton btnB = new JoystickButton(controller, IOC.BTN_B);
		JoystickButton btnX = new JoystickButton(controller, IOC.BTN_X);
		JoystickButton btnY = new JoystickButton(controller, IOC.BTN_Y);
		JoystickButton btnHome = new JoystickButton(controller, IOC.BTN_HOME);

		btnA.whenPressed(() -> {
			servoPressCommand.cancel();
			servoReleaseCommand.schedule();
			servoToggle = true;
		}).whileHeld(() -> {
			gatheringSubsystem.takeIn();
			ejectionSubsystem.setGathering(true);
		}).whenReleased(() -> {
			gatheringSubsystem.stop();
			ejectionSubsystem.setGathering(false);
			servoPressCommand.start(true);
			servoReleaseCommand.cancel();
			servoToggle = false;
		});

		btnB.whileHeld(gatheringSubsystem::takeOut).whenReleased(gatheringSubsystem::stop);

		btnX.whenPressed(() -> {
			if (servoToggle) {
				servoPressCommand.start(false);
				servoReleaseCommand.cancel();
				servoToggle = false;
			} else {
				servoPressCommand.cancel();
				servoReleaseCommand.schedule();
				servoToggle = true;
			}
		});

		btnY.whileHeld(() -> {
			ascensionSubsystem.ascend();
		}).whenReleased(() -> {
			ascensionSubsystem.stop();
		});
		btnHome.whileHeld(() -> {
			ascensionSubsystem.descend();
		}).whenReleased(() -> {
			ascensionSubsystem.stop();
		});
	}

	private void configureCommands() {
		driveSubsystem.setDefaultCommand(new RunCommand(driveSubsystem::arcadeDrive, driveSubsystem));
		ejectionSubsystem.setDefaultCommand(new RunCommand(ejectionSubsystem::run, ejectionSubsystem));
		telescopeSubsystem.setDefaultCommand(new RunCommand(telescopeSubsystem::run, telescopeSubsystem));
	}

	public Command getAutonomousCommand() {
		return chooser.getSelected();
	}

	public static XboxController getController() {
		return controller;
	}
}
