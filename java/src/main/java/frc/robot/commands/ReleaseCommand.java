package frc.robot.commands;

import edu.wpi.first.wpilibj.Timer;
import edu.wpi.first.wpilibj2.command.CommandBase;
import frc.robot.subsystems.GatheringSubsystem;


public class ReleaseCommand extends CommandBase {

    private final GatheringSubsystem subsystem;

    public ReleaseCommand(GatheringSubsystem gatheringSubsystem) {
        subsystem = gatheringSubsystem;
        addRequirements(gatheringSubsystem);
    }

    @Override
    public void initialize() {
    }

    @Override
    public void execute() {
        subsystem.releaseServos();
    }

    @Override
    public void end(boolean interrupted) {
        subsystem.stopServos();
    }

    @Override
    public boolean isFinished() {
        return false;
    }
}
