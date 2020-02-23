package frc.robot.subsystems;

import edu.wpi.first.wpilibj.PWMVictorSPX;
import edu.wpi.first.wpilibj2.command.SubsystemBase;

import static frc.robot.Constants.AC;

public class AscensionSubsystem extends SubsystemBase {

	PWMVictorSPX motor;

	public AscensionSubsystem() {
		motor = new PWMVictorSPX(AC.MOTOR_ASCENSION);
	}

	public void ascend() {
		motor.set(1.0);
	}

	public void descend() {
		motor.set(-1.0);
	}

	public void stop() {
		motor.set(0.0);
	}
}
