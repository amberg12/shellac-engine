#pragma once

#include "board/color.hpp"
#include "util/to_underlying.hpp"

#include <cstdint>

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

  constexpr auto unpack() const -> piece_unpack;
  constexpr auto unpack() -> piece_unpack;

  constexpr auto piece_type() const -> chess::piece_type;
  constexpr auto piece_type() -> chess::piece_type;
  constexpr auto set_piece_type(chess::piece_type piece_type) -> void;

  constexpr auto color() const -> chess::color;
  constexpr auto color() -> chess::color;
  constexpr auto set_color(chess::color color) -> void;

  constexpr auto is_none() const -> bool;
  constexpr auto is_none() -> bool;

private:
  std::uint8_t m_repr = 0 | (piece_type::NONE << 1);
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
  return static_cast<chess::piece_type>(m_repr >> 1);
}

constexpr auto chess::piece::piece_type() -> chess::piece_type
{
  return static_cast<chess::piece_type>(m_repr >> 1);
}

constexpr auto chess::piece::set_piece_type(chess::piece_type piece_type)
  -> void
{
  m_repr &= 0b00000001;
  m_repr |= (chess::to_underlying(piece_type) << 1);
}

constexpr auto chess::piece::color() const -> chess::color
{
  return static_cast<chess::color>(m_repr & 0b00000001);
}

constexpr auto chess::piece::color() -> chess::color
{
  return static_cast<chess::color>(m_repr & 0b00000001);
}

constexpr auto chess::piece::set_color(chess::color color) -> void
{
  m_repr &= 0b11111110;
  m_repr |= chess::to_underlying(color);
}

constexpr auto chess::piece::unpack() const -> chess::piece_unpack
{
  return {color(), piece_type()};
}

constexpr auto chess::piece::unpack() -> chess::piece_unpack
{
  return {color(), piece_type()};
}

constexpr auto chess::piece::is_none() const -> bool
{
  return piece_type() == chess::piece_type::NONE;
}

constexpr auto chess::piece::is_none() -> bool
{
  return piece_type() == chess::piece_type::NONE;
}
