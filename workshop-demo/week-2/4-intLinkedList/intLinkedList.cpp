#include "intLinkedList.h"

intLinkedList::intNode::intNode() {
  //   intNode::data = 0;
  //   intNode::next = nullptr;
}

intLinkedList::intNode::intNode(intNode* n, int d) {
  intNode::data = d;
  intNode::next = n;
}

intLinkedList::intNode::~intNode() {
  // You don't have to do anything for this one
}

int intLinkedList::intNode::getData() { return intNode::data; }

intLinkedList::intNode* intLinkedList::intNode::getNext() {
  return intNode::next;
}

void intLinkedList::intNode::setNext(intNode* n) { intNode::next = n; }

intLinkedList::intLinkedList() {
  //   head = nullptr;
  //   length = 0;
}

intLinkedList::~intLinkedList() {}

bool intLinkedList::isEmpty() {
  // 	two ways 1. lenth is 0
  return (length == 0);
}

void intLinkedList::prepend(int c) {
  intNode* node = new intNode(head, c);
  // intLinkedList list = new intLinkedList();
  head = node;
  length++;
}

void intLinkedList::append(int c) {
  intNode* mainHead = head;
  intNode* node = new intNode(nullptr, c);

  for (int i = 0; i < length; i++) {
    if (head->getNext() == nullptr) {
      head->setNext(node);
    }
    head = head->getNext();
  }
  head = mainHead;
  length++;
}

int intLinkedList::getHead() { return head->getData(); }

intLinkedList* intLinkedList::tail() {
  //   intNode* secondNode = head->getNext();
  //   intNode* node = new intNode(secondNode, secondNode->getData());
  //   intLinkedList* tail = new intLinkedList();
  //   tail->length = length - 1;
  //   for (int i = 0; i < length - 1; i++) {
  // 	  tail->append()
  // }

  // tail->head = node;
  // return tail;
  head = head->getNext();
  return this;
}
