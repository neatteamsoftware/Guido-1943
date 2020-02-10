/*----------------------------------------------------------------------------*/
/* Copyright (c) 2019 FIRST. All Rights Reserved.                             */
/* Open Source Software - may be modified and shared by FRC teams. The code   */
/* must be accompanied by the FIRST BSD license file in the root directory of */
/* the project.                                                               */
/*----------------------------------------------------------------------------*/

#pragma once

namespace ioc
{
constexpr int CONTROLLER_PORT = 0;

constexpr int BTN_A = 1;
constexpr int BTN_B = 2;
constexpr int BTN_X = 3;
constexpr int BTN_Y = 4;

constexpr int BUMPER_LEFT = 5;
constexpr int BUMPER_RIGHT = 6;

constexpr int BTN_LEFT_STICK = 9;
constexpr int BTN_RIGHT_STICK = 10;
} // namespace ioc

namespace dc
{
constexpr int MOTORS_LEFT = 0;
constexpr int MOTORS_RIGHT = 1;
} // namespace dc

namespace ec
{
constexpr int MOTOR_EJECTION = 2;
} // namespace ec

namespace tc
{
constexpr int MOTOR_TELESCOPE = 3;
} // namespace tc

namespace ac
{
constexpr int MOTOR_ASCENSION = 4;
} // namespace ac

namespace gc
{
constexpr int MOTOR_GATHERING = 5;
} // namespace gc
