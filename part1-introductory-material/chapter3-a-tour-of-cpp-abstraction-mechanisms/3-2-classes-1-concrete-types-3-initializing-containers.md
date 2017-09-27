```c++
class Vector {
public:
  Vector(std::initializer_list<double>);  // initialize with a list
  // ...
  void push_back(double);  // add element at end increasing the size by one
}

Vector read(istream& is) {  // usage of push_back
  Vector v;
  for (double d; is >> d;)  // read floating-point values into d (d limited to the loop)
    v.push_back(d);  // add d to v
  return v;
}

// example of initializer-list constructor
Vector::Vector(std::initializer_list<double> lst)
  :elem {new double[lst.size()]}, sz {lst.size()}
{
  copy(lst.begin(), lst.end(), elem);  // copy from lst into elem
}
// usage
// Vector v1 = {1, 2, 3, 4, 5};
// Vector v2 = {1.23, 4.56, 6.7, 8};
```
