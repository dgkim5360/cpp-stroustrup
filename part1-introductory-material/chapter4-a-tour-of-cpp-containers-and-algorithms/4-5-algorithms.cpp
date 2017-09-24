#include<iostream>
#include<string>
#include<vector>
#include<list>
#include<algorithm>
using namespace std;

struct Entry {
  string name;
  int number;
};

// order Entries by their name
bool operator<(const Entry& x, const Entry& y) {return x.name < y.name;}
bool operator==(const Entry& x, const Entry& y) {return x.name == y.name;}

/* The standard algorithms are expressed in terms of sequences of elements.
A sequence is represented by a pair of iterators specifying the first element
and the one-beyond-the-last element. */
void sort_and_copy_to_list(vector<Entry>& vec, list<Entry>& lst) {
  /* sort() sorts the sequence defined by the pair of iterators vec.begin() and
  vec.end() -- which just happens to be all the elements of a vector. */
  sort(vec.begin(), vec.end());

  /* for writing (output), you need only to specify the first element to be written.
  Thus, to avoid errors, lst must have at least aas many elements as there are
  unique values in vec. */
  unique_copy(vec.begin(), vec.end(), lst.begin());
}

list<Entry> sort_to_list(vector<Entry>& vec) {
  list<Entry> res;

  sort(vec.begin(), vec.end());
  unique_copy(vec.begin(), vec.end(), back_inserter(res));  // append to res
  /* back_inserter adds elements at the end of a container, extending the container
  to make room for them. */
  return res;  // The standard-library list has a move constructor that makes returning res by value efficient
}

int main() {
  vector<Entry> phone_book;
  ostream& operator<<(ostream& os, const Entry& e);
  void input_book(vector<Entry>&);

  input_book(phone_book);
  cout << "Input:" << endl;
  for (const auto& item: phone_book)
    cout << item << endl;
  list<Entry> sorted = sort_to_list(phone_book);
  cout << "Sorted:" << endl;
  for (const auto& item: sorted)
    cout << item << endl;
  return 0;
}

// from 4-3-stream-io.cpp
ostream& operator<<(ostream& os, const Entry& e) {
  return os << "{\"" << e.name << "\"," << e.number << "}";
}

istream& operator>>(istream& is, Entry& e);

void input_book(vector<Entry>& book) {
  for (Entry e; cin >> e;)
    book.push_back(e);
}

istream& operator>>(istream& is, Entry& e) {
  char c, c2;
  if (is >> c && c == '{' && is >> c2 && c2 == '"') {
    string name;
    while (is.get(c) && c != '"')
      name += c;
    if (is >> c && c == ',') {
      int number = 0;
      if (is >> number >> c && c == '}') {
        e = {name, number};
        return is;
      }
    }
  }
  // is.setf(ios_base::failbit);  // register the failure in the stream
  return is;
}
