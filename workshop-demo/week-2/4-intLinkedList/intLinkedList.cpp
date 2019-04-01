#include "intLinkedList.h"
#include <iostream>

intLinkedList::intNode::intNode() {
  intNode::data = 0;
intNode:
  next = nullptr;
}

intLinkedList::intNode::intNode(intNode* n, int d) {
  intNode::data = d;
  intNode::next = n;
}

intLinkedList::intNode::~intNode() {
  // You don't have to do anything for this one
}

int intLinkedList::intNode::getData() { return data; }

intLinkedList::intNode* intLinkedList::intNode::getNext() { return next; }

void intLinkedList::intNode::setNext(intNode* n) { this->next = n; }

intLinkedList::intLinkedList() {
  head = nullptr;
  length = 0;
}

intLinkedList::~intLinkedList() {}

bool intLinkedList::isEmpty() { return (length == 0); }

void intLinkedList::prepend(int c) {
  intNode* node = new intNode(head, c);
  head = node;
  length++;
}

void intLinkedList::append(int c) {
  if (head == nullptr) {
    intNode* newNode = new intNode(nullptr, c);
    head = newNode;
    length++;
  } else {
    intNode* tempHead = head;
    intNode* newNode = new intNode(nullptr, c);

    for (int i = 0; i < length - 1; i++) {
      tempHead = tempHead->getNext();
    }
    tempHead->setNext(newNode);
    this->length++;
  }
}

int intLinkedList::getHead() { return this->head->getData(); }

intLinkedList* intLinkedList::tail() {
  intLinkedList* tail = new intLinkedList();

  tail->head = head->getNext();
  tail->length = this->length - 1;
  return tail;
};