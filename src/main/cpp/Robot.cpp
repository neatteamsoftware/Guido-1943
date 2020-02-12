/*----------------------------------------------------------------------------*/
/* Copyright (c) 2017-2019 FIRST. All Rights Reserved.                        */
/* Open Source Software - may be modified and shared by FRC teams. The code   */
/* must be accompanied by the FIRST BSD license file in the root directory of */
/* the project.                                                               */
/*----------------------------------------------------------------------------*/

#include "Robot.h"

#include <frc/smartdashboard/SmartDashboard.h>
#include <frc2/command/CommandScheduler.h>

void Robot::RobotInit()
{
	m_container.ResetServosOnInit();
}

void Robot::RobotPeriodic() { CommandScheduler::GetInstance().Run(); }

void Robot::DisabledInit()
{
	m_container.ResetServosOnInit();
}

void Robot::DisabledPeriodic() {}

void Robot::AutonomousInit()
{
	m_autonomousCommand = m_container.GetAutonomousCommand();

	if (m_autonomousCommand != nullptr)
		m_autonomousCommand->Schedule();
}

void Robot::AutonomousPeriodic() {}

void Robot::TeleopInit()
{
	if (m_autonomousCommand != nullptr)
	{
		m_autonomousCommand->Cancel();
		m_autonomousCommand = nullptr;
	}
}

void Robot::TeleopPeriodic() {}

void Robot::TestPeriodic() {}

#ifndef RUNNING_FRC_TESTS
int main()
{
	return StartRobot<Robot>();
}
#endif
