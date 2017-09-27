Copying can be constly for large containers.

```c++
Vector operator+(const Vector& a, const Vector& b) {
  if (a.size() != b.size())
    throw Vector_size_mismatch();

  Vector res(a.size());
  for (int i = 0; i != a.size(); ++i)
    res[i] = a[i] + b[i];
  return res;  // returning involves copying local variable res
}  // e.g., r = x + y + z causes copying at least twice
```

The move protocol resolves above copy-returning behavior.

```c++
class Vector {
  // ...
  Vector(const Vector& a);  // copy constructor
  Vector& operator=(const Vector& a);  // copy assignment

  Vector(Vector&& a);  // move constructor (not taking const argument)
  Vector& operator=(Vector&& a);  // move assignment
}  // r = x + y + z will involve no copying anymore

Vector::Vector(Vector&& a)  // && means "rvalue reference"
  :elem{a.elem},  // "grab the elements" from a
  sz{a.sz}
{
  a.elem = nullptr;  // now a has no elements
  a.sz = 0;
}
```

### lvalue <=> rvalue
"lvalue" roughly means "something that can appear on the left-hand side of an assignment". So "rvalue" is a value that you can't assign to (such as an integer returned by a function call), and "rvalue reference" is a reference to something that nobody else can assign to. (e.g., variable res) A move operation is applied when an rvalue reference is used as an initializer or as the right-hand side of an assignment.

```c++
Vector f() {
  Vector x(1000);
  Vector y(1000);
  Vector z(1000);
  // ...
  z = x;  // copying
  y = std::move(x);  // moving -- x.elem <- nullptr
  // ...
  return z;  // moving
}
```
