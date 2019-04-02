// As this is a templated class, you should implement the
// class in the header.

//
template <typename T>
class stack {
 private:
  T data[10];
  // You may want to add other class variables here.
  int size;

 public:
  stack() { size = 0; }  // constructor
  ~stack() {}            // destructor

  void push(T t) {
    if (size < 10) {
      data[size] = t;
      size++;
    }

  }  // add an element to the top of the stack

  T pop() {
    if (size > 0) {
      T popedElement = data[size - 1];
      // T d = data[--size];
      size--;
      return popedElement;
    } else {
      return T();  // empty constructor of T type
    }

  }  // remove an element from the top of the stack

  bool empty() { return size == 0; }  // check if the stack is empty
};