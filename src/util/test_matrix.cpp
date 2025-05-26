#include "util/matrix.hpp"

#include <catch2/catch_test_macros.hpp>

using namespace chess;

TEST_CASE("Matrix initializes with given value", "[matrix]")
{
  matrix<int, 3, 2> m(42);
  for (std::size_t y = 0; y < 2; ++y) {
    for (std::size_t x = 0; x < 3; ++x) {
      REQUIRE(m.at(x, y) == 42);
    }
  }
}

TEST_CASE("Matrix at() throws out_of_range when out of bounds", "[matrix]")
{
  matrix<int, 2, 2> m(0);

  REQUIRE_THROWS_AS(m.at(2, 0), std::out_of_range);
  REQUIRE_THROWS_AS(m.at(0, 2), std::out_of_range);
  REQUIRE_THROWS_AS(m.at(2, 2), std::out_of_range);
}

TEST_CASE("Matrix at() returns correct reference for modification", "[matrix]")
{
  matrix<int, 2, 2> m(5);
  m.at(1, 1) = 99;

  REQUIRE(m.at(1, 1) == 99);
}

TEST_CASE("Matrix container() returns the underlying container", "[matrix]")
{
  matrix<int, 2, 2> m(7);
  const auto& container = m.container();
  REQUIRE(container.size() == 4);
  for (const auto& val : container) {
    REQUIRE(val == 7);
  }
}

TEST_CASE("Matrix iterators work as expected", "[matrix]")
{
  matrix<int, 2, 2> m(1);
  std::size_t count = 0;
  for (auto it = m.begin(); it != m.end(); ++it) {
    REQUIRE(*it == 1);
    ++count;
  }
  REQUIRE(count == 4);
}

TEST_CASE("Matrix row_begin and row_end give correct range", "[matrix]")
{
  matrix<int, 3, 2> m(0);
  m.at(0, 1) = 1;
  m.at(1, 1) = 2;
  m.at(2, 1) = 3;

  auto row_it = m.row_begin(1);
  REQUIRE(*(row_it + 0) == 1);
  REQUIRE(*(row_it + 1) == 2);
  REQUIRE(*(row_it + 2) == 3);

  std::vector<int> expected = {1, 2, 3};
  REQUIRE(std::vector<int>(m.row_begin(1), m.row_end(1)) == expected);
}

TEST_CASE("Matrix const row iterators are consistent", "[matrix]")
{
  const matrix<int, 2, 2> m(42);

  auto crb = m.crow_begin(1);
  auto cre = m.crow_end(1);
  REQUIRE(std::distance(crb, cre) == 2);
  for (auto it = crb; it != cre; ++it) {
    REQUIRE(*it == 42);
  }
}

TEST_CASE("Zero-sized matrix specialization", "[matrix][zero]")
{
  STATIC_REQUIRE(matrix<int, 0, 0>::SIZE == 0);
}

namespace {
// Helper function to extract content after ">::"
std::string extract_matrix_content(const std::string& str)
{
  auto pos = str.find(">::");
  if (pos == std::string::npos)
    return str;
  return str.substr(pos + 3);
}
}  // namespace

TEST_CASE("matrix to_string function", "[matrix][to_string]")
{
  SECTION("empty matrix")
  {
    chess::matrix<int, 0, 0> m;
    REQUIRE(extract_matrix_content(chess::to_string(m)) == "{}");
  }

  SECTION("1x1 matrix")
  {
    chess::matrix<int, 1, 1> m(42);
    REQUIRE(extract_matrix_content(chess::to_string(m)) == "{{42}}");
  }

  SECTION("2x2 matrix")
  {
    chess::matrix<int, 2, 2> m(0);
    m.at(0, 0) = 1;
    m.at(1, 0) = 2;
    m.at(0, 1) = 3;
    m.at(1, 1) = 4;
    REQUIRE(extract_matrix_content(chess::to_string(m)) == "{{1, 2}, {3, 4}}");
  }

  SECTION("3x2 matrix")
  {
    chess::matrix<int, 3, 2> m(0);
    m.at(0, 0) = 1;
    m.at(1, 0) = 2;
    m.at(2, 0) = 3;
    m.at(0, 1) = 4;
    m.at(1, 1) = 5;
    m.at(2, 1) = 6;
    REQUIRE(
      extract_matrix_content(chess::to_string(m)) == "{{1, 2, 3}, {4, 5, 6}}"
    );
  }
}

TEST_CASE("matrix operator<<", "[matrix][stream]")
{
  SECTION("stream output for 2x2 matrix")
  {
    chess::matrix<int, 2, 2> m(0);
    m.at(0, 0) = 1;
    m.at(1, 0) = 2;
    m.at(0, 1) = 3;
    m.at(1, 1) = 4;

    std::ostringstream oss;
    oss << m;
    REQUIRE(extract_matrix_content(oss.str()) == "{{1, 2}, {3, 4}}");
  }

  SECTION("stream output for 1x3 matrix")
  {
    chess::matrix<std::string, 1, 3> m("a");
    m.at(0, 1) = "b";
    m.at(0, 2) = "c";

    std::ostringstream oss;
    oss << m;
    REQUIRE(extract_matrix_content(oss.str()) == "{{a}, {b}, {c}}");
  }
}
