package frc.robot.commands.autonomous;

import edu.wpi.first.wpilibj.Timer;
import edu.wpi.first.wpilibj2.command.CommandBase;
import frc.robot.subsystems.EjectionSubsystem;

public class EjectAutonomousCommand extends CommandBase {

	private final EjectionSubsystem subsystem;
	private final double timeOut;
	private final Timer timer;

	public EjectAutonomousCommand(EjectionSubsystem ejectionSubsystem) {
		subsystem = ejectionSubsystem;
		timer = new Timer();
		timeOut = 2.0;

		addRequirements(ejectionSubsystem);
	}

	@Override
	public void initialize() {
		subsystem.stop();
		timer.reset();
		timer.start();
	}

	@Override
	public void execute() {
		subsystem.eject();
	}

	@Override
	public boolean isFinished() {
		return timer.get() >= timeOut;
	}

	@Override
	public void end(boolean interrupted) {
		subsystem.stop();
	}
}
