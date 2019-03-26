#ifndef ADT_VECTOR_H_
#define ADT_VECTOR_H_

#include "adt_list.h"
class Vector : public List {
 protected:
  int length;
  int* data;
  int capacity;

 public:
  Vector();
  ~Vector();

  virtual bool contains(int val) const;
  virtual void push_front(int val) = 0;
  virtual void push_back(int val) = 0;
  virtual int& at(int index) = 0;
  virtual void erase(int index) = 0;
  virtual bool empty() const = 0;
  virtual int size() const = 0;
  virtual void print() const = 0;

 private:
  void resize();
};

#endif