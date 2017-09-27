/**
A class is a user-defined type provided to represent a concept in the code of a
program.

The basic idea of concrete classes is that they behave "just like built-in types".
e.g. complex type like int, vector and string like built-in array.
*/
#include<iostream>
using namespace std;

class complex {  // slightly simplified version of std::complex
  double re, im;  // representation: two doubles
public:
  complex(double r, double i) : re{r}, im{i} {}  // construct complex from two scalars
  complex(double r) : re{r}, im{0} {}  // construct complex from one scalar
  complex() : re{0}, im{0} {}  // default constructor of complex: {0, 0}

  // const implies the function does not modify the object for which they are called.
  double real() const { return re; }
  void real(double d) { re = d; }
  double imag() const { return im; }
  void imag(double d) { im = d; }

  complex& operator +=(complex z) {  // add to re and im and return the result
    re += z.re, im += z.im; return *this;
  }
  complex& operator -=(complex z) { re -= z.re, im -= z.im; return *this; }
  // complex& operator *=(complex);
  // complex& operator /=(complex);
};

/**
Many useful operations do not require direct access to the representation of complex,
so they can be defined separately from the class definition.

Note the fact that an argument passed by value is copied.
*/
complex operator+(complex a, complex b) { return a += b; }
complex operator-(complex a, complex b) { return a -= b; }
complex operator-(complex a) { return {-a.real(), -a.imag()}; }  // unary minus
// complex operator*(complex a, complex b) { return a *= b; }
// complex operator/(complex a, complex b) { return a /= b; }

bool operator==(complex a, complex b) {
  return a.real() == b.real() && a.imag() == b.imag();
}
bool operator!=(complex a, complex b) {
  return !(a == b);
}

int main() {
  complex a {2.3};  // construct {2.3, 0.0}
  complex b {6.3, 1};
  complex c {a + b};
  complex d {b - 10};  // b - complex {10}

  cout << "a = (" << a.real() << ", " << a.imag() << ')' << endl;
  cout << "b = (" << b.real() << ", " << b.imag() << ')' << endl;
  cout << "a+b = (" << c.real() << ", " << c.imag() << ')' << endl;
  cout << "b-10 = (" << d.real() << ", " << d.imag() << ')' << endl;
  return 0;
}
