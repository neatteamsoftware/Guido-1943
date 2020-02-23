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

class GatheringSubsystem : public frc2::SubsystemBase
{
public:
	GatheringSubsystem();

	void TakeIn();
	void TakeOut();
	void Stop();

	void StopServos();
	void PressServos();
	void ReleaseServos();

private:
	frc::PWMVictorSPX m_motor;

	frc::Servo m_servoLeft;
	frc::Servo m_servoRight;
};
