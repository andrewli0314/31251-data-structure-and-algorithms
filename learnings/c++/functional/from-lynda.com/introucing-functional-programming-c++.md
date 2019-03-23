# Why Functional Programming

- Pure functions are simple in design making them understandable.
- Without classes and by emphasizing pure functions our code is easier to debug and test
- Since we lack mutable state, multi-threading is achieveable.

**Functional Programming Style**:

- We try to avoid data mutations so all of our variables tend to be _immutable_ (Immutable is just a fancy word for a constant).
- If we can not change variables, loops are difficult, so _recursion_ is preffered.
- Functions are kept clean (output depends only on their input) and straightforward. They also avoid making changes to program state which makes them side effect free.
- Expression preferred over statements. Expression returns a value and can appear on the right hand side of an equal sign. Statement return nothing and exist mainly to cause side effects.
- Curing and partial application manage how we send our arguments to functions.
- OOP emphasis on Polymorphism and Classes and FP emphasis on Immutability and Pure functions.

**Unit Testing FP**

- Pure function are easy to test, (no classes to mock or instantiate makes testing simplerand using pure function, output depends on input)

```cpp
// Catch2 unittesting framework (catch.hpp)
// main.cpp
#define CATCH_CONFIG_MAIN
#include "catch.hpp"

// a pure function without side effects
int fibonacci(int n){
    if(n <= 1){
        return (n);
    }
    return (fibonacci(n - 1) + fibonacci(n - 2));
}

TEST_CASE("Fibonancci series", "[fibonancci]"){
    REQUIRE(fibonancci(0) == 0);
    REQUIRE(fibonancci(1) == 1);
    REQUIRE(fibonancci(2) == 2);
    REQUIRE(fibonancci(12) == 144);
}
```

# FP in C++17

```bash
$ /std:c++17 # for MSVC
$ -std=c++17 # for GCC
$  -std=c++17 # for Clang
# For Cmake
set(CMAKE_CXX_STANDARD 17) # top of cmakelist.text file
```

```cpp
#include <iostream>

namespace A::B::C {   // C++ 17 nested namespaces (not in C++14)
    int i;
}

int main() {
    A::B::C::i = 42;
    std::cout<<"Nested namespaces are available: "<< A::B::C::i << std:endl;
    return 0;
}
```

**Map, Filter and Reduce** :

- Map, Filter and Reduce?? We have `std::transform` for `map()`, `std::copy_if` for `filter()` and `std::accumulate` for `reduce()`.

```cpp
#include <algorithm>
#include <iostream>
#include <numeric>
#include <vector>

using namespace std;

int main() {
  auto render = [](auto collection) {
    for (const auto &val : collection) {
      cout << val << endl;
    }
  };

  vector<int> inCollection{1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
  vector<int> outCollection;

  transform(inCollection.begin(), inCollection.end(),
            back_inserter(outCollection),  // since out out collection is empty
            [](const int &value) { return value * 3; });

  cout << "Transform " << endl;
  render(outCollection);

  return 0;
}
```
