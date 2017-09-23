### Constants

```c++
const int dmv = 17;  // named constant
int var = 17;  // not a constant

constexpr double max1 = 1.4*square(dmv);  // OK if square(17) is a constant expression (evaluated by the compiler)
constexpr double max2 = 1.4*square(var);  // error: var is not a constant expression
const double max3 = 1.4*square(var);  // OK: may be evaluated at run time

double sum(const vector<double> &);  // sum will not modify its argument
vector<double> v {1.2, 3.4, 4.5};  // not a constant
const double s1 = sum(v);  // OK: evaluated at run time
constexpr double s2 = sum(v)  // error: sum(v) not constant expression

// definition for a function to be usable in constexpr (evaluated by the compiler)
constexpr double square(double x) { return x*x; }

double d = 1.2;
double sq = square(d);  // square behaves as non-constant-expression
```
