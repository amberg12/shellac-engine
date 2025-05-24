#include "util/add.hpp"

#include <iostream>

using namespace engine;

auto main() -> int
{
  auto answer = util::simple_add(5, 3);
  std::cout << "The answer is " << answer << '\n';
}
