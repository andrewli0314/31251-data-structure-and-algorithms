#ifndef NODE_H
#define NODE_H

class node {
 private:
  int data;
  node* nodePtr;

 public:
  node(int data);
  node(int data, node* nodePtr);

  void set_next(node* next);
  int get_data();
  node* get_next();
};

#endif
