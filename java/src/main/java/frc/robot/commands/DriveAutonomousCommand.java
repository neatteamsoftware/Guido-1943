package frc.robot.commands;

import edu.wpi.first.wpilibj2.command.CommandBase;
import edu.wpi.first.wpilibj2.command.RamseteCommand;
import frc.robot.subsystems.DriveSubsystem;


public class DriveAutonomousCommand extends CommandBase {

    private final DriveSubsystem subsystem;

    public DriveAutonomousCommand(DriveSubsystem driveSubsystem) {
        subsystem = driveSubsystem;

        addRequirements(driveSubsystem);
    }

    @Override
    public void initialize() {
        subsystem.arcadeDrive(0.0, 0.0);
    }

    @Override
    public void execute() {
        double rot = 0.0;

        subsystem.arcadeDrive(0.5, rot);
    }

    @Override
    public boolean isFinished() {
        return false;
    }

    @Override
    public void end(boolean interrupted) {
        subsystem.arcadeDrive(0.0, 0.0);
    }
}
