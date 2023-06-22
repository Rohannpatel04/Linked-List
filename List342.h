#ifndef LIST342_H_
#define LIST342_H_
#include <iostream>
using namespace std;

template <typename ItemType>
struct node {
  ItemType* data;
  node* next;
};

template <typename ItemType>
class List342 {
  template <typename T>
  friend ostream& operator<<(ostream& output, const List342<T>& l);

 public:
  // Define Constructors:

  List342();
  List342(const List342& l);
  ~List342();

  // Define Functions:

  // Creates a linked list with the use of reading a file ???
  bool BuildList(string fileName);

  // Inserts a piece of data into the linked list

  bool Insert(ItemType* obj);

  // Removes a piece of data from the linked list

  bool Remove(ItemType target, ItemType& result);

  // Finds if a piece of data exist in the linked list

  bool Peek(ItemType target, ItemType& result) const;

  // Checks if the linked list is empty
  bool isEmpty() const;

  // Deletes the entire linked list
  void DeleteList();

  // Merges the linked listed passed in with the current linked list
  bool Merge(List342& list1);

  // Define Operator Overloads:

  // Adds two linked list together returning a new linked list
  List342 operator+(const List342<ItemType>& l);

  // Adds a linked list to the original linked list
  List342& operator+=(const List342<ItemType>& l);

  // Checks if the linked list are the same
  bool operator==(const List342<ItemType>& l);

  // Checks if the linked list are different
  bool operator!=(const List342<ItemType>& l);

  // Makes a copy of the linked list
  List342& operator=(const List342<ItemType>& l);

 private:
  node<ItemType>* head_;
};
#endif
