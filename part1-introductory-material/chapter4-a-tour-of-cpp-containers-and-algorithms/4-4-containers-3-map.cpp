// The standard library offers a (red-black) search tree called map
#include<iostream>
#include<map>
#include<string>
using namespace std;

int main() {
  int get_number(const string& s, map<string, int>& book);

  map<string, int> phone_book {
    {"David Hume", 123456},
    {"Karl Popper", 234567},
    {"Bertrand Arthur William Russell", 345678}
  };
  cout << "You've got a number: " << get_number("Karl Popper", phone_book) << endl;
  return 0;
}

int get_number(const string& s, map<string, int>& book) {
  /* If a key isn’t found, it is entered into the map with a default value for
  its value . The default value for an integer type is 0; the value I just happened
  to choose represents an invalid telephone number.
  */
  return book[s];
  /* If we wanted to avoid entering invalid numbers into our phone book,
  we could use find() and insert() instead of []
  */
}
