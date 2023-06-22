#include "List342.h"

#include <fstream>
#include <iostream>

using namespace std;

// Implementation of Constructors and destructors :
template <typename ItemType>
List342<ItemType>::List342() {
  head_ = NULL;
}

template <typename ItemType>
List342<ItemType>::List342(const List342& l) {
  head_ = NULL;
  *this = l;
}

template <typename ItemType>
List342<ItemType>::~List342() {
  this->DeleteList();
}

// Implementations of Functions:

template <typename ItemType>
bool List342<ItemType>::BuildList(string fileName) {
  ifstream txtFile;
  txtFile.open(fileName);
  if (txtFile.is_open()) {
    while (!txtFile.eof()) {
      string s = "";
      getline(txtFile, s);

      ItemType* obj = new ItemType(s);
      Insert(obj);
    }
    txtFile.close();
    return true;
  } else {
    cout << "File: " << fileName << "not found" << endl;
    return false;
  }
}

// Inserts a piece of data into the linked list
template <typename ItemType>
bool List342<ItemType>::Insert(ItemType* obj) {
  node<ItemType>* current;
  node<ItemType>* past;

  if (head_ == NULL) {
    node<ItemType>* insert = new node<ItemType>();
    insert->data = obj;
    insert->next = NULL;
    head_ = insert;

    return true;
  }

  if (*head_->data == *obj) {
    return false;
  }

  if (*obj < *(head_->data)) {
    node<ItemType>* insert = new node<ItemType>();
    insert->data = obj;
    insert->next = NULL;

    insert->next = head_;
    head_ = insert;

    return true;
  }

  past = head_;
  current = head_->next;

  while (current != NULL && past != NULL && *(current->data) < *obj) {
    current = current->next;
    past = past->next;
  }

  if (current != NULL && past != NULL && *current->data == *obj) {
    return false;
  }

  node<ItemType>* insert = new node<ItemType>();
  insert->data = obj;

  insert->next = current;
  past->next = insert;

  return true;
}

// Removes a piece of data from the linked list
template <typename ItemType>
bool List342<ItemType>::Remove(ItemType target, ItemType& result) {
  // node<ItemType>* current;
  node<ItemType>* past;

  if (isEmpty()) {
    return false;
  }

  if (*(head_->data) == target) {
    node<ItemType>* temp = head_;
    result = *(head_->data);
    head_ = head_->next;
    delete temp;
    return true;
  }

  past = head_;

  while (past->next != NULL && *(past->next->data) != target) {
    past = past->next;
  }

  if (past->next == NULL) {
    return false;
  }

  if (*(past->next->data) == target) {
    node<ItemType>* temp = past->next;
    result = *(temp->data);
    past->next = past->next->next;
    delete temp;
    return true;
  }

  return false;
}

// Finds if a piece of *dataexist in the linked list
template <typename ItemType>
bool List342<ItemType>::Peek(ItemType target, ItemType& result) const {
  node<ItemType>* current;

  current = head_->next;

  while (current != NULL && *(current->data) != target) {
    current = current->next;
  }

  if (current == NULL) {
    return false;
  }

  result = *(current->data);

  return true;
}

// Checks if the linked list is empty
template <typename ItemType>
bool List342<ItemType>::isEmpty() const {
  if (head_ == NULL) {
    return true;
  }

  else {
    return false;
  }
}

// Deletes the entire linked list
template <typename ItemType>
void List342<ItemType>::DeleteList() {
  node<ItemType>* current;

  current = NULL;

  while (head_ != NULL) {
    current = head_->next;
    delete head_;
    head_ = current;
  }

  head_ = NULL;
}

// Merges the linked listed passed in with the current linked list
template <typename ItemType>
bool List342<ItemType>::Merge(List342& list1) {
  node<ItemType>* c1;
  node<ItemType>* p1;
  node<ItemType>* c2;
  node<ItemType>* p2;

  // Starting Points
  c1 = head_;
  c2 = list1.head_;

  // Starting Edge Cases
  if (c1 == NULL && c2 == NULL) {
    return true;
  }

  if (c1 == NULL) {
    head_ = c2;
    list1.head_ = NULL;
    return true;
  }

  if (c2 == NULL) {
    return true;
  }

  if (c1 == c2) {
    return true;
  }

  // Check for dublicate
  if (*(c1->data) == *(c2->data)) {
    node<ItemType>* temp = c1;
    c1 = c1->next;
    delete temp;
  }

  // Fix front
  if ((*c1->data) < *(c2->data)) {
    p1 = c1;
    c1 = c1->next;
    p2 = p1;
  }

  else {
    p1 = c2;
    c2 = c2->next;
    p2 = p1;
  }

  // Iterate
  while (c1 != NULL && c2 != NULL) {
    if (*(c1->data) == *(c2->data)) {
      node<ItemType>* temp = c1;
      c1 = c1->next;
      p1->next = c2;
      p1 = c2;
      c2 = c2->next;
      delete temp;
    }

    else if (*(c1->data) > *(c2->data)) {
      p1->next = c2;
      p1 = c2;

      c2 = c2->next;
    }

    else {
      p1->next = c1;
      p1 = c1;
      c1 = c1->next;
    }
  }

  // Exit Edge Cases
  if (c2 == NULL) {
    p1->next = c1;
  }

  if (c1 == NULL) {
    p1->next = c2;
  }

  // returning / results
  head_ = p2;

  list1.head_ = NULL;

  return true;
}

// Implementation of Operator Overload functions:

template <typename ItemType>
ostream& operator<<(ostream& output, const List342<ItemType>& l) {
  node<ItemType>* printNode;
  printNode = l.head_;
  while (printNode != NULL) {
    output << *(printNode->data);
    printNode = printNode->next;
  }
  return output;
}

// Adds two linked list together returning a new linked list
template <typename ItemType>
List342<ItemType> List342<ItemType>::operator+(const List342<ItemType>& l) {
  List342 list = *this;
  list += l;
  return list;
}

// Adds a linked list to the original linked list
template <typename ItemType>
List342<ItemType>& List342<ItemType>::operator+=(const List342<ItemType>& l) {
  List342<ItemType> newList = l;

  this->Merge(newList);

  return *this;
}

// Checks if the linked list are the same
template <typename ItemType>
bool List342<ItemType>::operator==(const List342<ItemType>& l) {
  if (head_ == NULL && l.head_ == NULL) {
    return true;
  }
  if (head_ == NULL || l.head_ == NULL) {
    return false;
  }
  node<ItemType>* temp1;
  node<ItemType>* temp2;
  temp1 = head_;
  temp2 = l.head_;

  while (temp1 != NULL && temp2 != NULL) {
    if (*(temp1->data) != *(temp2->data)) {
      return false;
    }

    temp1 = temp1->next;
    temp2 = temp2->next;
  }

  if ((temp1 == NULL && temp2 != NULL) || (temp2 == NULL && temp1 != NULL)) {
    return false;
  }

  return true;
}

// Checks if the linked list are different
template <typename ItemType>
bool List342<ItemType>::operator!=(const List342<ItemType>& l) {
  if (head_ == NULL && l.head_ == NULL) {
    return false;
  }
  if (head_ == NULL || l.head_ == NULL) {
    return true;
  }
  node<ItemType>* temp1;
  node<ItemType>* temp2;
  temp1 = head_;
  temp2 = l.head_;

  while (temp1 != NULL && temp2 != NULL) {
    if (*(temp1->data) != *(temp2->data)) {
      return true;
    }
    temp1 = temp1->next;
    temp2 = temp2->next;
  }
  return false;
}

template <typename ItemType>
List342<ItemType>& List342<ItemType>::operator=(const List342<ItemType>& l) {
  if (this == &l) return *this;

  if (!isEmpty() || l.head_ == NULL) {
    DeleteList();
  }

  node<ItemType>* copiedFront = l.head_;
  node<ItemType>* copyObjNode = new node<ItemType>();
  ItemType* copyObjData = new ItemType;

  *copyObjData = *(l.head_->data);
  copyObjNode->data = copyObjData;
  head_ = copyObjNode;

  node<ItemType>* temp = head_;

  while (copiedFront->next != NULL) {
    copyObjNode = new node<ItemType>();
    copiedFront = copiedFront->next;

    copyObjNode->data = copiedFront->data;
    temp->next = copyObjNode;
    temp = temp->next;
  }

  temp->next = NULL;
  return *this;
}