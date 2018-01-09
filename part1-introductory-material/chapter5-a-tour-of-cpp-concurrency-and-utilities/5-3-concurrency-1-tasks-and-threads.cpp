#include<iostream>
#include<thread>
using namespace std;
/* We call a computation that can potentially be executed concurrently with other
computations a task. A thread is the system-level representation of a task in a
program.*/
void f() {  // task is a function
  cout << "hello para";
}

struct F {  // task is a function object
  void operator()() {  // F's call operator
    cout << " parallel world!";
  };
};

int main() {
  thread t1 {f};  // f() executes in separate thread
  thread t2 {F()};  // F()() executes in separate thread

  t1.join();  // wait for t1
  t2.join();  // wait for t2
  cout << endl;
  return 0;
}
/* This is an example of a bad error: Here, `f` and `F()` each use the object
`cout` without any form of synchronization. The resulting output would be unpredictable
and could vary between different executions of the program because the order of
execution of the individual operations in the two tasks is not defined. The program
may produce "odd" output, such as `PaHerallllel o World!` (But not my case :()
*/
