#include "board/piece.hpp"

#include <catch2/catch_test_macros.hpp>

TEST_CASE(
  "piece can be constructed, and the set values can be retrieved",
  "[piece]"
)
{
  const auto piece = chess::piece(chess::color::BLACK, chess::piece_type::ROOK);
  const auto [col, type] = piece.unpack();
  REQUIRE(col == chess::color::BLACK);
  REQUIRE(type == chess::piece_type::ROOK);
}

TEST_CASE("pieces can have their color and types changed safely", "[piece]")
{
  auto piece = chess::piece(chess::color::BLACK, chess::piece_type::ROOK);
  piece.set_color(chess::color::WHITE);
  piece.set_piece_type(chess::piece_type::PAWN);
  piece.set_piece_type(chess::piece_type::BISHOP);
  piece.set_piece_type(chess::piece_type::KNIGHT);

  const auto [col, type] = piece.unpack();

  REQUIRE(col == chess::color::WHITE);
  REQUIRE(type == chess::piece_type::KNIGHT);
}

TEST_CASE("pieces default initialise as none", "[piece]")
{
  const auto piece = chess::piece();
  REQUIRE(piece.is_none());
}

TEST_CASE("piece_type to_string works as intended", "[piece]")
{
  using chess::to_string;

  const auto pawn = chess::piece_type::PAWN;
  REQUIRE(to_string(pawn) == "piece_type::PAWN");

  const auto bishop = chess::piece_type::BISHOP;
  REQUIRE(to_string(bishop) == "piece_type::BISHOP");

  const auto knight = chess::piece_type::KNIGHT;
  REQUIRE(to_string(knight) == "piece_type::KNIGHT");

  const auto rook = chess::piece_type::ROOK;
  REQUIRE(to_string(rook) == "piece_type::ROOK");

  const auto queen = chess::piece_type::QUEEN;
  REQUIRE(to_string(queen) == "piece_type::QUEEN");

  const auto king = chess::piece_type::KING;
  REQUIRE(to_string(king) == "piece_type::KING");

  const auto none = chess::piece_type::NONE;
  REQUIRE(to_string(none) == "piece_type::NONE");

  const auto invalid = static_cast<chess::piece_type>(
    chess::to_underlying(chess::piece_type::NONE) + 1
  );
  REQUIRE(to_string(invalid) == "piece_type::7");
}
