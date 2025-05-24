#include "util/add.hpp"

#include <catch2/catch_test_macros.hpp>

using namespace engine;

TEST_CASE(
  "simple add should add with regards to the laws of mathematics",
  "[add]"
)
{
  auto result = util::simple_add(5, 3);
  REQUIRE(result == 8);
}
