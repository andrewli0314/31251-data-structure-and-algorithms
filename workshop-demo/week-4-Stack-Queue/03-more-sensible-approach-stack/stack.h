#include <vector>

template <typename T>
class stack {
 private:
  std::vector<T> data;
  // The internal storage goes here, so you
  // will need to create a vector.

 public:
  stack() {}
  ~stack() {}

  void push(T t) { data.push_back(t); }

  T pop() {
    T d = data.at(data.size() - 1);
    data.pop_back();
    return d;
  }
  T peek() {
    return data.at(data.size() - 1);
  }  // A new one, this returns the top
     // element of the stack without removing
     // it. (i.e. lets us peek at the top)
  bool empty() { return data.empty(); }
};