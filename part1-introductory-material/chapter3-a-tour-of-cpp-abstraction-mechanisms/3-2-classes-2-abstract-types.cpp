/**
complex and Vector are called concrete types because their representation is
part of their definition. In that, they resemble built-in types. In contrast,
an abstract type completely insulates a user from implementation details, by
decoupling the interface from the representation and give up genuine local variables.
*/
#include<iostream>
#include<list>
using namespace std;

// 3-2-classes-1-concrete-types-2-a-container.cpp
// 3-2-classes-1-concrete-types-3-initializing-containers.cpp
class Vector {
private:
  double *elem;  // elem points to an array of sz doubles
  int sz;
public:
  Vector(int s) :elem {new double[s]}, sz {s} {  // constructor: acquire resources
    for (int i = 0; i != s; ++i)
    elem[i] = 0;  // initialize elements
  }
  ~Vector() { delete[] elem; }  // destructor: release resources

  double& operator[](int i) { return elem[i]; }
  int size() const { return sz; }

  Vector(std::initializer_list<double>);  // initialize with a list
  void push_back(double);  // add element at end increasing the size by one
};

Vector::Vector(std::initializer_list<double> lst)
  :elem {new double[lst.size()]}, sz {lst.size()}
{
  copy(lst.begin(), lst.end(), elem);  // copy from lst into elem
}

// abstract version of Vector
class Container {
public:
  virtual double& operator[](int) = 0;  /* pure virtual function with "= 0"
  virtual means "may be redefined later".
  A class with a pure virtual function is called an abstract class. */
  virtual int size() const = 0;  // const member function
  virtual ~Container() {}  // destructor
};

/* usage of Container:
it uses Container interfaces in complete ignorance of implementation details.
*/
void use(Container& c) {
  const int sz = c.size();

  for (int i = 0; i != sz; ++i)
    cout << c[i] << '\n';
}

class Vector_container : public Container {  // it implements Container
  Vector v;
public:
  Vector_container(int s): v(s) {}  // Vector of s elements
  Vector_container(initializer_list<double> il) : v{il} {}
  ~Vector_container() {}  // this implicitly invokes the member destructor ~Vector()

  double& operator[](int i) { return v[i]; }
  int size() const { return v.size(); }
};

class List_container : public Container {
  list<double> ld;  // list of doubles
public:
  List_container() {}  // empty list
  List_container(initializer_list<double> il) : ld{il} {}
  ~List_container() {}

  double& operator[](int i);
  int size() const { return ld.size(); }
};

double& List_container::operator[](int i) {
  for (auto& x: ld) {
    if (i == 0)
      return x;
    --i;
  }
  throw out_of_range("List_container");
}

int main() {  // example usage of Vector_container and List_container
  Vector_container vc {10, 9, 8, 7, 6, 5, 4, 3, 2, 1};
  List_container lc = {1, 2, 3, 4, 5, 6, 7, 8, 9};

  use(vc);
  use(lc);
  return 0;
}
/*
use(Container&) has no idea if its argument is a Vector_container or a List_container
use() need not be recompiled if the implementation of List_container changes or
a brand-new class derived from Container is used.
*/
