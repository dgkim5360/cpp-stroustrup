#include<iostream>
using namespace std;
/* A template defined to accept an arbitrary number of arguments of arbitrary types
is called a variadic template.
*/
template<typename T>
void g(T x) {
  cout << x << ' ';
}

void f() {}  // do nothing

template<typename T, typename... Tail>
void f(T head, Tail... tail) {
  g(head);  // do something to head
  f(tail...);  // try again with tail (recursive call)
}

int main() {
  cout << "first try: ";
  f(1, 2.2, "hello");
  cout << endl;

  cout << "second try: ";
  f(0.2, 'c', "yuck!", 0, 1, 2);
  cout << endl;
  return 0;
}
/* The strength of variadic templates (sometimes just called variadics) is that
they can accept any arguments you care to give them. The weakness is that the type
checking of the interface is a possibly elaborate template program.
*/
