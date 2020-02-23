package frc.robot.commands.autonomous;

import com.kauailabs.navx.frc.AHRS;

import edu.wpi.first.wpilibj.I2C;
import edu.wpi.first.wpilibj.Timer;
import edu.wpi.first.wpilibj2.command.CommandBase;
import frc.robot.subsystems.DriveSubsystem;

public class DriveAutonomousCommand extends CommandBase {

	private final DriveSubsystem subsystem;
	private final double timeOut;
	private final Timer timer;
	private final boolean reverse;

	public DriveAutonomousCommand(DriveSubsystem driveSubsystem, double time, boolean isReverse) {
		subsystem = driveSubsystem;
		timer = new Timer();
		timeOut = time;
		reverse = isReverse;

		addRequirements(driveSubsystem);
	}

	@Override
	public void initialize() {
		subsystem.arcadeDrive(0.0, 0.0);
		timer.reset();
		timer.start();
	}

	@Override
	public void execute() {
		subsystem.arcadeDrive(reverse ? -0.7 : 0.7, 0);
	}

	@Override
	public boolean isFinished() {
		return timer.get() >= timeOut;
	}

	@Override
	public void end(boolean interrupted) {
		subsystem.arcadeDrive(0.0, 0.0);
	}
}
