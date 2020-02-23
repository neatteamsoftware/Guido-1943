package frc.robot.commands.autonomous;

import edu.wpi.first.wpilibj2.command.SequentialCommandGroup;
import frc.robot.subsystems.DriveSubsystem;
import frc.robot.subsystems.EjectionSubsystem;
import frc.robot.subsystems.GatheringSubsystem;

public class CrossLineCommandGroup extends SequentialCommandGroup {

	public CrossLineCommandGroup(DriveSubsystem driveSubsystem, EjectionSubsystem ejectionSubsystem,
			GatheringSubsystem gatheringSubsystem, boolean onlyLine) {
		super();

		if (onlyLine) {
			addCommands(new SequentialCommandGroup(new DriveAutonomousCommand(driveSubsystem, 1.0, true),
					new DropGrippersCommand(gatheringSubsystem)));
		} else {
			addCommands(
					new SequentialCommandGroup(new DriveAutonomousCommand(driveSubsystem, 2.0, false),
							new DropGrippersCommand(gatheringSubsystem)),
					new EjectAutonomousCommand(ejectionSubsystem),
					new DriveAutonomousCommand(driveSubsystem, 2.0, true));
		}
	}
}