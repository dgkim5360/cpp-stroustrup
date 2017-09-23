#include <iostream>
using namespace std;

struct Vector {
  int sz;  // number of elements
  double *elem;  // pointer to elements
};

void vector_init(Vector &v, int s) {  // pass v by non-const reference
  v.elem = new double[s];  // allocate an array of s doubles
  v.sz = s;
}

// read s integers from cin and return their sum; s is assumed to be positive
double read_and_sum(int s) {
  Vector v;
  vector_init(v, s);

  for (int i = 0; i != s; ++i)
    cin >> v.elem[i];  // read into elements

  double sum = 0;
  for (int i = 0; i != s; ++i)
    sum += v.elem[i];  // take the sum of elements
  return sum;
}

int main() {
  cout << "Insert numbers you want to sum:" << '\n';
  int sum = read_and_sum(10);
  cout << "The sum is " << sum << "\n";
  return 0;
}

/** an example of accessing struct members
void f(Vector v, Vector &rv, Vector *pv) {
  int i1 = v.sz;  // access through name
  int i2 = rv.sz;  // access through reference
  int i3 = pv->sz;  // access through pointer
}
*/
