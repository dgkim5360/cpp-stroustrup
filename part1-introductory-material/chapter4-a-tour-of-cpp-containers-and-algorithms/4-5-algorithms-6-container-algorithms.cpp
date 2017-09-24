#include<iostream>
#include<string>
#include<vector>
#include<list>
#include<algorithm>
namespace Estd {
  using namespace std;
  // shorthand for sort(v.begin(), v.end()) -> sort(v)
  template<class C>
  void sort(C& c) {sort(c.begin(), c.begin());}

  template<class C, class Pred>
  void sort(C& c, Pred p) {sort(c.begin(), c.end(), p);}
}
using namespace Estd;

// 4-5-algorithms.cpp
struct Entry {
  string name;
  int number;
};

bool operator<(const Entry& x, const Entry& y) {return x.name < y.name;}
bool operator==(const Entry& x, const Entry& y) {return x.name == y.name;}

list<Entry> sort_to_list(vector<Entry>& vec) {
  list<Entry> res;

  sort(vec);
  unique_copy(vec.begin(), vec.end(), back_inserter(res));
  return res;
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

// 4-3-stream-io.cpp
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
