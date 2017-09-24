#include<iostream>
#include<string>
#include<vector>
using namespace std;

struct Entry {
  string name;
  int number;
};

template<typename T>
class Vec: public vector<T> {
public:
  using vector<T>::vector;  // using the constructors from vector (under the name Vec)

  T& operator[](int i) {return vector<T>::at(i);}  // range check

  const T& operator[](int i) const {return vector<T>::at(i);}  // range check const objects
};

void input_book(Vec<Entry>& book);

void checked(Vec<Entry>& book) {
  try {
    book[book.size()] = {"JJoe", 9999999};  // will throw an exception
  }
  catch (out_of_range) {
    cerr << "RangeError" << endl;
  }
}

int main() {
  Vec<Entry> phone_book;

  input_book(phone_book);
  checked(phone_book);
  return 0;
}

istream& operator>>(istream& is, Entry& e);

void input_book(Vec<Entry>& book) {
  for (Entry e; cin >> e;)
    book.push_back(e);
}

// corresponding input operator
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
