#include<iostream>
#include<string>
#include<vector>
using namespace std;

struct Entry {
  string name;
  int number;
};

ostream& operator<<(ostream& os, const Entry& e);
istream& operator>>(istream& is, Entry& e);

void print_book(const vector<Entry>& book) {
  /* loop with subscripting
  for (int i = 0; i != book.size(); i++)
    cout << book[i] << '\n';
  */
  for (const auto& x: book)  // range-for loop
    cout << x << '\n';
}

void input_book(vector<Entry>& book) {
  for (Entry e; cin >> e;)
    book.push_back(e);
}

// 4.4.1.2. Range Checking
void silly(vector<Entry>& book) {
  // out of range, but not giving an error
  int i = book[book.size()].number;
  cout << "WTF: " << i << endl;
}

int main() {
  vector<Entry> phone_book;
  /* examples of initialization for vectors
  vector<Entry> phone_book = {
    {"David Hume", 1234567},
    {"Karl Popper", 234567},
    {"Bertrand Arthur William Russell", 3488865}
  };
  vector<int> v1 = {1, 2, 3, 4};  // size is 4
  vector<string> v2;  // size is 0
  vector<Shape*> v3(23);  // size is 23, initial element value: nullptr
  vector<double> v4(32, 9.9);  // size is 32, initial value: 9.9 */

  input_book(phone_book);
  print_book(phone_book);
  silly(phone_book);
  return 0;
}

// 4-3-stream-io.cpp
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
