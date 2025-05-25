#include "piece.hpp"

#include "util/to_safe_larger_integral.hpp"
#include "util/to_underlying.hpp"

#include <iostream>
#include <sstream>
#include <string>

[[nodiscard]] auto chess::to_string(const chess::piece_type& pt) -> std::string
{
  switch (pt) {
    case chess::piece_type::PAWN: {
      return "piece_type::PAWN";
    }
    case chess::piece_type::KNIGHT: {
      return "piece_type::KNIGHT";
    }
    case chess::piece_type::BISHOP: {
      return "piece_type::BISHOP";
    }
    case chess::piece_type::ROOK: {
      return "piece_type::ROOK";
    }
    case chess::piece_type::QUEEN: {
      return "piece_type::QUEEN";
    }
    case chess::piece_type::KING: {
      return "piece_type::KING";
    }
    case chess::piece_type::NONE: {
      return "piece_type::NONE";
    }
  }

  std::ostringstream oss;
  oss << "piece_type::"
      << chess::to_safe_larger_integral(chess::to_underlying(pt));
  return oss.str();
}

auto chess::operator<<(std::ostream& os, chess::piece_type pt) -> std::ostream&
{
  using chess::to_string;
  os << to_string(pt);
  return os;
}

[[nodiscard]] auto chess::to_string(const chess::piece& p) -> std::string
{
  std::ostringstream oss;
  auto [col, type] = p.unpack();

  oss << "piece::{color=" << col << ", type=" << type << "}";
  return oss.str();
}

auto chess::operator<<(std::ostream& os, chess::piece p) -> std::ostream&
{
  using chess::to_string;
  os << to_string(p);
  return os;
}
