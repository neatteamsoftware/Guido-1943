/*----------------------------------------------------------------------------*/
/* Copyright (c) 2019 FIRST. All Rights Reserved.                             */
/* Open Source Software - may be modified and shared by FRC teams. The code   */
/* must be accompanied by the FIRST BSD license file in the root directory of */
/* the project.                                                               */
/*----------------------------------------------------------------------------*/

#pragma once

#include <frc/PWMVictorSPX.h>
#include <frc2/command/SubsystemBase.h>

#include "Constants.h"

class AscensionSubsystem : public frc2::SubsystemBase
{
public:
	AscensionSubsystem();

	void Ascend();
	void Descend();
	void Stop();

private:
	frc::PWMVictorSPX m_motor;
};
