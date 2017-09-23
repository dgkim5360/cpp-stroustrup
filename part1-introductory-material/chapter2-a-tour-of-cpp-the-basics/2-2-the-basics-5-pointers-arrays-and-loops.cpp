#include <iostream>
using namespace std;

void print() {
  int v[] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};

  for (auto x: v)
    cout << x << '\n';

  for (auto x: {10, 21, 32, 43, 54, 65})
    cout << x << '\n';
}

void increment() {
  int v[] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};

  for (auto &x: v)
    ++x;
  for (auto x: v)
    cout << x << ' ';
  cout << '\n';
}

// count the number of occurrences of x in p[]
// p is assumed to point to zero-terminated array of char (or to nothing)
int count_x(char *p, char x) {
  if (p == nullptr)
    return 0;
  int count = 0;

  for (; *p != 0; ++p)
    if (*p == x)
      ++count;
  return count;
}

int main() {
  print();
  increment();

  char hello[] = "hello world";
  int count = count_x(hello, 'l');
  cout << "In \"hello world\", 'l' occurs " << count << " times.\n";
  return 0;
}
