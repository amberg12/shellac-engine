#include <print>

#include "util/add.hpp"

using namespace engine;

auto main() -> int
{
  auto answer = util::add(5, 3);
  std::println("The answer is {}!", answer);
}
