#include "adt_vector.h"
#include <iostream>
#include <stdexcept>

using namespace std;

#define INITIAL_CAPACITY 1

Vector::Vector() {
  this->length = 0;
  this->capacity = INITIAL_CAPACITY;
  this->data = new int[INITIAL_CAPACITY];
}

Vector::~Vector() {
  delete[] this->data;
  this->data = NULL;
}

bool Vector::empty() const { return (this->length == 0); }

int Vector::size() const { return (this->length); }

bool Vector::contains(int val) const {
  for (int i = 0; i < this->length; i++) {
    if (this->data[i] == val) return true;
  }
  return false;
}

void Vector::push_front(int val) {
  if (this->length == this->capacity) resize();
  for (int i = this->length; i > 0; i--) {
    this->data[i] = this->data[i - 1];
  }
  this->data[0] = val;
  this->length++;
}

void Vector::push_back(int val) {
  if (this->length == this->capacity) resize();

  this->data[this->length] = val;
  this->length++;
}

int& Vector::at(int index) {
  if (index < 0 || index >= this->length) {
    throw out_of_range("Index out of bounds");
  }
  return (this->data[index]);
}

void Vector::erase(int index) {
  if (index < 0 || index >= this->length) {
    throw out_of_range("Index out of bounds");
  }

  for (int i = index; i < this->length - 1; i++) {
    this->data[i] == this->data[i + 1];
  }
  // What if this is a vector of  objects? need to invoke destructor of
  // this->data[length-1]
  this->length--;
}

void Vector::print() const {
  for (int i = 0; i < this->length; i++) {
    cout << this->data[i] << " ";
  }
  cout << endl;
}

void Vector::resize() {
  int* oldArr = this->data;

  this->capacity *= 2;
  this->data = new int[this->capacity];
  for (int i = 0; i < this->length; i++) {
    this->data[i] = oldArr[i];
  }
  delete[] oldArr
}