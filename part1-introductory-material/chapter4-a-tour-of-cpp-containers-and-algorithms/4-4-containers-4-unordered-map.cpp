/* The cost of a map lookup is O(log(n)) where n is the number of elements in the map.
That’s pretty good. For example, for a map with 1,000,000 elements, we perform only
about 20 comparisons and indirections to find an element. However, in many cases,
we can do better by using a hashed lookup rather than comparison using an ordering
function, such as <. The standard-library hashed containers are referred to as
‘unordered’ because they don’t require an ordering function.
*/
#include<iostream>
#include<unordered_map>
#include<string>
using namespace std;

int main() {
  int get_number(const string& s, unordered_map<string, int>& book);

  unordered_map<string, int> phone_book {
    {"David Hume", 123456},
    {"Karl Popper", 234567},
    {"Bertrand Arthur William Russell", 345678}
  };
  cout << "You've got a number: " << get_number("Karl Popper", phone_book) << endl;
  return 0;
}

int get_number(const string& s, unordered_map<string, int>& book) {
  /* If a key isn’t found, it is entered into the map with a default value for
  its value . The default value for an integer type is 0; the value I just happened
  to choose represents an invalid telephone number.
  */
  return book[s];
  /* If we wanted to avoid entering invalid numbers into our phone book,
  we could use find() and insert() instead of []
  */
}
