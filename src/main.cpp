#include <iostream>

#include "util/add.hpp"

using namespace engine;

auto main() -> int
{
  auto answer = util::simple_add(5, 3);
  std::cout << "The answer is " << answer << std::endl;
}
