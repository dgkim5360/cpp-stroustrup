#include<iostream>
#include<thread>
#include<vector>
using namespace std;

void f(const vector<double>& v, double *res) {  // take input from v; place result in *res
  *res = 7;
}

class F {
public:
  F(const vector<double>& vv, double *p) : v{vv}, res{p} {}
  void operator()() {  // place result in *res
    *res = 77;
  }
private:
  const vector<double>& v;  // source of input
  double *res;  // target for output
};

int main() {
  vector<double> some_vec;
  vector<double> vec2;
  // ...

  double res1, res2;

  thread t1 {f, ref(some_vec), &res1};
  thread t2 {F{vec2, &res2}};
  t1.join();
  t2.join();

  cout << "Result from f: " << res1 << endl;
  cout << "Result from F: " << res2 << endl;
  return 0;
}
