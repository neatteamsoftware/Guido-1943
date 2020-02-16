package frc.robot.subsystems;


import edu.wpi.first.wpilibj.PWMVictorSPX;
import edu.wpi.first.wpilibj.XboxController;
import edu.wpi.first.wpilibj2.command.SubsystemBase;
import frc.robot.RobotContainer;

import static edu.wpi.first.wpilibj.GenericHID.Hand;
import static frc.robot.Constants.EC;

public class EjectionSubsystem extends SubsystemBase {

    private final PWMVictorSPX motorStrip;
    private final PWMVictorSPX motorGripperLeft;
    private final PWMVictorSPX motorGripperRight;

    public EjectionSubsystem() {
        motorStrip = new PWMVictorSPX(EC.MOTOR_EJECTION);
        motorGripperLeft = new PWMVictorSPX(EC.MOTOR_GRIPPERS[0]);
        motorGripperRight = new PWMVictorSPX(EC.MOTOR_GRIPPERS[1]);
    }

    public void run() {

        XboxController controller = RobotContainer.getController();
        double power = controller.getTriggerAxis(Hand.kRight) - controller.getTriggerAxis(Hand.kLeft);
        motorStrip.set(power * 0.85);

        if (power >= 0.5) {
            motorGripperLeft.set(1.0);
            motorGripperRight.set(1.0);
        } else {
            motorGripperLeft.set(0.0);
            motorGripperRight.set(0.0);
        }
    }
}
