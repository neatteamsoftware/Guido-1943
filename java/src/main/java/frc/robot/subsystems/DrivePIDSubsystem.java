package frc.robot.subsystems;

import edu.wpi.first.wpilibj.controller.PIDController;
import edu.wpi.first.wpilibj2.command.PIDSubsystem;

public class DrivePIDSubsystem extends PIDSubsystem {

	private DrivePIDSubsystem() {
		// TODO: Determine real PID values needed and configure them here
		super(new PIDController(0.0, 0.0, 0.0));

		// TODO: Set the default command, if any, for this subsystem by calling
		// setDefaultCommand(command)
		// in the constructor or in the robot coordination class, such as
		// RobotContainer.
		// Also, you can call addChild(name, sendableChild) to associate sendables with
		// the subsystem
		// such as SpeedControllers, Encoders, DigitalInputs, etc.
	}

	@Override
	public double getMeasurement() {
		// TODO: Return the measurement from the PID sensor, such as an encoder, gyro,
		// potentiometer, etc.
		// This method is automatically called by the subsystem.
		return 0.0;
	}

	@Override
	protected void useOutput(double output, double setpoint) {
		// TODO: Use the output, for example to set the sped on a motor.
	}
}
