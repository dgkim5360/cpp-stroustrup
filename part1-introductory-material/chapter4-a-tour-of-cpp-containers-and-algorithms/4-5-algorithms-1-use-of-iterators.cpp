#include<iostream>
#include<algorithm>
#include<string>
#include<vector>
#include<list>
using namespace std;

bool has_c(const string& s, char c) {
  /* The standard algorithm `find` looks for a value in a sequence and returns
  an iterator to the element found.
  */
  return find(s.begin(), s.end(), c) != s.end();
  // auto p = find(s.begin(), s.end(), c);
  // if (p != s.end())
  //   return true;
  // else
  //   return false;
}

vector<string::iterator> find_all(string& s, char c) {
  /* Assuming that we would like to modify the locations found,
  we pass a non-const string.
  */
  vector<string::iterator> res;

  for (auto p = s.begin(); p != s.end(); ++p)
    if (*p == c)
      res.push_back(p);
  return res;
}

// We can hide this implementation detail by introducing a type alias for iterator
template<typename T>
using Iterator = typename T::iterator;

// Generalization of find_all
template<typename C, typename V>
// vector<typename C::iterator> find_all(C& c, V v) {
vector<Iterator<C>> find_all(C& c, V v) { // find all occurrences of v in c
  // vector<typename C::iterator> res;
  vector<Iterator<C>> res;
  for (auto p = c.begin(); p != c.end(); ++p)
    if (*p == v)
      res.push_back(p);
  return res;
}

int main() {
  // test for find_all
  string m {"Mary had a little lamb"};
  for (auto p: find_all(m, 'a'))  // p is a string::iterator
    if (*p != 'a')
      cerr << "a bug!" << endl;

  list<double> ld {1.1, 2.2, 3.3, 1.1};
  for (auto p: find_all(ld, 1.1))
    if (*p != 1.1)
      cerr << "list bug!" << endl;

  vector<string> vs {"red", "blue", "green", "green", "orange", "green"};
  for (auto p: find_all(vs, "green"))
    if (*p != "green")
      cerr << "vector bug!" << endl;

  cout << "Input:" << endl << '\t';
  for (auto& s: vs)
    cout << s << ' ';
  cout << endl;
  for (auto p: find_all(vs, "green"))
    *p = "vert";
  cout << "Converted:" << endl << '\t';
  for (auto& s: vs)
    cout << s << ' ';
  cout << endl;
  return 0;
}
/* Iterators are used to separate algorithms and containers. An algorithm operates
on its data through iterators and knows nothing about the container in which the
elements are stored. Conversely, a container knows nothing about the algorithms
operating on its elements; all it does is to supply iterators upon request
(e.g., begin() and end()). This model of separation between data storage and
algorithm delivers very general and flexible software. */
