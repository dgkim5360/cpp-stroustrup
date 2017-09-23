#include "2-4-modularity-1-separate-compilation--Vector.h"
#include <cmath>
#include <iostream>
using namespace std;

double sqrt_sum(Vector &v) {
  double sum = 0;
  for (int i = 0; i != v.size(); ++i)
    sum += sqrt(v[i]);  // sum of square roots
  return sum;
}

double read_and_sum(int s) {
  Vector v(s);  // make a vector of s elements
  for (int i = 0; i != v.size(); ++i)
    cin >> v[i];  // read into elements

  return sqrt_sum(v);
}

int main() {
  cout << "Insert numbers you want to sqrt_sum:" << '\n';
  int sum = read_and_sum(10);
  cout << "The sqrt_sum is " << sum << "\n";
  return 0;
}
