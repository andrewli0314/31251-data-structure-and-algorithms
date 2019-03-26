#ifndef ADT_LIST_H
#define ADT_LIST_H
class List {
 public:
  virtual bool contains(int val) const = 0;
  virtual void push_front(int val) = 0;
  virtual void push_back(int val) = 0;
  virtual int& at(int index) = 0;
  virtual void erase(int index) = 0;
  virtual bool empty() const = 0;
  virtual int size() const = 0;
  virtual void print() const = 0;
};

#endif