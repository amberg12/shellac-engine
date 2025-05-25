#pragma once

#include <type_traits>

namespace chess {

template <typename T>
[[nodiscard]] constexpr auto to_underlying(T e) noexcept
  -> std::underlying_type_t<T>
{
  return static_cast<std::underlying_type_t<T>>(e);
}

template <typename T, typename E>
[[nodiscard]] constexpr auto to_underlying_of(E e) noexcept
  -> std::underlying_type_t<T>
{
  return static_cast<std::underlying_type_t<T>>(e);
}

}  // namespace chess
