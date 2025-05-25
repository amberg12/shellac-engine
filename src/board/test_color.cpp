#include "board/color.hpp"
#include "util/to_underlying.hpp"

#include <catch2/catch_test_macros.hpp>
#include <sstream>

static constexpr chess::color INVALID_COLOR =
  static_cast<chess::color>(chess::to_underlying(chess::color::BLACK) + 1);

TEST_CASE("color converts to it's string rep", "[color]")
{
  using chess::to_string, std::to_string;

  const auto white = chess::color::WHITE;
  REQUIRE(to_string(white) == "color::WHITE");

  const auto black = chess::color::BLACK;
  REQUIRE(to_string(black) == "color::BLACK");

  REQUIRE(to_string(INVALID_COLOR) == "color::2");
}

TEST_CASE("color converts to it's string rep in stream operations", "[color]")
{
  std::ostringstream oss_white;
  oss_white << chess::color::WHITE;
  REQUIRE(oss_white.str() == "color::WHITE");

  std::ostringstream oss_black;
  oss_black << chess::color::BLACK;
  REQUIRE(oss_black.str() == "color::BLACK");

  std::ostringstream oss_invalid;
  oss_invalid << INVALID_COLOR;
  REQUIRE(oss_invalid.str() == "color::2");
}

TEST_CASE("color not operator flips the color", "[color]")
{
  const auto white = chess::color::WHITE;
  REQUIRE(~white == chess::color::BLACK);

  const auto black = chess::color::BLACK;
  REQUIRE(~black == chess::color::WHITE);
}
