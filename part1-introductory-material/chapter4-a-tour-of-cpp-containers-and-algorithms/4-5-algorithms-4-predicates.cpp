#include<iostream>
#include<string>
#include<map>
#include<utility>
#include<algorithm>
using namespace std;

struct Entry {
  string name;
  int number;
};

struct Less_than {
  int val;
  Less_than(int v): val{v} {}
  bool operator()(const pair<string,int>& r) {return r.second < val;}
};

void f(map<string,int>& m) {
  auto p = find_if(m.begin(), m.end(), Less_than{200000});
  // alternative using lambda expression
  // auto p = find_if(m.begin(), m.end(), [](const pair<string,int>& r) {return r.second < 200000;});
  cout << p->first << ' ' << p->second << endl;
}

/* In the examples above, the algorithms have simply ‘‘built in’’ the action to
be done for each element of a sequence. However, we often want to make that action
a parameter to the algorithm.
A more general variant looks for an element that fulfills a specified requirement, a predicate.*/
int main() {
  map<string, int> phone_book {
    {"David Hume", 123456},
    {"Karl Popper", 234567},
    {"Bertrand Arthur William Russell", 345678}
  };

  f(phone_book);
  return 0;
}
