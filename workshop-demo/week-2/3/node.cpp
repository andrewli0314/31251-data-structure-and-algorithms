#include "node.h"

// Constructor
node::node(int data) {
  this->data = data;
  this->nodePtr = nullptr;
}

node::node(int data, node* nodePtr) {
  this->data = data;
  this->nodePtr = nodePtr;
}

void node::set_next(node* next) { this->nodePtr = next; }

int node::get_data() { return this->data; }

node* node::get_next() { return this->nodePtr; }
