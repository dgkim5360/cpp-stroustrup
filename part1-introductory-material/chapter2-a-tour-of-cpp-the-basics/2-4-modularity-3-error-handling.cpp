#include <iostream>
using namespace std;

/** 2.4.3.2. Invariants
Statements of what is assumed to be true for a class. Invariants
help us to understand precisely what we want, and force us to be specific; that
gives us a better chance of getting our code correct (after debugging and testing).
*/
class Vector {
public:
  Vector(int s) {  // construct a Vector
    if (s < 0)
      throw length_error("Vector::Vector");
    elem = new double[s];
    sz = s;
  }
  double &operator[](int i) {  // element access: subscripting
    if (i < 0 || size() <= i)
      throw out_of_range("Vector::operator[]");
    return elem[i];
  }
  int size() { return sz; }
private:
  double *elem;  // pointer to the elements
  int sz;  // the number of elements
};

int main() {
  Vector v(6);
  try {  // exceptions here are handled by the handler defined below
    cout << "Let's inject 7\n";
    v[v.size()] = 7;  // try to access beyond the end of v
  }
  catch (out_of_range) {  // oops, out_of_range error
    // handle range error
    cout << "oops, out_of_range error :(\n";
  }

  try {
    Vector v(-27);
  }
  catch (length_error) {
    cout << "There's no vector of negative length\n";
  }
  catch (bad_alloc) {
    cout << "what is this?\n";
  }
  return 0;
}

/** 2.4.3.3. Static Assertion
The static_assert mechanism can be used for anything that can be expressed
in terms of constant expressions. In general, static_assert(A, S) prints S
as a compiler error message if A is not true. */
