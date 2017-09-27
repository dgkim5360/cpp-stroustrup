#include<iostream>
#include<string>
#include<vector>
#include<list>
using namespace std;
/* The function object (sometimes called a functor) is used to define objects that
can be called like functions. */
template<typename T>
class Less_than {
  const T val;  // value to compare against
public:
  Less_than(const T& v) :val(v) {}
  bool operator()(const T& x) const {return x < val;}  // call operator
};

Less_than<int> lti(42);  // it will compare i to 42 using <
Less_than<string> lts("Backus");

// Such function objects are widely used as arguments to algorithms.
template<typename C, typename P>
int count(const C& c, P pred) {
  int cnt = 0;
  for (const auto& x: c)
    if (pred(x))
      ++cnt;
  return cnt;
}

// void f(const vector<int>& vec, const list<string>& lst, int x, const string& s) {
void f(const vector<int>& vec, int x) {
  cout << "the number of values less than " << x << ": "
       << count(vec, Less_than<int>{x}) << endl;
       //  << count(vec, [&](int a) {return a < x;}) << endl;  // alternative: lambda expression
       //  [&] captures all local names used by reference, c.f., [] captures nothing
  // cout << "the number of values less than " << s << ": "
  //      << count(lst, Less_than<string>{s}) << endl;
  //      << count(lst, [&s](const string& a) {return a < s;}) << endl;  // alternative: lambda expression
  //      [&s] captures only s by reference, c.f., [=s] captures s by value (copying it)
}

int main() {
  bool b1 = lti(10);
  bool b2 = lts("hello");

  cout << "10 < 42 ? " << b1 << endl;
  cout << "hello < Backus ? " << b2 << endl;

  vector<int> vec {1,2,3,4,5,6,7,8,9};
  f(vec, 8);
  return 0;
}
