/*----------------------------------------------------------------------------*/
/* Copyright (c) 2019 FIRST. All Rights Reserved.                             */
/* Open Source Software - may be modified and shared by FRC teams. The code   */
/* must be accompanied by the FIRST BSD license file in the root directory of */
/* the project.                                                               */
/*----------------------------------------------------------------------------*/

#pragma once

#include <frc/PWMVictorSPX.h>
#include <frc/XboxController.h>
#include <frc/drive/DifferentialDrive.h>

#include <frc2/command/SubsystemBase.h>

#include "Constants.h"

using namespace dc;
using namespace frc;
using namespace frc2;

class DriveSubsystem : public SubsystemBase
{
public:
	DriveSubsystem(XboxController *controller);

	void ArcadeDrive();
	void ArcadeDrive(double mag, double rot);
	void SetMaxOutput(double max);

private:
	XboxController *m_controller;

	PWMVictorSPX motorsLeft{MOTORS_LEFT};
	PWMVictorSPX motorsRight{MOTORS_RIGHT};

	DifferentialDrive m_robotDrive{motorsLeft, motorsRight};
};
