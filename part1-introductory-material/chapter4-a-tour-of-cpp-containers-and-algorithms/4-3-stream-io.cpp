#include<iostream>
#include<string>
using namespace std;

struct Entry {
  string name;
  int number;
};

// a simple output operator for Entry
ostream& operator<<(ostream& os, const Entry& e) {
  return os << "{\"" << e.name << "\"," << e.number << "}";
}

// corresponding input operator
istream& operator>>(istream& is, Entry& e) {
  char c, c2;
  // if (is >> c) means "Did we succeed at reading from is into c?"
  if (is >> c && c == '{' && is >> c2 && c2 == '"') {  // start with a {"
    string name;  // the default value of a string is the empty string: ""
    // is >> c skips whitespace by default, but is.get(c) does not.
    while (is.get(c) && c != '"')  // anything before a " is part of the name
      name += c;
    if (is >> c && c == ',') {
      int number = 0;
      if (is >> number >> c && c == '}') {  // read the number and a }
        e = {name, number};  // assign to the entry
        return is;
      }
    }
  }
  // is.setf(ios_base::failbit);  // register the failure in the stream
  return is;
}

int main() {
  for (Entry ee; cin >> ee;)  // read from cin into ee
    cout << ee <<'\n';  // write ee to cout
  return 0;
}
