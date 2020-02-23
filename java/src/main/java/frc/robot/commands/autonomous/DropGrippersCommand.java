/*----------------------------------------------------------------------------*/
/* Copyright (c) 2019 FIRST. All Rights Reserved.                             */
/* Open Source Software - may be modified and shared by FRC teams. The code   */
/* must be accompanied by the FIRST BSD license file in the root directory of */
/* the project.                                                               */
/*----------------------------------------------------------------------------*/

package frc.robot.commands.autonomous;

import edu.wpi.first.wpilibj.Timer;
import edu.wpi.first.wpilibj2.command.CommandBase;
import frc.robot.subsystems.GatheringSubsystem;

public class DropGrippersCommand extends CommandBase {

	private final GatheringSubsystem subsystem;
	private final double timeOut;
	private final Timer timer;

	public DropGrippersCommand(GatheringSubsystem gatheringSubsystem) {
		subsystem = gatheringSubsystem;
		timer = new Timer();
		timeOut = 1.5;

		addRequirements(gatheringSubsystem);
	}

	@Override
	public void initialize() {
		subsystem.stop();
		timer.reset();
		timer.start();
	}

	@Override
	public void execute() {
		subsystem.takeOut();
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
