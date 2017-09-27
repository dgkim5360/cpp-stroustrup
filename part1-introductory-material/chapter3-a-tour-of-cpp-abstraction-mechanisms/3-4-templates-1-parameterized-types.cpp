#include<iostream>
#include<string>
#include<list>
using namespace std;
/* A template is a class or a function that we parameterize with a set of types
or values. */

template<typename T>  // C++ version of the mathmatical "for all types T"
class Vector {
private:
  T *elem;  // elem points to an array of sz elements of type T
  int sz;
public:
  Vector(int s);  // constructor: establish invariant, acquire resources
  ~Vector() {delete[] elem;}  // destructor: release resources

  // ... copy and move operations

  T& operator[](int i);
  const T& operator[](int i) const;
  int size() const {return sz;}
};

template<typename T>
Vector<T>::Vector(int s) {
  if (s < 0) throw 20;
  elem = new T[s];
  sz = s;
}

template<typename T>
const T& Vector<T>::operator[](int i) const {
  if (i < 0 || size() <= i)
    throw out_of_range{"Vector::operator[]"};
  return elem[i];
}

// To support the range-for loop, we must define suitable begin() and end() functions
template<typename T>
T *begin(Vector<T>& x) {return x.size() ? &x[0] : nullptr;}  // pointer to first element

template<typename T>
T *end(Vector<T>& x) {return begin(x) + x.size();}  // pointer to one-past-last element

void write(const Vector<string>& vs) {
  for (int i = 0; i != vs.size(); ++i)
    cout << vs[i] << endl;
  // for (auto& s: vs)
  //   cout << s << endl;
}

int main() {
  Vector<char> vc(200);
  Vector<string> vs(17);
  Vector<list<int>> vli(45);
  try {
    Vector<double> vd(-5);
  }
  catch (int n) {
    cout << "Error " << n << ": no support for the negative size" << endl;
  }

  cout << "vc.size() = " << vc.size() << endl;
  cout << "vs.size() = " << vs.size() << endl;
  cout << "vli.size() = " << vli.size() << endl;

  write(vs);
  return 0;
}
