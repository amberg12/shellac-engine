#include <cstdint>
#include <type_traits>

namespace chess {

template <typename T, typename = std::enable_if_t<std::is_integral_v<T>>>
struct safe_larger_integral
{
  using type =
    std::conditional_t<std::is_signed_v<T>, std::int64_t, std::uint64_t>;
};

template <typename T, typename = std::enable_if_t<std::is_integral_v<T>>>
using safe_larger_integral_t = typename safe_larger_integral<T>::type;

template <typename T, typename = std::enable_if_t<std::is_integral_v<T>>>
auto to_safe_larger_integral(T e) -> safe_larger_integral_t<T>
{
  return static_cast<safe_larger_integral_t<T>>(e);
}

}  // namespace chess
