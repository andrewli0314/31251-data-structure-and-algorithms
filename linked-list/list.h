
#ifndef LIST_H_
#define LIST_H_

#include <iostream>
#include <string>

class List {
 private:
  class Node {
    int data;    // stores data into the node
    Node* next;  // points to next node
  };

  typedef Node* nodePointer;  // prefix for node pointr

  nodePointer head;  // Node* head;
  nodePointer current;
  nodePointer temp;

 public:
  List();  // Constructor
  void addNode(int addData);
  void deleteNode(int deleteData);
  void printList();
};

#endif
