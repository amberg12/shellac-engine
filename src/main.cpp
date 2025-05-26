#include "util/matrix.hpp"

#include <iostream>

auto main() -> int
{
  auto m = chess::matrix<int, 5, 3>(0);
  std::cout << m << '\n';
}
