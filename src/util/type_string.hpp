// Code adapted from here:
// https://rodusek.com/posts/2021/03/09/getting-an-unmangled-type-name-at-compile-time/#finding-a-string-at-compile-time

#pragma once

#include <array>
#include <cstddef>
#include <string_view>
#include <utility>

namespace chess {

#if defined(__clang__) || defined(__GNUC__) || defined(_MSC_VER)

template <typename T> struct type_string
{
  template <std::size_t... Idxs>
  static constexpr auto substring_as_array(
    std::string_view str,
    std::index_sequence<Idxs...> /*unused*/
  )
  {
    return std::array{str[Idxs]...};
  }

  static constexpr auto type_name_array()
  {
#if defined(__clang__)
    constexpr auto prefix = std::string_view{"[T = "};
    constexpr auto suffix = std::string_view{"]"};
    constexpr auto function = std::string_view{__PRETTY_FUNCTION__};
#elif defined(__GNUC__)
    constexpr auto prefix = std::string_view{"with T = "};
    constexpr auto suffix = std::string_view{"]"};
    constexpr auto function = std::string_view{__PRETTY_FUNCTION__};
#elif defined(_MSC_VER)
    constexpr auto prefix = std::string_view{"type_name_array<"};
    constexpr auto suffix = std::string_view{">(void)"};
    constexpr auto function = std::string_view{__FUNCSIG__};
#else
#error Unsupported compiler
#endif

    constexpr auto start = function.find(prefix) + prefix.size();
    constexpr auto end = function.rfind(suffix);

    static_assert(start < end);

    constexpr auto name = function.substr(start, (end - start));
    return substring_as_array(name, std::make_index_sequence<name.size()>{});
  }

  struct type_name_holder
  {
    static constexpr auto value = type_name_array();
  };

  static constexpr auto type_name() -> std::string_view
  {
    constexpr auto& value = type_name_holder::value;
    return std::string_view{value.data(), value.size()};
  }

  static constexpr auto value = type_name();
};

#else

template <typename T> struct type_string
{
  static inline constexpr auto value = std::string_view("Unknown");
};

#endif

template <typename T>
static inline constexpr auto type_string_v = type_string<T>::value;

}  // namespace chess
