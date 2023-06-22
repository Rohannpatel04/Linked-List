#include <iostream>
#include <string>
using namespace std;

class Child {
  friend ostream &operator<<(ostream &output, const Child &c);
  friend istream &operator>>(istream &input, Child &c);

 public:
  // Constructor defintions
  Child();
  Child(string fName, string lName, int id);
  Child(string s);

  // Define getters and setters

  string getFName() const;
  string getLName() const;
  int getID() const;

  void set_child(string fName, string Lname, int id);

  // Define operator overloads

  bool operator>(const Child &c);
  bool operator<(const Child &c);
  bool operator>=(const Child &c);
  bool operator<=(const Child &c);
  bool operator=(const Child &c);
  bool operator!=(const Child &c);
  bool operator==(const Child &c);

 private:
  string fName_;
  string lName_;
  int id_;
};