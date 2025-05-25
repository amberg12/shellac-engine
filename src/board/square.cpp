#include "board/square.hpp"

#include "util/to_safe_larger_integral.hpp"

#include <iostream>
#include <sstream>
#include <string>

auto chess::to_string(const chess::square& sq) -> std::string
{
  using SquareInt = chess::safe_larger_integral_t<chess::square>;

  std::ostringstream oss;
  oss << "square::";

  auto [rank, file] = to_rank_file<SquareInt>(sq);

  if (rank < 8 && file < 8) {
    oss << static_cast<char>('A' + file);
    oss << (1 + rank);
  } else {
    oss << chess::to_safe_larger_integral(sq);
  }

  return oss.str();
}

auto chess::operator<<(std::ostream& os, chess::square sq) -> std::ostream&
{
  using chess::to_string;
  os << to_string(sq);
  return os;
}
