#pragma once

#include <algorithm>
#include <array>
#include <cstddef>
#include <sstream>
#include <stdexcept>

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

  [[nodiscard]] auto container() const -> const
    typename chess::matrix<T, X_SIZE, Y_SIZE>::container_type&;
  [[nodiscard]] auto container() ->
    typename chess::matrix<T, X_SIZE, Y_SIZE>::container_type&;

  [[nodiscard]] auto begin() -> typename container_type::iterator;
  [[nodiscard]] auto begin() const -> typename container_type::iterator;
  [[nodiscard]] auto cbegin() const -> typename container_type::iterator;

  [[nodiscard]] auto end() -> typename container_type::iterator;
  [[nodiscard]] auto end() const -> typename container_type::iterator;
  [[nodiscard]] auto cend() const -> typename container_type::iterator;

  [[nodiscard]] auto row_begin(std::size_t y) ->
    typename container_type::iterator;
  [[nodiscard]] auto row_begin(std::size_t y) const ->
    typename container_type::const_iterator;
  [[nodiscard]] auto crow_begin(std::size_t y) const ->
    typename container_type::const_iterator;

  [[nodiscard]] auto row_end(std::size_t y) ->
    typename container_type::iterator;
  [[nodiscard]] auto row_end(std::size_t y) const ->
    typename container_type::const_iterator;
  [[nodiscard]] auto crow_end(std::size_t y) const ->
    typename container_type::const_iterator;

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
[[nodiscard]] auto chess::matrix<T, X_SIZE, Y_SIZE>::container() const -> const
  typename chess::matrix<T, X_SIZE, Y_SIZE>::container_type&
{
  return m_container;
}

template <typename T, std::size_t X_SIZE, std::size_t Y_SIZE>
[[nodiscard]] auto chess::matrix<T, X_SIZE, Y_SIZE>::container() ->
  typename chess::matrix<T, X_SIZE, Y_SIZE>::container_type&
{
  return m_container;
}

template <typename T, std::size_t X_SIZE, std::size_t Y_SIZE>
[[nodiscard]] auto chess::matrix<T, X_SIZE, Y_SIZE>::begin() ->
  typename chess::matrix<T, X_SIZE, Y_SIZE>::container_type::iterator
{
  return std::begin(m_container);
}

template <typename T, std::size_t X_SIZE, std::size_t Y_SIZE>
[[nodiscard]] auto chess::matrix<T, X_SIZE, Y_SIZE>::begin() const ->
  typename chess::matrix<T, X_SIZE, Y_SIZE>::container_type::iterator
{
  return std::begin(m_container);
}

template <typename T, std::size_t X_SIZE, std::size_t Y_SIZE>
[[nodiscard]] auto chess::matrix<T, X_SIZE, Y_SIZE>::cbegin() const ->
  typename chess::matrix<T, X_SIZE, Y_SIZE>::container_type::iterator
{
  return std::cbegin(m_container);
}

template <typename T, std::size_t X_SIZE, std::size_t Y_SIZE>
[[nodiscard]] auto chess::matrix<T, X_SIZE, Y_SIZE>::end() ->
  typename chess::matrix<T, X_SIZE, Y_SIZE>::container_type::iterator
{
  return std::end(m_container);
}

template <typename T, std::size_t X_SIZE, std::size_t Y_SIZE>
[[nodiscard]] auto chess::matrix<T, X_SIZE, Y_SIZE>::end() const ->
  typename chess::matrix<T, X_SIZE, Y_SIZE>::container_type::iterator
{
  return std::end(m_container);
}

template <typename T, std::size_t X_SIZE, std::size_t Y_SIZE>
[[nodiscard]] auto chess::matrix<T, X_SIZE, Y_SIZE>::cend() const ->
  typename chess::matrix<T, X_SIZE, Y_SIZE>::container_type::iterator
{
  return std::cend(m_container);
}

template <typename T, std::size_t X_SIZE, std::size_t Y_SIZE>
[[nodiscard]] auto chess::matrix<T, X_SIZE, Y_SIZE>::row_begin(std::size_t y) ->
  typename chess::matrix<T, X_SIZE, Y_SIZE>::container_type::iterator
{
  return m_container.begin() + (y * X_SIZE);
}

template <typename T, std::size_t X_SIZE, std::size_t Y_SIZE>
[[nodiscard]] auto chess::matrix<T, X_SIZE, Y_SIZE>::row_begin(std::size_t y
) const ->
  typename chess::matrix<T, X_SIZE, Y_SIZE>::container_type::const_iterator
{
  return m_container.begin() + (y * X_SIZE);
}

template <typename T, std::size_t X_SIZE, std::size_t Y_SIZE>
[[nodiscard]] auto chess::matrix<T, X_SIZE, Y_SIZE>::crow_begin(std::size_t y
) const ->
  typename chess::matrix<T, X_SIZE, Y_SIZE>::container_type::const_iterator
{
  return m_container.begin() + (y * X_SIZE);
}

template <typename T, std::size_t X_SIZE, std::size_t Y_SIZE>
[[nodiscard]] auto chess::matrix<T, X_SIZE, Y_SIZE>::row_end(std::size_t y) ->
  typename chess::matrix<T, X_SIZE, Y_SIZE>::container_type::iterator
{
  return m_container.begin() + ((y + 1) * X_SIZE);
}

template <typename T, std::size_t X_SIZE, std::size_t Y_SIZE>
[[nodiscard]] auto chess::matrix<T, X_SIZE, Y_SIZE>::row_end(std::size_t y
) const ->
  typename chess::matrix<T, X_SIZE, Y_SIZE>::container_type::const_iterator
{
  return m_container.begin() + ((y + 1) * X_SIZE);
}

template <typename T, std::size_t X_SIZE, std::size_t Y_SIZE>
[[nodiscard]] auto chess::matrix<T, X_SIZE, Y_SIZE>::crow_end(std::size_t y
) const ->
  typename chess::matrix<T, X_SIZE, Y_SIZE>::container_type::const_iterator
{
  return m_container.begin() + ((y + 1) * X_SIZE);
}
