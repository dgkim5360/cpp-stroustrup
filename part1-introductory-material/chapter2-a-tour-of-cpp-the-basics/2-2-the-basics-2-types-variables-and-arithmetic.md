### meaningful conversions between basic types
```c++
double d = 2.2;
int i = 7;
d = d + i;
i = d*i;
```

### general {} form
```c++
double d1 = 2.3;
double d2 {2.3};

complex<double> z = 1;
complex<double> z2 {d1, d2};
complex<double> s3 = {1, 2};  // = is optional with { }

vector<int> v {1,2,3,4,5,6};
```
### the general {} form saves you from conversions that lose information
```c++
int i1 = 7.2;  // i1 becomes 7
int i2 {7.2};  // error: floating-point to integer conversion
int i3 = {7.2};  // the same error (= is redundant)
```

### auto
```c++
// here `=` is used since there is no type conversion involved that might
// cause problems
auto b = true;  // a bool
auto ch = 'x';  // a char
auto i = 123;  // an int
auto d = 1.2;  // a double
auto z = sqrt(y);  // z has the type of whatever sqrt(y) returns
```
