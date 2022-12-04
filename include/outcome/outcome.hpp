#ifndef OUTCOME_HEADER
#define OUTCOME_HEADER

#include <cstdarg>
#include <functional>
#include <optional>
#include <type_traits>

namespace Outcome {

template <typename T>
concept IsEnumObject = (std::is_enum_v<T> || std::is_object_v<T>);

template <IsEnumObject T, IsEnumObject E>
class Outcome {
 public:
  explicit Outcome(T value, E error) {
    this->success = std::make_optional(value);
    this->failure = std::make_optional(error);
  }

  T value() const { return this->success.value(); }
  E error() const { return this->failure.value(); }

  void and_then(std::function<void()> f) const {
    if (this->success.has_value()) {
      f(this->success);
    } else {
      f(this->failure);
    }
  };

 private:
  std::optional<T> success;
  std::optional<E> failure;
};

template <IsEnumObject T, IsEnumObject E>
constexpr auto make_outcome(T&& value, E&& error) {
  return Outcome<T, E>(value, error);
}

}  // namespace Outcome

#endif
