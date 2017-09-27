By default, copy means memberwise copy.

```c++
void test(complex z1) {
  complex z2 {z1};  // copy initialization
  complex z3;
  z3 = z3;  // copy assignment
}  // they all have the same values
```

When a class is a resource handle, the default memberwise copy is a disaster,
because it violates its invariant. (See the figure in the textbook)

```c++
void bad_copy(Vector v1) {
  Vector v2 = v1;  // copy v1's representations into v2
  v1[0] = 2;  // v2[0] is now also 2
  v2[1] = 3;  // v1[1] is not also 3
}
```

Two steps to define copying of an object:
1. a copy constructor,
2. a copy assignment.

```c++
class Vector {
private:
  double *elem;
  int sz;
public:
  Vector(int s);  // constructor: establish invariant, acquire resources
  ~Vector() { delete[] elem; }  // destructor: release resources

  Vector(const Vector &a);  // copy constructor
  Vector &operator=(const Vector &a);  // copy assignment

  double &operator[](int i);
  const double &operator[](int i) const;

  int size() const;
}

Vector::Vector(const Vector &a)
  :elem{new double[a.sz]}, sz{a.sz}  // copy constructor
{
  for (int i = 0; i != sz; ++i)  // copy elements
    elem[i] = a.elem[i];
}

Vector &Vector::operator=(const Vector &a) {  // copy assignment
  double *p = new double[a.sz];

  for (int i = 0; i != a.sz; ++i)
    p[i] = a.elem[i];
  delete[] elem;  // delete old elements
  elem = p;
  sz = a.sz;
  return *this;  // this points to the object whose member function called
}
```
