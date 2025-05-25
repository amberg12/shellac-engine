#pragma once

#include <cstdint>
#include <type_traits>

namespace chess {

template <typename T, typename Enable = void>
struct safe_larger_integral;

template <typename T>
struct safe_larger_integral<T, std::enable_if_t<std::is_integral_v<T>>>
{
  using type = std::conditional_t<std::is_signed_v<T>, std::int64_t, std::uint64_t>;
};

template <typename T>
struct safe_larger_integral<T, std::enable_if_t<std::is_enum_v<T>>>
{
  using underlying = std::underlying_type_t<T>;
  using type = std::conditional_t<std::is_signed_v<underlying>, std::int64_t, std::uint64_t>;
};

template <typename T>
using safe_larger_integral_t = typename safe_larger_integral<T>::type;

template <typename T>
constexpr auto to_safe_larger_integral(T e) -> safe_larger_integral_t<T>
{
  if constexpr (std::is_enum_v<T>) {
    using TSliInfo = safe_larger_integral<T>;
    return static_cast<typename TSliInfo::type>(static_cast<typename TSliInfo::underlying>(e));
  } else {
    return static_cast<safe_larger_integral_t<T>>(e);
  }
}

}  // namespace chess
