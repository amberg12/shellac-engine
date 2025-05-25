#pragma once

#include "board/color.hpp"
#include "util/to_underlying.hpp"

#include <cstdint>
#include <iostream>
#include <string>
#include <type_traits>
#include <utility>

namespace chess {

enum piece_type : std::uint8_t
{
  PAWN = 0b000,
  KNIGHT = 0b001,
  BISHOP = 0b010,
  ROOK = 0b011,
  QUEEN = 0b100,
  KING = 0b101,
  NONE = 0b110,
};

[[nodiscard]] auto to_string(const piece_type& pt) -> std::string;

auto operator<<(std::ostream& os, piece_type pt) -> std::ostream&;

}  // namespace chess

namespace chess {

struct piece_unpack
{
  chess::color color;
  chess::piece_type piece_type;
};

class piece
{
public:
  constexpr piece() = default;
  constexpr piece(chess::color color, chess::piece_type piece_type);

  [[nodiscard]] constexpr auto unpack() const -> piece_unpack;

  [[nodiscard]] constexpr auto piece_type() const -> chess::piece_type;
  constexpr auto set_piece_type(chess::piece_type pt) -> void;

  [[nodiscard]] constexpr auto color() const -> chess::color;
  constexpr auto set_color(chess::color color) -> void;

  [[nodiscard]] constexpr auto is_none() const -> bool;

private:
  // Currently, the underlying of piece_type is unsigned, but clang-tidy is
  // failing to recognise so.  The static assert is to work as our own built
  // in warning.
  static_assert(std::is_unsigned_v<
                decltype(chess::to_underlying(std::declval<chess::piece_type>())
                )>);
  // NOLINTNEXTLINE(hicpp-signed-bitwise)
  std::uint8_t m_repr =
    static_cast<std::uint8_t>(0)
    // NOLINTNEXTLINE(hicpp-signed-bitwise)
    | (chess::to_underlying(piece_type::NONE) << static_cast<std::uint8_t>(1));
};

[[nodiscard]] auto to_string(const piece& p) -> std::string;

auto operator<<(std::ostream& os, piece p) -> std::ostream&;

}  // namespace chess

constexpr chess::piece::piece(chess::color color, chess::piece_type piece_type)
{
  set_piece_type(piece_type);
  set_color(color);
}

constexpr auto chess::piece::piece_type() const -> chess::piece_type
{
  return static_cast<chess::piece_type>(m_repr >> static_cast<std::uint8_t>(1));
}

constexpr auto chess::piece::set_piece_type(chess::piece_type pt) -> void
{
  m_repr &= static_cast<std::uint8_t>(0b00000001);
  // Currently, the underlying of piece_type is unsigned, but clang-tidy is
  // failing to recognise so.  The static assert is to work as our own built
  // in warning.
  static_assert(std::is_unsigned_v<decltype(chess::to_underlying(pt))>);
  // NOLINTNEXTLINE(hicpp-signed-bitwise)
  m_repr |= (chess::to_underlying(pt) << static_cast<std::uint8_t>(1));
}

constexpr auto chess::piece::color() const -> chess::color
{
  return static_cast<chess::color>(
    m_repr & static_cast<std::uint8_t>(0b00000001)
  );
}

constexpr auto chess::piece::set_color(chess::color color) -> void
{
  m_repr &= static_cast<std::uint8_t>(0b11111110);
  m_repr |= chess::to_underlying(color);
}

[[nodiscard]] constexpr auto chess::piece::unpack() const -> chess::piece_unpack
{
  return {color(), piece_type()};
}

constexpr auto chess::piece::is_none() const -> bool
{
  return piece_type() == chess::piece_type::NONE;
}
