/*----------------------------------------------------------------------------*/
/* Copyright (c) 2019 FIRST. All Rights Reserved.                             */
/* Open Source Software - may be modified and shared by FRC teams. The code   */
/* must be accompanied by the FIRST BSD license file in the root directory of */
/* the project.                                                               */
/*----------------------------------------------------------------------------*/

#pragma once

namespace ioc
{
constexpr int kControllerPort = 0;

constexpr int kBtnA = 1;
constexpr int kBtnB = 2;
constexpr int kBtnX = 3;
constexpr int kBtnY = 4;

constexpr int kBumperLeft = 5;
constexpr int kBumperRight = 6;

constexpr int kBtnHome = 7;
constexpr int kBtnMenu = 8;

constexpr int kBtnLeftStick = 9;
constexpr int kBtnRightStick = 10;
} // namespace ioc

namespace dc
{
constexpr int kMotorsLeft = 0;
constexpr int kMotorsRight = 1;
} // namespace dc

namespace ec
{
constexpr int kMotorEjection = 2;
constexpr int kMotorGrippers[] = {6, 7};
} // namespace ec

namespace tc
{
constexpr int kMotorTelescope = 3;
} // namespace tc

namespace ac
{
constexpr int kMotorAscension = 4;
} // namespace ac

namespace gc
{
constexpr int kMotorGathering = 5;
constexpr int kServoPorts[] = {8, 9};
} // namespace gc
