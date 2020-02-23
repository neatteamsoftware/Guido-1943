package frc.robot.subsystems;

import edu.wpi.first.wpilibj.PWMVictorSPX;
import edu.wpi.first.wpilibj.XboxController;
import edu.wpi.first.wpilibj2.command.SubsystemBase;
import frc.robot.RobotContainer;

import static edu.wpi.first.wpilibj.GenericHID.Hand;
import static frc.robot.Constants.EC;

public class EjectionSubsystem extends SubsystemBase {

	private boolean gathering;
	private final PWMVictorSPX motorStrip;
	private final PWMVictorSPX motorGripperLeft;
	private final PWMVictorSPX motorGripperRight;

	public EjectionSubsystem() {
		gathering = false;
		motorStrip = new PWMVictorSPX(EC.MOTOR_EJECTION);
		motorGripperLeft = new PWMVictorSPX(EC.MOTOR_GRIPPERS[0]);
		motorGripperRight = new PWMVictorSPX(EC.MOTOR_GRIPPERS[1]);
	}

	public void run() {
		XboxController controller = RobotContainer.getController();

		double power = controller.getTriggerAxis(Hand.kRight) - controller.getTriggerAxis(Hand.kLeft);

		if (power >= 0.8) {
			motorGripperLeft.set(0.8);
			motorGripperRight.set(0.8);
			power *= 0.65;
		} else {
			motorGripperLeft.set(0.0);
			motorGripperRight.set(0.0);
			power *= 0.8;
		}

		motorStrip.set(power);
	}

	public void stop() {
		motorStrip.set(0.0);
		motorGripperLeft.set(0.0);
		motorGripperRight.set(0.0);
	}

	public void eject() {
		motorStrip.set(0.8);
		motorGripperLeft.set(0.8);
		motorGripperRight.set(0.8);
	}

	public void setGathering(boolean g) {
		gathering = g;
	}
}
