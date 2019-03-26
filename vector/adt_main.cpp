#include <iomanip>
#include <iostream>
#include "adt_list.h"
#include "adt_vector.h"
using namespace std;
int main() {
  List* list = new Vector();
  cout << "Empty=" << list->empty() << endl;
  for (int i = 0; i < 6; i++) {
    list->push_back(i);
    cout << "Listsize=" << list->size() << endl;
    list->print();
  }
  for (int j = 11; j > 6; j--) {
    list->push_front(j);
    cout << "List size=" << list->size() << endl;
    list->print();
  }
  cout << "Empty=" << list->empty() << endl;
  cout << "list->at(5)=" << list->at(5) << endl;
  cout << "list->at(1)=" << list->at(1) << endl;
  cout << "contains(55)=" << list->contains(55) << endl;
  cout << "contains(4)=" << list->contains(4) << endl;
  list->erase(0);
  list->print();
  list->erase(5);
  list->print();
}