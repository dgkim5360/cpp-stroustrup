#include <iostream>
using namespace std;

class Vector {
public:
  Vector(int s) :elem {new double[s]}, sz {s} { }  // construct a Vector
  double &operator[](int i) { return elem[i]; }  // element access: subscripting
  int size() { return sz; }
private:
  double *elem;  // pointer to the elements
  int sz;  // the number of elements
};

// definition of a Vector with 6 elements: Vector v(6);

double read_and_sum(int s) {
  Vector v(s);  // make a vector of s elements
  for (int i = 0; i != v.size(); ++i)
    cin >> v[i];  // read into elements

  double sum = 0;
  for (int i = 0; i != v.size(); ++i)
    sum += v[i];
  return sum;
}

int main() {
  cout << "Insert numbers you want to sum:" << '\n';
  int sum = read_and_sum(10);
  cout << "The sum is " << sum << "\n";
  return 0;
}
