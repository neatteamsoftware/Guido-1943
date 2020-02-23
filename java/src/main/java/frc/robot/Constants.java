/*----------------------------------------------------------------------------*/
/* Copyright (c) 2018-2019 FIRST. All Rights Reserved.                        */
/* Open Source Software - may be modified and shared by FRC teams. The code   */
/* must be accompanied by the FIRST BSD license file in the root directory of */
/* the project.                                                               */
/*----------------------------------------------------------------------------*/

package frc.robot;

import edu.wpi.first.wpilibj.XboxController;

import static edu.wpi.first.wpilibj.XboxController.*;

/**
 * The Constants class provides a convenient place for teams to hold robot-wide
 * numerical or boolean constants. This class should not be used for any other
 * purpose. All constants should be declared globally (i.e. public static). Do
 * not put anything functional in this class.
 * <p>
 * It is advised to statically import this class (or one of its inner classes)
 * wherever the constants are needed, to reduce verbosity.
 */
public final class Constants {

	public static final class IOC {
		public static final int CONTROLLER_PORT = 0;

		public static final int BTN_A = Button.kA.value;
		public static final int BTN_B = Button.kB.value;
		public static final int BTN_X = Button.kX.value;
		public static final int BTN_Y = Button.kY.value;

		public static final int BUMPER_LEFT = Button.kBumperLeft.value;
		public static final int BUMPER_RIGHT = Button.kBumperRight.value;

		public static final int BTN_LEFT_STICK = Button.kStickLeft.value;
		public static final int BTN_RIGHT_STICK = Button.kStickRight.value;

		public static final int BTN_HOME = Button.kBack.value;
	}

	public static final class DC {
		public static final int MOTORS_LEFT = 0;
		public static final int MOTORS_RIGHT = 1;
	}

	public static final class EC {
		public static final int MOTOR_EJECTION = 2;
		public static final int[] MOTOR_GRIPPERS = { 6, 7 };
	}

	public static final class TC {
		public static final int MOTOR_TELESCOPE = 3;
	}

	public static final class AC {
		public static final int MOTOR_ASCENSION = 4;
	}

	public static final class GC {
		public static final int MOTOR_GATHERING = 5;
		public static final int[] SERVO_PORTS = { 8, 9 };
	}
}
