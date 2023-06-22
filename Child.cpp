/*
Name: Rohan Patel
Course: CSS342
Assighment: Program4
Last Edited: 11/19/2022
Description: the implementation of Child
*/

#include "Child.h"

// Implement Constructor:
Child::Child() : fName_(""), lName_(""), id_(0) {}
Child::Child(string fName, string lName, int id) {
  fName_ = fName;
  lName_ = lName;
  id_ = id;
}

Child::Child(string s) {
  string word = "";
  for (int i = 0; i < s.length(); i++) {
    word += s[i];

    if (s[i] == ' ') {
      if (fName_ == "") {
        fName_ = word;
        word = "";
      }
      if (lName_ == "") {
        lName_ = word;
        word = "";
      }
    }
    if (i == s.length() - 1) {
      id_ = stoi(word);
      word = "";
    }
  }
}

// Implement getters and setters:

string Child::getFName() const { return fName_; }
string Child::getLName() const { return lName_; }
int Child::getID() const { return id_; }

// Implement operator overload

bool Child::operator>(const Child &c) {
  if (lName_ == c.lName_) {
    return (fName_ > c.fName_);
  }

  else {
    return (lName_ > c.lName_);
  }
}

bool Child::operator<(const Child &c) {
  if (lName_ == c.lName_) {
    return (fName_ < c.fName_);
  }

  else {
    return (lName_ < c.lName_);
  }
}

bool Child::operator>=(const Child &c) {
  if (lName_ == c.lName_) {
    return (fName_ >= c.fName_);
  }

  else {
    return (lName_ >= c.lName_);
  }
}

bool Child::operator<=(const Child &c) {
  if (lName_ == c.lName_) {
    return (fName_ <= c.fName_);
  }

  else {
    return (lName_ <= c.lName_);
  }
}
// bool Child::operator=(const Child &c) {}

bool Child::operator!=(const Child &c) {
  if (lName_ != c.lName_ && fName_ != c.fName_ && id_ != c.id_) {
    return true;
  }
  return false;
}
bool Child::operator==(const Child &c) {
  if (lName_ == c.lName_ && fName_ == c.fName_ && id_ == c.id_) {
    return true;
  }
  return false;
}

bool Child::operator=(const Child &c) {
  (fName_ = c.fName_);
  (lName_ = c.lName_);
  (id_ = c.id_);

  return true;
}

ostream &operator<<(ostream &output, const Child &c) {
  output << c.getFName() << c.getLName() << c.getID();

  return output;
}

istream &operator>>(istream &input, Child &c) {
  input >> c.fName_ >> c.lName_ >> c.id_;

  return input;
}