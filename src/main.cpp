#include <iostream>
#include <outcome/outcome.hpp>
#include <string>

enum class ErrorCode { Error, NoError };

Outcome::Outcome<std::string, ErrorCode> check_age(int age) {
  if (age >= 18) {
    return Outcome::make_outcome<std::string, ErrorCode>("Fancy a pint?",
                                                         ErrorCode::NoError);
  } else {
    return Outcome::make_outcome<std::string, ErrorCode>(
        "Not old enough to drink", ErrorCode::Error);
  }
}

int main(void) {
  Outcome::Outcome<std::string, std::string> v("Success!",
                                               "Oppsie faily waily");

  std::printf("Value: %s\n", v.value().data());
  std::printf("Error: %s\n", v.error().data());

  v.and_then([v]() -> void { std::cout << v.value() << std::endl; });

  auto checked = check_age(21);
  auto checked2 = check_age(17);

  std::printf("%s\n", checked.value().data());
  std::printf("%s\n", checked2.value().data());

  return 0;
}
