```c++
#include<iostream>
#include<thread>
#include<mutex>
#include<vector>
using namespace std;

mutex m;  // controlling mutex (mutual exclusion object)
int sh;  // shared data

void f() {
  unique_lock<mutex> lck {m};  // acquire mutex
  sh += 7;  // manipulate shared data
  // release mutex implicitly (RAII)
}
```
The `unique_lock`’s constructor acquires the mutex (through a call `m.lock()`). If another thread has already acquired the mutex, the thread waits ("blocks") until the other thread completes its access. Once a thread has completed its access to the shared data, the `unique_lock` releases the mutex (with a call `m.unlock()`).

It is not uncommon to need to simultaneously access several resources to perform some action. This can lead to deadlock. For example, if `thread1` acquires `mutex1` and then tries to acquire `mutex2` while `thread2` acquires `mutex2` and then tries to acquire `mutex1`, then neither task will ever proceed further. The standard library offers help in the form of an operation for acquiring several locks simultaneously:

```c++
void f() {
  // ...
  unique_lock<mutex> lck1 {m1, defer_lock};  // defer_lock: don't yet try to acquire the mutex
  unique_lock<mutex> lck2 {m2, defer_lock};
  unique_lock<mutex> lck3 {m3, defer_lock};
  // ...
  lock(lck1, lck2, lck3);  // acquire all three locks
  // ... manipulate shared data ...
}  // implicitly release all mutexes
```

This `lock()` will only proceed after acquiring all its mutex arguments and will never block ("go to sleep") while holding a `mutex`. The destructors for the individual `unique_lock`s ensure that the `mutex`es are released when a thread leaves the scope.

Communicating through shared data is pretty low level. In particular, the programmer has to devise ways of knowing what work has and has not been done by various tasks. In that regard, use of shared data is inferior to the notion of call and return. On the other hand, some people are convinced that sharing must be more efficient than copying arguments and returns. That can indeed be so when large amounts of data are involved, but locking and unlocking are relatively expensive operations. On the other hand, modern machines are very good at copying data, especially compact data, such as vector elements. So don’t choose shared data for communication because of "efficiency" without thought and preferably not without measurement.

### 5.3.4.1. Waiting for Events
The basic support for communicating using external events is provided by `condition_variable`s found in `<condition_variable>`. A `condition_variable` is a mechanism allowing one thread to wait for another. In particular, it allows a thread to wait for some *condition* (often called an event) to occur as the result of work done by other `thread`s.

```c++
class Message {  // object to be communicated
  // ...
}

queue<Message> mqueue;  // the queue of messages
condition_variable mcond;  // the variable communicating events
mutex mmutex;  // the locking mechanism

void consummer() {
  while (true) {
    unique_lock<mutex> lck {mmutex};  // acquire mmutex
    while (mcond.wait(lck)) ;  // release lck and wait
    // re-acquire lck upon wakeup
    auto m = mqueue.front();  // get the message
    mqueue.pop();
    lck.unlock();  // release lck
    // ... process m ...
  }
}

void producer() {
  while (true) {
    Message m;
    // ... fill the message ...
    unique_lock<mutex> lck {mmutex};  // protect operations
    mqueue.push(m);
    mcond.notify_one();  // notify
  }  // release lock (at the end of scope)
}
```
