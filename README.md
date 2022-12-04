<div id="header">
    <p align="center">
      <b>Outcome 📖</b><br>
  	  <span font-size="16px">a C++ template type to return two possible values </span><br>
      <span font-size="12px">Made by <a href="http://epmor.app">Ethan</a> with love.</span><br><br>
      <span><a href="https://www.twitter.com/glassofethanol">Twitter</a> | <a href="https://github.com/sponsors/gweithio">Support</a></span><br><br>
    </p>
</div>

### About

A C++ template class to allow two possible return types, such as a success or error

### Features

```
- Nothing to mention yet
```

### Requirements

```
- CMake, for building, Ninja instead of makefiles ;)
- Conan, for deps
- A C++ compiler with c++20 support, I use clang
```

### Usage

```cpp
#include <cstdio>
#include <outcome/outcome.hpp>
#include <string>

enum class ErrorCode { Error, NoError };

Outcome::Outcome<std::string, ErrorCode> check_age(int age) {
  if (age >= 18) {
    return Outcome::make_outcome<std::string, ErrorCode>("fancy a pint?", ErrorCode::NoError);
  } else {
    return Outcome::make_outcome<std::string, ErrorCode>("Not old enough to drink", ErrorCode::Error);
  }
}

int main(void) {
  Outcome::Outcome<std::string, std::string> v("test", "error");

  printf("Value: %s\n", v.value().data());
  printf("Error: %s\n", v.error().data());

  auto checked = check_age(21);

  printf("%s\n", checked.value().data());

  return 0;
}

Value: Success!
Error: oppsie faily waily
Fancy a pint?
Not old enough for a drink
```


### Target Platforms (Currently)

```
- Linux
- MacOS
- Windows (Future target)
```

### Building

Will download the deps from Conan building the cmake structure and build the project

```bash
$ ./build.sh
```
