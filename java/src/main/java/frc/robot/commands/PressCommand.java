package frc.robot.commands;

import edu.wpi.first.wpilibj.Timer;
import edu.wpi.first.wpilibj2.command.CommandBase;
import frc.robot.subsystems.GatheringSubsystem;


public class PressCommand extends CommandBase {

    private boolean setTimer;
    private final Timer timer;
    private final GatheringSubsystem subsystem;

    public PressCommand(GatheringSubsystem gatheringSubsystem) {
        timer = new Timer();
        subsystem = gatheringSubsystem;

        addRequirements(gatheringSubsystem);
    }

    public void start(boolean set) {
        setTimer = set;
        schedule();
    }

    @Override
    public void initialize() {
        timer.reset();
        timer.start();
    }

    @Override
    public void execute() {
        if (timer.get() > 1.0 || !setTimer)
            subsystem.pressServos();
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
