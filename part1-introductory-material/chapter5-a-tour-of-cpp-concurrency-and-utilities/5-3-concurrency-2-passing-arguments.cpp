#include<iostream>
#include<thread>
#include<vector>
using namespace std;

void f(vector<double>& v) {  // function do something with v
  for (double& d: v)
    cout << "From f: " << d << endl;
}

struct F {
  vector<double>& v;
  F(vector<double>& vv) : v{vv} {}
  void operator()() {  // application operator
    for (double& d: v)
      cout << "From F: " << d << endl;
  }
};

int main() {
  vector<double> some_vec {1,2,3,4,5,6,7,8,9};
  vector<double> vec2 {10,11,12,13,14};

  // https://stackoverflow.com/questions/28950835
  thread t1 {f, ref(some_vec)};  // f(some_vec) executes in a separate thread
  thread t2 {F{vec2}};  // F(vec2)() executes in a separate thread
  t1.join();
  t2.join();
  return 0;
}
/* Obviously, `F{vec2}` saves a reference to the argument vector in `F`. `F` can
now use that array and hopefully no other task accesses `vec2` while `F` is executing.
Passing `vec2` by value would eliminate that risk. */
