// Copyright 2025 Dolphin Emulator Project
// SPDX-License-Identifier: GPL-2.0-or-later

#pragma once

#include <chrono>
#include <string>

#include "Common/CommonTypes.h"
#include "Common/IniFile.h"

class TimePlayed
{
public:
  TimePlayed();

  // not copyable due to the stored section pointer
  TimePlayed(const TimePlayed& other) = delete;
  TimePlayed(TimePlayed&& other) = delete;
  TimePlayed& operator=(const TimePlayed& other) = delete;
  TimePlayed& operator=(TimePlayed&& other) = delete;

  ~TimePlayed();

  void AddTime(const std::string& game_id, std::chrono::milliseconds time_emulated);

  std::chrono::milliseconds GetTimePlayed(const std::string& game_id) const;

  void Reload();

private:
  std::string m_ini_path;
  Common::IniFile m_ini;
  Common::IniFile::Section* m_time_list;
};
