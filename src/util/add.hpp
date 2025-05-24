#pragma once

#include <concepts>

namespace engine::util {

constexpr auto add(std::integral auto lhs, std::same_as<decltype(lhs)> auto rhs)
{
  return lhs + rhs;
}

auto simple_add(int lhs, int rhs) -> int;

auto foo_bar() -> int;

}
