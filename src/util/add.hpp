#pragma once

#include <concepts>

namespace engine::util {

constexpr auto add(std::integral auto lhs, std::same_as<decltype(lhs)> auto rhs)
{
  return lhs + rhs;
}

}
