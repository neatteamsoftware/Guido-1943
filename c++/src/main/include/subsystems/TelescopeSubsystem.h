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

using namespace tc;
using namespace frc;
using namespace frc2;

class TelescopeSubsystem : public SubsystemBase
{
public:
	TelescopeSubsystem(XboxController *controller);
	void Run();

private:
	XboxController *m_controller;
	PWMVictorSPX m_motor{MOTOR_TELESCOPE};
};
