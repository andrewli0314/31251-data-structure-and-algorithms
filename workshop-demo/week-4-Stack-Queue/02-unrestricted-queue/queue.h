template <typename T>
class queue {
 private:
  // Add some internal data members here
  // What ones do you need?
  // An array like thing to store data...
  // How do we handle arrays where we don't know the size?
  // You'll also want to do something to keep track of where
  // in the queue you're up to (there's a couple of ways
  // to do this).

  T* data;
  int front;
  int size;
  int capacity;

 public:
  // constructors
  queue() {
    data = new T[5];
    capacity = 5;
    size = 0;
    front = 0;
  }

  queue(int capacity) {
    this->capacity = capacity;
    data = new T[capacity];
    size = 0;
    front = 0;
  }
  ~queue() { delete[] data; }

  void offer(T t) {
    if (size == capacity) {
      T* newArray = new T[capacity * 2];

      for (int i = 0; i < size; i++) {
        newArray[i] = data[front + i];
      }
      size++;
      newArray[size] = t;
      data = &newArray;
    } else {
      data[front + size] = t;
      size++;
    }
  }  // add something to the back of the queue

  T poll() {
    T polledElement = data[front];
    front++;
    return polledElement;

  }  // remove something from the front of the queue

  bool empty() { return size == 0; }  // is the queue empty?

  // Notes

  // (front + size)% capacity
};