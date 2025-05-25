#include "board/square.hpp"

#include <catch2/catch_test_macros.hpp>
#include <sstream>

TEST_CASE("squares are constructed correctly from rank and file", "[square]")
{
  REQUIRE(chess::from_rank_file(0, 0) == chess::square::A1);
  REQUIRE(chess::from_rank_file(0, 1) == chess::square::B1);
  REQUIRE(chess::from_rank_file(0, 2) == chess::square::C1);
  REQUIRE(chess::from_rank_file(0, 3) == chess::square::D1);
  REQUIRE(chess::from_rank_file(0, 4) == chess::square::E1);
  REQUIRE(chess::from_rank_file(0, 5) == chess::square::F1);
  REQUIRE(chess::from_rank_file(0, 6) == chess::square::G1);
  REQUIRE(chess::from_rank_file(0, 7) == chess::square::H1);

  REQUIRE(chess::from_rank_file(1, 0) == chess::square::A2);
  REQUIRE(chess::from_rank_file(1, 1) == chess::square::B2);
  REQUIRE(chess::from_rank_file(1, 2) == chess::square::C2);
  REQUIRE(chess::from_rank_file(1, 3) == chess::square::D2);
  REQUIRE(chess::from_rank_file(1, 4) == chess::square::E2);
  REQUIRE(chess::from_rank_file(1, 5) == chess::square::F2);
  REQUIRE(chess::from_rank_file(1, 6) == chess::square::G2);
  REQUIRE(chess::from_rank_file(1, 7) == chess::square::H2);

  REQUIRE(chess::from_rank_file(2, 0) == chess::square::A3);
  REQUIRE(chess::from_rank_file(2, 1) == chess::square::B3);
  REQUIRE(chess::from_rank_file(2, 2) == chess::square::C3);
  REQUIRE(chess::from_rank_file(2, 3) == chess::square::D3);
  REQUIRE(chess::from_rank_file(2, 4) == chess::square::E3);
  REQUIRE(chess::from_rank_file(2, 5) == chess::square::F3);
  REQUIRE(chess::from_rank_file(2, 6) == chess::square::G3);
  REQUIRE(chess::from_rank_file(2, 7) == chess::square::H3);

  REQUIRE(chess::from_rank_file(3, 0) == chess::square::A4);
  REQUIRE(chess::from_rank_file(3, 1) == chess::square::B4);
  REQUIRE(chess::from_rank_file(3, 2) == chess::square::C4);
  REQUIRE(chess::from_rank_file(3, 3) == chess::square::D4);
  REQUIRE(chess::from_rank_file(3, 4) == chess::square::E4);
  REQUIRE(chess::from_rank_file(3, 5) == chess::square::F4);
  REQUIRE(chess::from_rank_file(3, 6) == chess::square::G4);
  REQUIRE(chess::from_rank_file(3, 7) == chess::square::H4);

  REQUIRE(chess::from_rank_file(4, 0) == chess::square::A5);
  REQUIRE(chess::from_rank_file(4, 1) == chess::square::B5);
  REQUIRE(chess::from_rank_file(4, 2) == chess::square::C5);
  REQUIRE(chess::from_rank_file(4, 3) == chess::square::D5);
  REQUIRE(chess::from_rank_file(4, 4) == chess::square::E5);
  REQUIRE(chess::from_rank_file(4, 5) == chess::square::F5);
  REQUIRE(chess::from_rank_file(4, 6) == chess::square::G5);
  REQUIRE(chess::from_rank_file(4, 7) == chess::square::H5);

  REQUIRE(chess::from_rank_file(5, 0) == chess::square::A6);
  REQUIRE(chess::from_rank_file(5, 1) == chess::square::B6);
  REQUIRE(chess::from_rank_file(5, 2) == chess::square::C6);
  REQUIRE(chess::from_rank_file(5, 3) == chess::square::D6);
  REQUIRE(chess::from_rank_file(5, 4) == chess::square::E6);
  REQUIRE(chess::from_rank_file(5, 5) == chess::square::F6);
  REQUIRE(chess::from_rank_file(5, 6) == chess::square::G6);
  REQUIRE(chess::from_rank_file(5, 7) == chess::square::H6);

  REQUIRE(chess::from_rank_file(6, 0) == chess::square::A7);
  REQUIRE(chess::from_rank_file(6, 1) == chess::square::B7);
  REQUIRE(chess::from_rank_file(6, 2) == chess::square::C7);
  REQUIRE(chess::from_rank_file(6, 3) == chess::square::D7);
  REQUIRE(chess::from_rank_file(6, 4) == chess::square::E7);
  REQUIRE(chess::from_rank_file(6, 5) == chess::square::F7);
  REQUIRE(chess::from_rank_file(6, 6) == chess::square::G7);
  REQUIRE(chess::from_rank_file(6, 7) == chess::square::H7);

  REQUIRE(chess::from_rank_file(7, 0) == chess::square::A8);
  REQUIRE(chess::from_rank_file(7, 1) == chess::square::B8);
  REQUIRE(chess::from_rank_file(7, 2) == chess::square::C8);
  REQUIRE(chess::from_rank_file(7, 3) == chess::square::D8);
  REQUIRE(chess::from_rank_file(7, 4) == chess::square::E8);
  REQUIRE(chess::from_rank_file(7, 5) == chess::square::F8);
  REQUIRE(chess::from_rank_file(7, 6) == chess::square::G8);
  REQUIRE(chess::from_rank_file(7, 7) == chess::square::H8);
}

TEST_CASE("ranks and files are correctly retrieved from squares", "[square]")
{
  const auto [a1_rank, a1_file] = chess::to_rank_file<int>(chess::square::A1);
  REQUIRE(a1_rank == 0);
  REQUIRE(a1_file == 0);

  const auto [b1_rank, b1_file] = chess::to_rank_file<int>(chess::square::B1);
  REQUIRE(b1_rank == 0);
  REQUIRE(b1_file == 1);

  const auto [c1_rank, c1_file] = chess::to_rank_file<int>(chess::square::C1);
  REQUIRE(c1_rank == 0);
  REQUIRE(c1_file == 2);

  const auto [d1_rank, d1_file] = chess::to_rank_file<int>(chess::square::D1);
  REQUIRE(d1_rank == 0);
  REQUIRE(d1_file == 3);

  const auto [e1_rank, e1_file] = chess::to_rank_file<int>(chess::square::E1);
  REQUIRE(e1_rank == 0);
  REQUIRE(e1_file == 4);

  const auto [f1_rank, f1_file] = chess::to_rank_file<int>(chess::square::F1);
  REQUIRE(f1_rank == 0);
  REQUIRE(f1_file == 5);

  const auto [g1_rank, g1_file] = chess::to_rank_file<int>(chess::square::G1);
  REQUIRE(g1_rank == 0);
  REQUIRE(g1_file == 6);

  const auto [h1_rank, h1_file] = chess::to_rank_file<int>(chess::square::H1);
  REQUIRE(h1_rank == 0);
  REQUIRE(h1_file == 7);

  const auto [a2_rank, a2_file] = chess::to_rank_file<int>(chess::square::A2);
  REQUIRE(a2_rank == 1);
  REQUIRE(a2_file == 0);

  const auto [b2_rank, b2_file] = chess::to_rank_file<int>(chess::square::B2);
  REQUIRE(b2_rank == 1);
  REQUIRE(b2_file == 1);

  const auto [c2_rank, c2_file] = chess::to_rank_file<int>(chess::square::C2);
  REQUIRE(c2_rank == 1);
  REQUIRE(c2_file == 2);

  const auto [d2_rank, d2_file] = chess::to_rank_file<int>(chess::square::D2);
  REQUIRE(d2_rank == 1);
  REQUIRE(d2_file == 3);

  const auto [e2_rank, e2_file] = chess::to_rank_file<int>(chess::square::E2);
  REQUIRE(e2_rank == 1);
  REQUIRE(e2_file == 4);

  const auto [f2_rank, f2_file] = chess::to_rank_file<int>(chess::square::F2);
  REQUIRE(f2_rank == 1);
  REQUIRE(f2_file == 5);

  const auto [g2_rank, g2_file] = chess::to_rank_file<int>(chess::square::G2);
  REQUIRE(g2_rank == 1);
  REQUIRE(g2_file == 6);

  const auto [h2_rank, h2_file] = chess::to_rank_file<int>(chess::square::H2);
  REQUIRE(h2_rank == 1);
  REQUIRE(h2_file == 7);

  const auto [a3_rank, a3_file] = chess::to_rank_file<int>(chess::square::A3);
  REQUIRE(a3_rank == 2);
  REQUIRE(a3_file == 0);

  const auto [b3_rank, b3_file] = chess::to_rank_file<int>(chess::square::B3);
  REQUIRE(b3_rank == 2);
  REQUIRE(b3_file == 1);

  const auto [c3_rank, c3_file] = chess::to_rank_file<int>(chess::square::C3);
  REQUIRE(c3_rank == 2);
  REQUIRE(c3_file == 2);

  const auto [d3_rank, d3_file] = chess::to_rank_file<int>(chess::square::D3);
  REQUIRE(d3_rank == 2);
  REQUIRE(d3_file == 3);

  const auto [e3_rank, e3_file] = chess::to_rank_file<int>(chess::square::E3);
  REQUIRE(e3_rank == 2);
  REQUIRE(e3_file == 4);

  const auto [f3_rank, f3_file] = chess::to_rank_file<int>(chess::square::F3);
  REQUIRE(f3_rank == 2);
  REQUIRE(f3_file == 5);

  const auto [g3_rank, g3_file] = chess::to_rank_file<int>(chess::square::G3);
  REQUIRE(g3_rank == 2);
  REQUIRE(g3_file == 6);

  const auto [h3_rank, h3_file] = chess::to_rank_file<int>(chess::square::H3);
  REQUIRE(h3_rank == 2);
  REQUIRE(h3_file == 7);

  const auto [a4_rank, a4_file] = chess::to_rank_file<int>(chess::square::A4);
  REQUIRE(a4_rank == 3);
  REQUIRE(a4_file == 0);

  const auto [b4_rank, b4_file] = chess::to_rank_file<int>(chess::square::B4);
  REQUIRE(b4_rank == 3);
  REQUIRE(b4_file == 1);

  const auto [c4_rank, c4_file] = chess::to_rank_file<int>(chess::square::C4);
  REQUIRE(c4_rank == 3);
  REQUIRE(c4_file == 2);

  const auto [d4_rank, d4_file] = chess::to_rank_file<int>(chess::square::D4);
  REQUIRE(d4_rank == 3);
  REQUIRE(d4_file == 3);

  const auto [e4_rank, e4_file] = chess::to_rank_file<int>(chess::square::E4);
  REQUIRE(e4_rank == 3);
  REQUIRE(e4_file == 4);

  const auto [f4_rank, f4_file] = chess::to_rank_file<int>(chess::square::F4);
  REQUIRE(f4_rank == 3);
  REQUIRE(f4_file == 5);

  const auto [g4_rank, g4_file] = chess::to_rank_file<int>(chess::square::G4);
  REQUIRE(g4_rank == 3);
  REQUIRE(g4_file == 6);

  const auto [h4_rank, h4_file] = chess::to_rank_file<int>(chess::square::H4);
  REQUIRE(h4_rank == 3);
  REQUIRE(h4_file == 7);

  const auto [a5_rank, a5_file] = chess::to_rank_file<int>(chess::square::A5);
  REQUIRE(a5_rank == 4);
  REQUIRE(a5_file == 0);

  const auto [b5_rank, b5_file] = chess::to_rank_file<int>(chess::square::B5);
  REQUIRE(b5_rank == 4);
  REQUIRE(b5_file == 1);

  const auto [c5_rank, c5_file] = chess::to_rank_file<int>(chess::square::C5);
  REQUIRE(c5_rank == 4);
  REQUIRE(c5_file == 2);

  const auto [d5_rank, d5_file] = chess::to_rank_file<int>(chess::square::D5);
  REQUIRE(d5_rank == 4);
  REQUIRE(d5_file == 3);

  const auto [e5_rank, e5_file] = chess::to_rank_file<int>(chess::square::E5);
  REQUIRE(e5_rank == 4);
  REQUIRE(e5_file == 4);

  const auto [f5_rank, f5_file] = chess::to_rank_file<int>(chess::square::F5);
  REQUIRE(f5_rank == 4);
  REQUIRE(f5_file == 5);

  const auto [g5_rank, g5_file] = chess::to_rank_file<int>(chess::square::G5);
  REQUIRE(g5_rank == 4);
  REQUIRE(g5_file == 6);

  const auto [h5_rank, h5_file] = chess::to_rank_file<int>(chess::square::H5);
  REQUIRE(h5_rank == 4);
  REQUIRE(h5_file == 7);

  const auto [a6_rank, a6_file] = chess::to_rank_file<int>(chess::square::A6);
  REQUIRE(a6_rank == 5);
  REQUIRE(a6_file == 0);

  const auto [b6_rank, b6_file] = chess::to_rank_file<int>(chess::square::B6);
  REQUIRE(b6_rank == 5);
  REQUIRE(b6_file == 1);

  const auto [c6_rank, c6_file] = chess::to_rank_file<int>(chess::square::C6);
  REQUIRE(c6_rank == 5);
  REQUIRE(c6_file == 2);

  const auto [d6_rank, d6_file] = chess::to_rank_file<int>(chess::square::D6);
  REQUIRE(d6_rank == 5);
  REQUIRE(d6_file == 3);

  const auto [e6_rank, e6_file] = chess::to_rank_file<int>(chess::square::E6);
  REQUIRE(e6_rank == 5);
  REQUIRE(e6_file == 4);

  const auto [f6_rank, f6_file] = chess::to_rank_file<int>(chess::square::F6);
  REQUIRE(f6_rank == 5);
  REQUIRE(f6_file == 5);

  const auto [g6_rank, g6_file] = chess::to_rank_file<int>(chess::square::G6);
  REQUIRE(g6_rank == 5);
  REQUIRE(g6_file == 6);

  const auto [h6_rank, h6_file] = chess::to_rank_file<int>(chess::square::H6);
  REQUIRE(h6_rank == 5);
  REQUIRE(h6_file == 7);

  const auto [a7_rank, a7_file] = chess::to_rank_file<int>(chess::square::A7);
  REQUIRE(a7_rank == 6);
  REQUIRE(a7_file == 0);

  const auto [b7_rank, b7_file] = chess::to_rank_file<int>(chess::square::B7);
  REQUIRE(b7_rank == 6);
  REQUIRE(b7_file == 1);

  const auto [c7_rank, c7_file] = chess::to_rank_file<int>(chess::square::C7);
  REQUIRE(c7_rank == 6);
  REQUIRE(c7_file == 2);

  const auto [d7_rank, d7_file] = chess::to_rank_file<int>(chess::square::D7);
  REQUIRE(d7_rank == 6);
  REQUIRE(d7_file == 3);

  const auto [e7_rank, e7_file] = chess::to_rank_file<int>(chess::square::E7);
  REQUIRE(e7_rank == 6);
  REQUIRE(e7_file == 4);

  const auto [f7_rank, f7_file] = chess::to_rank_file<int>(chess::square::F7);
  REQUIRE(f7_rank == 6);
  REQUIRE(f7_file == 5);

  const auto [g7_rank, g7_file] = chess::to_rank_file<int>(chess::square::G7);
  REQUIRE(g7_rank == 6);
  REQUIRE(g7_file == 6);

  const auto [h7_rank, h7_file] = chess::to_rank_file<int>(chess::square::H7);
  REQUIRE(h7_rank == 6);
  REQUIRE(h7_file == 7);

  const auto [a8_rank, a8_file] = chess::to_rank_file<int>(chess::square::A8);
  REQUIRE(a8_rank == 7);
  REQUIRE(a8_file == 0);

  const auto [b8_rank, b8_file] = chess::to_rank_file<int>(chess::square::B8);
  REQUIRE(b8_rank == 7);
  REQUIRE(b8_file == 1);

  const auto [c8_rank, c8_file] = chess::to_rank_file<int>(chess::square::C8);
  REQUIRE(c8_rank == 7);
  REQUIRE(c8_file == 2);

  const auto [d8_rank, d8_file] = chess::to_rank_file<int>(chess::square::D8);
  REQUIRE(d8_rank == 7);
  REQUIRE(d8_file == 3);

  const auto [e8_rank, e8_file] = chess::to_rank_file<int>(chess::square::E8);
  REQUIRE(e8_rank == 7);
  REQUIRE(e8_file == 4);

  const auto [f8_rank, f8_file] = chess::to_rank_file<int>(chess::square::F8);
  REQUIRE(f8_rank == 7);
  REQUIRE(f8_file == 5);

  const auto [g8_rank, g8_file] = chess::to_rank_file<int>(chess::square::G8);
  REQUIRE(g8_rank == 7);
  REQUIRE(g8_file == 6);

  const auto [h8_rank, h8_file] = chess::to_rank_file<int>(chess::square::H8);
  REQUIRE(h8_rank == 7);
  REQUIRE(h8_file == 7);
}

TEST_CASE("squares convert to string using to_string", "square")
{
  using chess::to_string;

  const auto a1 = chess::square::A1;
  const auto a2 = chess::square::A2;
  const auto a3 = chess::square::A3;
  const auto a4 = chess::square::A4;
  const auto a5 = chess::square::A5;
  const auto a6 = chess::square::A6;
  const auto a7 = chess::square::A7;
  const auto a8 = chess::square::A8;

  const auto b1 = chess::square::B1;
  const auto b2 = chess::square::B2;
  const auto b3 = chess::square::B3;
  const auto b4 = chess::square::B4;
  const auto b5 = chess::square::B5;
  const auto b6 = chess::square::B6;
  const auto b7 = chess::square::B7;
  const auto b8 = chess::square::B8;

  const auto c1 = chess::square::C1;
  const auto c2 = chess::square::C2;
  const auto c3 = chess::square::C3;
  const auto c4 = chess::square::C4;
  const auto c5 = chess::square::C5;
  const auto c6 = chess::square::C6;
  const auto c7 = chess::square::C7;
  const auto c8 = chess::square::C8;

  const auto d1 = chess::square::D1;
  const auto d2 = chess::square::D2;
  const auto d3 = chess::square::D3;
  const auto d4 = chess::square::D4;
  const auto d5 = chess::square::D5;
  const auto d6 = chess::square::D6;
  const auto d7 = chess::square::D7;
  const auto d8 = chess::square::D8;

  const auto e1 = chess::square::E1;
  const auto e2 = chess::square::E2;
  const auto e3 = chess::square::E3;
  const auto e4 = chess::square::E4;
  const auto e5 = chess::square::E5;
  const auto e6 = chess::square::E6;
  const auto e7 = chess::square::E7;
  const auto e8 = chess::square::E8;

  const auto f1 = chess::square::F1;
  const auto f2 = chess::square::F2;
  const auto f3 = chess::square::F3;
  const auto f4 = chess::square::F4;
  const auto f5 = chess::square::F5;
  const auto f6 = chess::square::F6;
  const auto f7 = chess::square::F7;
  const auto f8 = chess::square::F8;

  const auto g1 = chess::square::G1;
  const auto g2 = chess::square::G2;
  const auto g3 = chess::square::G3;
  const auto g4 = chess::square::G4;
  const auto g5 = chess::square::G5;
  const auto g6 = chess::square::G6;
  const auto g7 = chess::square::G7;
  const auto g8 = chess::square::G8;

  const auto h1 = chess::square::H1;
  const auto h2 = chess::square::H2;
  const auto h3 = chess::square::H3;
  const auto h4 = chess::square::H4;
  const auto h5 = chess::square::H5;
  const auto h6 = chess::square::H6;
  const auto h7 = chess::square::H7;
  const auto h8 = chess::square::H8;

  REQUIRE(to_string(a1) == "square::A1");
  REQUIRE(to_string(a2) == "square::A2");
  REQUIRE(to_string(a3) == "square::A3");
  REQUIRE(to_string(a4) == "square::A4");
  REQUIRE(to_string(a5) == "square::A5");
  REQUIRE(to_string(a6) == "square::A6");
  REQUIRE(to_string(a7) == "square::A7");
  REQUIRE(to_string(a8) == "square::A8");

  REQUIRE(to_string(b1) == "square::B1");
  REQUIRE(to_string(b2) == "square::B2");
  REQUIRE(to_string(b3) == "square::B3");
  REQUIRE(to_string(b4) == "square::B4");
  REQUIRE(to_string(b5) == "square::B5");
  REQUIRE(to_string(b6) == "square::B6");
  REQUIRE(to_string(b7) == "square::B7");
  REQUIRE(to_string(b8) == "square::B8");

  REQUIRE(to_string(c1) == "square::C1");
  REQUIRE(to_string(c2) == "square::C2");
  REQUIRE(to_string(c3) == "square::C3");
  REQUIRE(to_string(c4) == "square::C4");
  REQUIRE(to_string(c5) == "square::C5");
  REQUIRE(to_string(c6) == "square::C6");
  REQUIRE(to_string(c7) == "square::C7");
  REQUIRE(to_string(c8) == "square::C8");

  REQUIRE(to_string(d1) == "square::D1");
  REQUIRE(to_string(d2) == "square::D2");
  REQUIRE(to_string(d3) == "square::D3");
  REQUIRE(to_string(d4) == "square::D4");
  REQUIRE(to_string(d5) == "square::D5");
  REQUIRE(to_string(d6) == "square::D6");
  REQUIRE(to_string(d7) == "square::D7");
  REQUIRE(to_string(d8) == "square::D8");

  REQUIRE(to_string(e1) == "square::E1");
  REQUIRE(to_string(e2) == "square::E2");
  REQUIRE(to_string(e3) == "square::E3");
  REQUIRE(to_string(e4) == "square::E4");
  REQUIRE(to_string(e5) == "square::E5");
  REQUIRE(to_string(e6) == "square::E6");
  REQUIRE(to_string(e7) == "square::E7");
  REQUIRE(to_string(e8) == "square::E8");

  REQUIRE(to_string(f1) == "square::F1");
  REQUIRE(to_string(f2) == "square::F2");
  REQUIRE(to_string(f3) == "square::F3");
  REQUIRE(to_string(f4) == "square::F4");
  REQUIRE(to_string(f5) == "square::F5");
  REQUIRE(to_string(f6) == "square::F6");
  REQUIRE(to_string(f7) == "square::F7");
  REQUIRE(to_string(f8) == "square::F8");

  REQUIRE(to_string(g1) == "square::G1");
  REQUIRE(to_string(g2) == "square::G2");
  REQUIRE(to_string(g3) == "square::G3");
  REQUIRE(to_string(g4) == "square::G4");
  REQUIRE(to_string(g5) == "square::G5");
  REQUIRE(to_string(g6) == "square::G6");
  REQUIRE(to_string(g7) == "square::G7");
  REQUIRE(to_string(g8) == "square::G8");

  REQUIRE(to_string(h1) == "square::H1");
  REQUIRE(to_string(h2) == "square::H2");
  REQUIRE(to_string(h3) == "square::H3");
  REQUIRE(to_string(h4) == "square::H4");
  REQUIRE(to_string(h5) == "square::H5");
  REQUIRE(to_string(h6) == "square::H6");
  REQUIRE(to_string(h7) == "square::H7");
  REQUIRE(to_string(h8) == "square::H8");
}

TEST_CASE("squares convert to string using sstream", "square")
{
  using chess::to_string;

  const auto a1 = chess::square::A1;
  const auto a2 = chess::square::A2;
  const auto a3 = chess::square::A3;
  const auto a4 = chess::square::A4;
  const auto a5 = chess::square::A5;
  const auto a6 = chess::square::A6;
  const auto a7 = chess::square::A7;
  const auto a8 = chess::square::A8;

  const auto b1 = chess::square::B1;
  const auto b2 = chess::square::B2;
  const auto b3 = chess::square::B3;
  const auto b4 = chess::square::B4;
  const auto b5 = chess::square::B5;
  const auto b6 = chess::square::B6;
  const auto b7 = chess::square::B7;
  const auto b8 = chess::square::B8;

  const auto c1 = chess::square::C1;
  const auto c2 = chess::square::C2;
  const auto c3 = chess::square::C3;
  const auto c4 = chess::square::C4;
  const auto c5 = chess::square::C5;
  const auto c6 = chess::square::C6;
  const auto c7 = chess::square::C7;
  const auto c8 = chess::square::C8;

  const auto d1 = chess::square::D1;
  const auto d2 = chess::square::D2;
  const auto d3 = chess::square::D3;
  const auto d4 = chess::square::D4;
  const auto d5 = chess::square::D5;
  const auto d6 = chess::square::D6;
  const auto d7 = chess::square::D7;
  const auto d8 = chess::square::D8;

  const auto e1 = chess::square::E1;
  const auto e2 = chess::square::E2;
  const auto e3 = chess::square::E3;
  const auto e4 = chess::square::E4;
  const auto e5 = chess::square::E5;
  const auto e6 = chess::square::E6;
  const auto e7 = chess::square::E7;
  const auto e8 = chess::square::E8;

  const auto f1 = chess::square::F1;
  const auto f2 = chess::square::F2;
  const auto f3 = chess::square::F3;
  const auto f4 = chess::square::F4;
  const auto f5 = chess::square::F5;
  const auto f6 = chess::square::F6;
  const auto f7 = chess::square::F7;
  const auto f8 = chess::square::F8;

  const auto g1 = chess::square::G1;
  const auto g2 = chess::square::G2;
  const auto g3 = chess::square::G3;
  const auto g4 = chess::square::G4;
  const auto g5 = chess::square::G5;
  const auto g6 = chess::square::G6;
  const auto g7 = chess::square::G7;
  const auto g8 = chess::square::G8;

  const auto h1 = chess::square::H1;
  const auto h2 = chess::square::H2;
  const auto h3 = chess::square::H3;
  const auto h4 = chess::square::H4;
  const auto h5 = chess::square::H5;
  const auto h6 = chess::square::H6;
  const auto h7 = chess::square::H7;
  const auto h8 = chess::square::H8;

  std::ostringstream oss_a1;
  oss_a1 << a1;
  REQUIRE(oss_a1.str() == "square::A1");
  std::ostringstream oss_a2;
  oss_a2 << a2;
  REQUIRE(oss_a2.str() == "square::A2");
  std::ostringstream oss_a3;
  oss_a3 << a3;
  REQUIRE(oss_a3.str() == "square::A3");
  std::ostringstream oss_a4;
  oss_a4 << a4;
  REQUIRE(oss_a4.str() == "square::A4");
  std::ostringstream oss_a5;
  oss_a5 << a5;
  REQUIRE(oss_a5.str() == "square::A5");
  std::ostringstream oss_a6;
  oss_a6 << a6;
  REQUIRE(oss_a6.str() == "square::A6");
  std::ostringstream oss_a7;
  oss_a7 << a7;
  REQUIRE(oss_a7.str() == "square::A7");
  std::ostringstream oss_a8;
  oss_a8 << a8;
  REQUIRE(oss_a8.str() == "square::A8");

  std::ostringstream oss_b1;
  oss_b1 << b1;
  REQUIRE(oss_b1.str() == "square::B1");
  std::ostringstream oss_b2;
  oss_b2 << b2;
  REQUIRE(oss_b2.str() == "square::B2");
  std::ostringstream oss_b3;
  oss_b3 << b3;
  REQUIRE(oss_b3.str() == "square::B3");
  std::ostringstream oss_b4;
  oss_b4 << b4;
  REQUIRE(oss_b4.str() == "square::B4");
  std::ostringstream oss_b5;
  oss_b5 << b5;
  REQUIRE(oss_b5.str() == "square::B5");
  std::ostringstream oss_b6;
  oss_b6 << b6;
  REQUIRE(oss_b6.str() == "square::B6");
  std::ostringstream oss_b7;
  oss_b7 << b7;
  REQUIRE(oss_b7.str() == "square::B7");
  std::ostringstream oss_b8;
  oss_b8 << b8;
  REQUIRE(oss_b8.str() == "square::B8");

  std::ostringstream oss_c1;
  oss_c1 << c1;
  REQUIRE(oss_c1.str() == "square::C1");
  std::ostringstream oss_c2;
  oss_c2 << c2;
  REQUIRE(oss_c2.str() == "square::C2");
  std::ostringstream oss_c3;
  oss_c3 << c3;
  REQUIRE(oss_c3.str() == "square::C3");
  std::ostringstream oss_c4;
  oss_c4 << c4;
  REQUIRE(oss_c4.str() == "square::C4");
  std::ostringstream oss_c5;
  oss_c5 << c5;
  REQUIRE(oss_c5.str() == "square::C5");
  std::ostringstream oss_c6;
  oss_c6 << c6;
  REQUIRE(oss_c6.str() == "square::C6");
  std::ostringstream oss_c7;
  oss_c7 << c7;
  REQUIRE(oss_c7.str() == "square::C7");
  std::ostringstream oss_c8;
  oss_c8 << c8;
  REQUIRE(oss_c8.str() == "square::C8");

  std::ostringstream oss_d1;
  oss_d1 << d1;
  REQUIRE(oss_d1.str() == "square::D1");
  std::ostringstream oss_d2;
  oss_d2 << d2;
  REQUIRE(oss_d2.str() == "square::D2");
  std::ostringstream oss_d3;
  oss_d3 << d3;
  REQUIRE(oss_d3.str() == "square::D3");
  std::ostringstream oss_d4;
  oss_d4 << d4;
  REQUIRE(oss_d4.str() == "square::D4");
  std::ostringstream oss_d5;
  oss_d5 << d5;
  REQUIRE(oss_d5.str() == "square::D5");
  std::ostringstream oss_d6;
  oss_d6 << d6;
  REQUIRE(oss_d6.str() == "square::D6");
  std::ostringstream oss_d7;
  oss_d7 << d7;
  REQUIRE(oss_d7.str() == "square::D7");
  std::ostringstream oss_d8;
  oss_d8 << d8;
  REQUIRE(oss_d8.str() == "square::D8");

  std::ostringstream oss_e1;
  oss_e1 << e1;
  REQUIRE(oss_e1.str() == "square::E1");
  std::ostringstream oss_e2;
  oss_e2 << e2;
  REQUIRE(oss_e2.str() == "square::E2");
  std::ostringstream oss_e3;
  oss_e3 << e3;
  REQUIRE(oss_e3.str() == "square::E3");
  std::ostringstream oss_e4;
  oss_e4 << e4;
  REQUIRE(oss_e4.str() == "square::E4");
  std::ostringstream oss_e5;
  oss_e5 << e5;
  REQUIRE(oss_e5.str() == "square::E5");
  std::ostringstream oss_e6;
  oss_e6 << e6;
  REQUIRE(oss_e6.str() == "square::E6");
  std::ostringstream oss_e7;
  oss_e7 << e7;
  REQUIRE(oss_e7.str() == "square::E7");
  std::ostringstream oss_e8;
  oss_e8 << e8;
  REQUIRE(oss_e8.str() == "square::E8");

  std::ostringstream oss_f1;
  oss_f1 << f1;
  REQUIRE(oss_f1.str() == "square::F1");
  std::ostringstream oss_f2;
  oss_f2 << f2;
  REQUIRE(oss_f2.str() == "square::F2");
  std::ostringstream oss_f3;
  oss_f3 << f3;
  REQUIRE(oss_f3.str() == "square::F3");
  std::ostringstream oss_f4;
  oss_f4 << f4;
  REQUIRE(oss_f4.str() == "square::F4");
  std::ostringstream oss_f5;
  oss_f5 << f5;
  REQUIRE(oss_f5.str() == "square::F5");
  std::ostringstream oss_f6;
  oss_f6 << f6;
  REQUIRE(oss_f6.str() == "square::F6");
  std::ostringstream oss_f7;
  oss_f7 << f7;
  REQUIRE(oss_f7.str() == "square::F7");
  std::ostringstream oss_f8;
  oss_f8 << f8;
  REQUIRE(oss_f8.str() == "square::F8");

  std::ostringstream oss_g1;
  oss_g1 << g1;
  REQUIRE(oss_g1.str() == "square::G1");
  std::ostringstream oss_g2;
  oss_g2 << g2;
  REQUIRE(oss_g2.str() == "square::G2");
  std::ostringstream oss_g3;
  oss_g3 << g3;
  REQUIRE(oss_g3.str() == "square::G3");
  std::ostringstream oss_g4;
  oss_g4 << g4;
  REQUIRE(oss_g4.str() == "square::G4");
  std::ostringstream oss_g5;
  oss_g5 << g5;
  REQUIRE(oss_g5.str() == "square::G5");
  std::ostringstream oss_g6;
  oss_g6 << g6;
  REQUIRE(oss_g6.str() == "square::G6");
  std::ostringstream oss_g7;
  oss_g7 << g7;
  REQUIRE(oss_g7.str() == "square::G7");
  std::ostringstream oss_g8;
  oss_g8 << g8;
  REQUIRE(oss_g8.str() == "square::G8");

  std::ostringstream oss_h1;
  oss_h1 << h1;
  REQUIRE(oss_h1.str() == "square::H1");
  std::ostringstream oss_h2;
  oss_h2 << h2;
  REQUIRE(oss_h2.str() == "square::H2");
  std::ostringstream oss_h3;
  oss_h3 << h3;
  REQUIRE(oss_h3.str() == "square::H3");
  std::ostringstream oss_h4;
  oss_h4 << h4;
  REQUIRE(oss_h4.str() == "square::H4");
  std::ostringstream oss_h5;
  oss_h5 << h5;
  REQUIRE(oss_h5.str() == "square::H5");
  std::ostringstream oss_h6;
  oss_h6 << h6;
  REQUIRE(oss_h6.str() == "square::H6");
  std::ostringstream oss_h7;
  oss_h7 << h7;
  REQUIRE(oss_h7.str() == "square::H7");
  std::ostringstream oss_h8;
  oss_h8 << h8;
  REQUIRE(oss_h8.str() == "square::H8");
}
