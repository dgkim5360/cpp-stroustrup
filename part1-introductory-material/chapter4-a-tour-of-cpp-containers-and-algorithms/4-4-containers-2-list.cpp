#include<iostream>
#include<string>
#include<list>
using namespace std;

struct Entry {
  string name;
  int number;
};

int main() {
  int get_numbers(const string& s, list<Entry>& book);
  /* doubly-linked list
  We use a list for sequences where we want to insert and delete elements without moving other ele-
ments.
  */
  list<Entry> phone_book = {
    {"David Hume", 123456},
    {"Karl Popper", 234567},
    {"Bertrand Arthur William Russell", 345678}
  };

  cout << "You've got a number: " << get_numbers("Karl Popper", phone_book) << endl;
  return 0;
}

int get_numbers(const string& s, list<Entry>& book) {
  /* When we use a linked list, we tend not to access elements using subscripting
  the way we commonly do for vectors. Instead, we might search the list looking
  for an element with a given value.

  for (const auto& x: book)
    if (x.name == s)
      return x.number;
  return 0;  // use 0 to represent "number not found"
  */

  /* Sometimes, we need to identify an element in a list . For example, we may
  want to delete it or insert a new entry before it. To do that we use an iterator:
  a list iterator identifies an element of a list and can be used to iterate through
  a list (hence its name). Every standard-library container provides the functions
  begin() and end() , which return an iterator to the first and to one-past-the-last
  element, respectively. */
  for (auto p = book.begin(); p != book.end(); ++p)
    // In fact, this is roughly the way the terser and less error-prone
    // range-for loop is implemented by the compiler.
    if (p->name == s)
      return p->number;
  return 0;  // use 0 to represent "number not found"
}

/* Adding and removing elements from a list

void f(const Entry& ee, list<Entry>::iterator p, list<Entry>::iterator q) {
  phone_book.insert(p, ee);  // add ee before the element referred to by p
  phone_book.erase(q);  // remove the element referred to by q
}
*/

/* These list examples could be written identically using vector and (surprisingly,
unless you understand machine architecture) perform better with a small vector than
with a small list. When all we want is a sequence of elements, we have a choice
between using a vector and a list. Unless you have a reason not to, use a vector.
A vector performs better for traversal (e.g., find() and count() ) and for sorting
and searching (e.g., sort() and binary_search()).
*/
