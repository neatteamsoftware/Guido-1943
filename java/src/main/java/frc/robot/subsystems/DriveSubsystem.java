/*----------------------------------------------------------------------------*/
/* Copyright (c) 2018-2019 FIRST. All Rights Reserved.                        */
/* Open Source Software - may be modified and shared by FRC teams. The code   */
/* must be accompanied by the FIRST BSD license file in the root directory of */
/* the project.                                                               */
/*----------------------------------------------------------------------------*/

package frc.robot.subsystems;

import edu.wpi.first.wpilibj.GenericHID.Hand;
import edu.wpi.first.wpilibj.PWMVictorSPX;
import edu.wpi.first.wpilibj.XboxController;
import edu.wpi.first.wpilibj.drive.DifferentialDrive;
import edu.wpi.first.wpilibj.interfaces.Gyro;
import edu.wpi.first.wpilibj2.command.SubsystemBase;
import frc.robot.Constants;
import frc.robot.RobotContainer;

import static frc.robot.Constants.*;
import static frc.robot.Constants.DC;

public class DriveSubsystem extends SubsystemBase {

	private final DifferentialDrive robotDrive;

	public DriveSubsystem() {
		PWMVictorSPX leftMotors = new PWMVictorSPX(DC.MOTORS_LEFT);
		PWMVictorSPX rightMotors = new PWMVictorSPX(DC.MOTORS_RIGHT);

		robotDrive = new DifferentialDrive(leftMotors, rightMotors);
	}

	public void arcadeDrive() {
		XboxController controller = RobotContainer.getController();
		robotDrive.arcadeDrive(-controller.getY(Hand.kLeft), controller.getX(Hand.kLeft),
				controller.getRawButtonPressed(IOC.BTN_LEFT_STICK));

		// tank drive
		// robotDrive.tankDrive(-controller.getY(Hand.kLeft),
		// -controller.getY(Hand.kRight));
	}

	public void arcadeDrive(double mag, double rot) {
		robotDrive.arcadeDrive(mag, rot);
	}

	public void tankDrive() {
		XboxController controller = RobotContainer.getController();
		robotDrive.tankDrive(controller.getY(Hand.kLeft), controller.getY(Hand.kRight));
	}

	public void tankDrive(double left, double right) {
		robotDrive.tankDrive(left, right);
	}

	public void setMaxOutput(double maxOutput) {
		robotDrive.setMaxOutput(maxOutput);
	}
}
