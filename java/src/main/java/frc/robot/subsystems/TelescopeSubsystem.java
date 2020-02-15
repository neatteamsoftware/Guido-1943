package frc.robot.subsystems;


import edu.wpi.first.wpilibj.PWMVictorSPX;
import edu.wpi.first.wpilibj.XboxController;
import edu.wpi.first.wpilibj2.command.SubsystemBase;
import frc.robot.RobotContainer;

import static edu.wpi.first.wpilibj.GenericHID.Hand;
import static frc.robot.Constants.TC;

public class TelescopeSubsystem extends SubsystemBase {

    private final PWMVictorSPX motor;

    public TelescopeSubsystem() {
        motor = new PWMVictorSPX(TC.MOTOR_TELESCOPE);
    }

    public void run() {
        XboxController controller = RobotContainer.getController();
        motor.set(controller.getY(Hand.kRight));
    }
}
