/*----------------------------------------------------------------------------*/
/* Copyright (c) 2019 FIRST. All Rights Reserved.                             */
/* Open Source Software - may be modified and shared by FRC teams. The code   */
/* must be accompanied by the FIRST BSD license file in the root directory of */
/* the project.                                                               */
/*----------------------------------------------------------------------------*/

#pragma once

#include <frc/PWMVictorSPX.h>
#include <frc/XboxController.h>
#include <frc2/command/SubsystemBase.h>

#include "Constants.h"

class EjectionSubsystem : public frc2::SubsystemBase
{
public:
	EjectionSubsystem(frc::XboxController *controller);

	void Run();
	void Stop();
	void Eject();

private:
	frc::XboxController *m_controller;

	frc::PWMVictorSPX m_motorStrip;
	frc::PWMVictorSPX m_motorGripperLeft;
	frc::PWMVictorSPX m_motorGripperRight;
};
