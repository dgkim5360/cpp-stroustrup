#include<iostream>
#include<vector>
using namespace std;
/* Templates are extensively used for parameterization of both types and algorithms
in the standard library. */
template<typename Container, typename Value>
Value sum(const Container& c, Value v) {
  for (auto x: c)
    v += x;
  return v;
}

int main() {
  vector<int> v {1,2,3,4,5,6,7,8,9};
  cout << sum(v, 0) << endl;
  return 0;
}
