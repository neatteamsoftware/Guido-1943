
package frc.robot.subsystems;


import edu.wpi.first.wpilibj.PWMVictorSPX;
import edu.wpi.first.wpilibj.Servo;
import edu.wpi.first.wpilibj2.command.SubsystemBase;

import static frc.robot.Constants.GC;

public class GatheringSubsystem extends SubsystemBase {

    private final PWMVictorSPX motor;
    private final Servo servoLeft;
    private final Servo servoRight;

    public GatheringSubsystem() {
        motor = new PWMVictorSPX(GC.MOTOR_GATHERING);
        servoLeft = new Servo(GC.SERVO_PORTS[0]);
        servoRight = new Servo(GC.SERVO_PORTS[1]);
    }

    public void takeIn() {
        motor.set(-0.7);
    }

    public void takeOut() {
        motor.set(0.7);
    }

    public void stop() {
        motor.set(0.0);
    }

    public void stopServos() {
        servoLeft.stopMotor();
        servoRight.stopMotor();
    }

    public void pressServos() {
        servoLeft.set(0.7);
        servoRight.set(0.65);
    }

    public void releaseServos() {
        servoLeft.set(0.1);
        servoRight.set(0.1);
    }
}
