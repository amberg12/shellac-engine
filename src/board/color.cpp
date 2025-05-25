#include "board/color.hpp"

#include "util/to_safe_larger_integral.hpp"
#include "util/to_underlying.hpp"

#include <iostream>
#include <sstream>
#include <string>

[[nodiscard]] auto chess::operator~(chess::color c) noexcept -> chess::color
{
  return static_cast<chess::color>(
    chess::to_underlying(c) ^ chess::to_underlying_of<chess::color>(1)
  );
}

[[nodiscard]] auto chess::to_string(const chess::color& c) -> std::string
{
  switch (c) {
    case color::WHITE: {
      return "color::WHITE";
    }
    case color::BLACK: {
      return "color::BLACK";
    }
    default: {
      std::ostringstream oss;
      oss << "color::"
          << chess::to_safe_larger_integral(chess::to_underlying(c));
      return oss.str();
    }
  }
}

auto chess::operator<<(std::ostream& os, chess::color c) -> std::ostream&
{
  using chess::to_string;
  os << to_string(c);
  return os;
}
