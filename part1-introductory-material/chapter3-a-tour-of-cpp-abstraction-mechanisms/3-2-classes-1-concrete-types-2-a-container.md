A container is an object holding a collection of elements, so we call Vector a container because it is the type of objects that are containers.

The constructor/destructor combination is the basis of many elegant techniques.

```c++
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

  double& operator[](int i);
  int size() const;
};

void fct(int n) {
  Vector v(n);
  // ... use v ...
  {
    Vector v2(2*n);
    // use v and v2 ...
  }  // v2 is destroyed here
  // ... use v ...
  return 0;
}  // v is destroyed here
```
