#pragma once

#include <array>
#include <cstdint>
#include <iostream>
#include <string>
#include <type_traits>

namespace chess {

enum class square : std::uint8_t
{
  A1 = 0,
  B1,
  C1,
  D1,
  E1,
  F1,
  G1,
  H1,
  A2,
  B2,
  C2,
  D2,
  E2,
  F2,
  G2,
  H2,
  A3,
  B3,
  C3,
  D3,
  E3,
  F3,
  G3,
  H3,
  A4,
  B4,
  C4,
  D4,
  E4,
  F4,
  G4,
  H4,
  A5,
  B5,
  C5,
  D5,
  E5,
  F5,
  G5,
  H5,
  A6,
  B6,
  C6,
  D6,
  E6,
  F6,
  G6,
  H6,
  A7,
  B7,
  C7,
  D7,
  E7,
  F7,
  G7,
  H7,
  A8,
  B8,
  C8,
  D8,
  E8,
  F8,
  G8,
  H8,
};

template <typename T, typename = std::enable_if_t<std::is_integral_v<T>>>
struct square_unpack
{
  T rank;
  T file;
};

static constexpr std::array<square, 64> SQUARES = {
  square::A1, square::B1, square::C1, square::D1, square::E1, square::F1,
  square::G1, square::H1, square::A2, square::B2, square::C2, square::D2,
  square::E2, square::F2, square::G2, square::H2, square::A3, square::B3,
  square::C3, square::D3, square::E3, square::F3, square::G3, square::H3,
  square::A4, square::B4, square::C4, square::D4, square::E4, square::F4,
  square::G4, square::H4, square::A5, square::B5, square::C5, square::D5,
  square::E5, square::F5, square::G5, square::H5, square::A6, square::B6,
  square::C6, square::D6, square::E6, square::F6, square::G6, square::H6,
  square::A7, square::B7, square::C7, square::D7, square::E7, square::F7,
  square::G7, square::H7, square::A8, square::B8, square::C8, square::D8,
  square::E8, square::F8, square::G8, square::H8,
};

template <typename T, typename = std::enable_if_t<std::is_integral_v<T>>>
constexpr auto from_rank_file(T rank, T file) -> square
{
  return static_cast<square>((rank * 8) + file);
}

template <typename T, typename = std::enable_if_t<std::is_integral_v<T>>>
constexpr auto to_file(square sq) -> T
{
  return static_cast<T>(sq) % 8;
}

template <typename T, typename = std::enable_if_t<std::is_integral_v<T>>>
constexpr auto to_rank(square sq) -> T
{
  return static_cast<T>(sq) / 8;
}

template <typename T, typename = std::enable_if_t<std::is_integral_v<T>>>
constexpr auto to_rank_file(square sq) -> square_unpack<T>
{
  return {to_rank<T>(sq), to_file<T>(sq)};
}

auto to_string(const square& sq) -> std::string;

auto operator<<(std::ostream& os, square sq) -> std::ostream&;

}  // namespace chess
