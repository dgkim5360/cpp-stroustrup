```c++
#include <iostream>

class Container {
public:
  virtual double &operator[](int) = 0;
  virtual int size() const = 0;
  virtual ~Container() {}
}

void use(Container &c) {
  const int sz = c.size();

  for (int i = 0; i != sz; ++i)
    cout << c[i] << '\n';
}
```
At run time, use() exploits well the operator[] of derived class via virtual function table (vtbl) linking names of virtual functions to pointers to functions.
