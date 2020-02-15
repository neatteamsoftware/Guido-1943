/*----------------------------------------------------------------------------*/
/* Copyright (c) 2019 FIRST. All Rights Reserved.                             */
/* Open Source Software - may be modified and shared by FRC teams. The code   */
/* must be accompanied by the FIRST BSD license file in the root directory of */
/* the project.                                                               */
/*----------------------------------------------------------------------------*/

#pragma once

#include <frc/Servo.h>
#include <frc/PWMVictorSPX.h>
#include <frc/XboxController.h>
#include <frc2/command/SubsystemBase.h>

#include "Constants.h"

using namespace gc;
using namespace frc;
using namespace frc2;

class GatheringSubsystem : public SubsystemBase
{
public:
	GatheringSubsystem();

	void TakeIn();
	void TakeOut();
	void Stop();

	void StopServos();
	void PressServos();
	void ReleaseServos();
	bool IsServoFinished(int state);

private:
	Servo m_servoLeft{SERVO_PORTS[0]};
	Servo m_servoRight{SERVO_PORTS[1]};

	PWMVictorSPX m_motor{MOTOR_GATHERING};
};
