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
    this->success = value;
    this->failure = error;
  }

  T value() const { return this->success; }
  E error() const { return this->failure; }

  template <typename F>
  auto and_then(F&& f) const {
    if (this->success.has_value) {
      std::invoke(f, this->success);
    } else {
      std::invoke(f, this->success);
    }
  };

 private:
  T success;
  E failure;
};

template <IsEnumObject T, IsEnumObject E>
constexpr auto make_outcome(T&& value, E&& error) {
  return Outcome<T, E>(value, error);
}

}  // namespace Outcome

#endif
