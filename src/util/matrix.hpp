#pragma once

#include "util/type_string.hpp"

#include <algorithm>
#include <array>
#include <cstddef>
#include <iostream>
#include <sstream>
#include <stdexcept>
#include <string>

namespace chess {

template <typename T, std::size_t X_SIZE, std::size_t Y_SIZE> class matrix
{
public:
  static constexpr std::size_t SIZE = X_SIZE * Y_SIZE;

  using value_type = T;
  using container_type = std::array<T, SIZE>;
  using iterator = typename container_type::iterator;
  using const_iterator = typename container_type::const_iterator;

  explicit matrix(T val);

  [[nodiscard]] auto at(std::size_t x, std::size_t y) const
    -> const value_type&;
  [[nodiscard]] auto at(std::size_t x, std::size_t y) -> value_type&;

  [[nodiscard]] auto container() const -> const container_type&;
  [[nodiscard]] auto container() -> container_type&;

  [[nodiscard]] auto begin() -> iterator;
  [[nodiscard]] auto begin() const -> iterator;
  [[nodiscard]] auto cbegin() const -> iterator;

  [[nodiscard]] auto end() -> iterator;
  [[nodiscard]] auto end() const -> iterator;
  [[nodiscard]] auto cend() const -> iterator;

  [[nodiscard]] auto row_begin(std::size_t y) -> iterator;
  [[nodiscard]] auto row_begin(std::size_t y) const -> const_iterator;
  [[nodiscard]] auto crow_begin(std::size_t y) const -> const_iterator;

  [[nodiscard]] auto row_end(std::size_t y) -> iterator;
  [[nodiscard]] auto row_end(std::size_t y) const -> const_iterator;
  [[nodiscard]] auto crow_end(std::size_t y) const -> const_iterator;

private:
  std::array<T, SIZE> m_container{};
};

template <typename T> class matrix<T, 0, 0>
{
public:
  using value_type = T;
  using container_type = void;
  static constexpr std::size_t SIZE = 0;
};

template <typename T, std::size_t X_SIZE, std::size_t Y_SIZE>
[[nodiscard]] auto to_string(const chess::matrix<T, X_SIZE, Y_SIZE>& m)
  -> std::string
{
  std::ostringstream oss;
  oss << "matrix<" << chess::type_string_v<T> << ", " << X_SIZE << ", "
      << Y_SIZE << ">::{";

  const auto add_to_oss = [&](const T& e) { oss << e << ", "; };

  for (auto y = std::size_t(0); y < Y_SIZE - 1; ++y) {
    oss << "{";
    std::for_each(m.crow_begin(y), std::prev(m.crow_end(y)), add_to_oss);
    oss << *std::prev(m.crow_end(y)) << "}, ";
  }

  constexpr auto final_row = Y_SIZE - 1;

  oss << "{";
  std::for_each(
    m.crow_begin(final_row), std::prev(m.crow_end(final_row)), add_to_oss
  );
  oss << *std::prev(m.crow_end(final_row)) << "}";
  oss << "}";

  return oss.str();
}

template <typename T>
[[nodiscard]] auto to_string(const chess::matrix<T, 0, 0>& m) -> std::string
{
  (void)m;
  std::ostringstream oss;
  oss << "matrix<" << chess::type_string_v<T> << ", 0, 0>::{}";
  return oss.str();
}

template <typename T, std::size_t X_SIZE, std::size_t Y_SIZE>
auto operator<<(std::ostream& os, chess::matrix<T, X_SIZE, Y_SIZE>& m)
  -> std::ostream&
{
  os << chess::to_string(m);
  return os;
}

}  // namespace chess

template <typename T, std::size_t X_SIZE, std::size_t Y_SIZE>
chess::matrix<T, X_SIZE, Y_SIZE>::matrix(T val)
{
  std::fill(std::begin(m_container), std::end(m_container), val);
}

template <typename T, std::size_t X_SIZE, std::size_t Y_SIZE>
[[nodiscard]] auto
chess::matrix<T, X_SIZE, Y_SIZE>::at(std::size_t x, std::size_t y) const
  -> const T&
{
  if (x >= X_SIZE || y >= Y_SIZE) {
    std::ostringstream oss;
    oss << "(" << x << ", " << y << ") not in range (" << X_SIZE << ", "
        << Y_SIZE << ")";
    throw std::out_of_range(oss.str());
  }
  auto idx = x + (X_SIZE * y);
  return m_container.at(idx);
}

template <typename T, std::size_t X_SIZE, std::size_t Y_SIZE>
[[nodiscard]] auto
chess::matrix<T, X_SIZE, Y_SIZE>::at(std::size_t x, std::size_t y) -> T&
{
  if (x >= X_SIZE || y >= Y_SIZE) {
    std::ostringstream oss;
    oss << "(" << x << ", " << y << ") not in range (" << X_SIZE << ", "
        << Y_SIZE << ")";
    throw std::out_of_range(oss.str());
  }

  auto idx = x + (X_SIZE * y);
  return m_container.at(idx);
}

template <typename T, std::size_t X_SIZE, std::size_t Y_SIZE>
[[nodiscard]] auto chess::matrix<T, X_SIZE, Y_SIZE>::container() const
  -> const container_type&
{
  return m_container;
}

template <typename T, std::size_t X_SIZE, std::size_t Y_SIZE>
[[nodiscard]] auto chess::matrix<T, X_SIZE, Y_SIZE>::container()
  -> container_type&
{
  return m_container;
}

template <typename T, std::size_t X_SIZE, std::size_t Y_SIZE>
[[nodiscard]] auto chess::matrix<T, X_SIZE, Y_SIZE>::begin() -> iterator
{
  return std::begin(m_container);
}

template <typename T, std::size_t X_SIZE, std::size_t Y_SIZE>
[[nodiscard]] auto chess::matrix<T, X_SIZE, Y_SIZE>::begin() const -> iterator
{
  return std::begin(m_container);
}

template <typename T, std::size_t X_SIZE, std::size_t Y_SIZE>
[[nodiscard]] auto chess::matrix<T, X_SIZE, Y_SIZE>::cbegin() const -> iterator
{
  return std::cbegin(m_container);
}

template <typename T, std::size_t X_SIZE, std::size_t Y_SIZE>
[[nodiscard]] auto chess::matrix<T, X_SIZE, Y_SIZE>::end() -> iterator
{
  return std::end(m_container);
}

template <typename T, std::size_t X_SIZE, std::size_t Y_SIZE>
[[nodiscard]] auto chess::matrix<T, X_SIZE, Y_SIZE>::end() const -> iterator
{
  return std::end(m_container);
}

template <typename T, std::size_t X_SIZE, std::size_t Y_SIZE>
[[nodiscard]] auto chess::matrix<T, X_SIZE, Y_SIZE>::cend() const -> iterator
{
  return std::cend(m_container);
}

template <typename T, std::size_t X_SIZE, std::size_t Y_SIZE>
[[nodiscard]] auto chess::matrix<T, X_SIZE, Y_SIZE>::row_begin(std::size_t y)
  -> iterator
{
  return m_container.begin() + (y * X_SIZE);
}

template <typename T, std::size_t X_SIZE, std::size_t Y_SIZE>
[[nodiscard]] auto chess::matrix<T, X_SIZE, Y_SIZE>::row_begin(std::size_t y
) const -> const_iterator
{
  return m_container.begin() + (y * X_SIZE);
}

template <typename T, std::size_t X_SIZE, std::size_t Y_SIZE>
[[nodiscard]] auto chess::matrix<T, X_SIZE, Y_SIZE>::crow_begin(std::size_t y
) const -> const_iterator
{
  return m_container.begin() + (y * X_SIZE);
}

template <typename T, std::size_t X_SIZE, std::size_t Y_SIZE>
[[nodiscard]] auto chess::matrix<T, X_SIZE, Y_SIZE>::row_end(std::size_t y)
  -> iterator
{
  return m_container.begin() + ((y + 1) * X_SIZE);
}

template <typename T, std::size_t X_SIZE, std::size_t Y_SIZE>
[[nodiscard]] auto chess::matrix<T, X_SIZE, Y_SIZE>::row_end(std::size_t y
) const -> const_iterator
{
  return m_container.begin() + ((y + 1) * X_SIZE);
}

template <typename T, std::size_t X_SIZE, std::size_t Y_SIZE>
[[nodiscard]] auto chess::matrix<T, X_SIZE, Y_SIZE>::crow_end(std::size_t y
) const -> const_iterator
{
  return m_container.begin() + ((y + 1) * X_SIZE);
}
