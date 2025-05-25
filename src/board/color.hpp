#pragma once

#include <cstdint>
#include <iostream>
#include <string>

namespace chess {

enum class color : std::uint8_t
{
  WHITE,
  BLACK,
};

[[nodiscard]] auto operator~(color c) noexcept -> color;

[[nodiscard]] auto to_string(const color& c) -> std::string;

auto operator<<(std::ostream& os, color c) -> std::ostream&;

}  // namespace chess
