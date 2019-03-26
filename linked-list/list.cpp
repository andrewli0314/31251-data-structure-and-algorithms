#include "list.h"
#include <cstdlib>
#include <iostream>

using namespace std;

List::List() {
  head = NULL;
  current = NULL;
  temp = NULL;
}

void List::addNode(int addData) {
  nodePointer n = new;
  n->next = NULL;
}

void List::deleteNode(int deleteData) {}

void List::printList() {}