By defining constructors, copy operations, move operations, and a destructor, a programmer can provide complete control of the lifetime of a contained resource (such as the elements of a container). Furthermore, a move constructor allows an object to move simply and cheaply from one scope to another.

Consider:
1. a standard-library thread representing a concurrent activity (we can't copy this),
2. a Vector of a million doubles (we don’t want to copy this).

We can't copy the former and don't want to copy the latter.

```c++
std::vector<thread> my_threads;

Vector init(int n) {
  thread t {heartbeat};  // run heartbeat concurrently (on its own thread)
  my_threads.push_back(move(t))  // move t into my_threads
  // ...

  Vector vec(n);
  for (int i = 0; i < vec.size(); ++i)
    vec[i] = 777;
  return vec;  // move it out of init()
}

auto v = init(1000);  // start heartbeat and initialize v
```

This makes resource handles, such as Vector and thread, an alternative to using pointers in many cases. In fact, the standard-library "smart pointers", such as unique_ptr, are themselves resource handles.
