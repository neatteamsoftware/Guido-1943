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

class DriveSubsystem : public frc2::SubsystemBase
{
public:
	DriveSubsystem(frc::XboxController *controller);

	void ArcadeDrive();
	void TankDrive();
	void ArcadeDrive(double mag, double rot);
	void TankDrive(double left, double right);
	void SetMaxOutput(double max);

private:
	frc::XboxController *m_controller;

	frc::PWMVictorSPX m_motorsLeft;
	frc::PWMVictorSPX m_motorsRight;

	frc::DifferentialDrive m_robotDrive;
};
