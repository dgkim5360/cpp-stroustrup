The most basic use of these "smart pointers" is to prevent memory leaks caused by careless programming.
```c++
void f(int i, int j) {  // X* vs. unique_ptr<X>
  X* p = new X;  // allocate a new X
  unique_ptr<X> sp {new X};  // allocate a new X and give its pointer to unique_ptr
  // ...

  if (i < 99) throw Z {};  // may throw an exception
  if (j < 77) return;  // may return "early"
  p->do_something();  // may throw an exception
  sp->do_something();  // may throw an exception
  // ...

  delete p;  // destroy * p
}
```

Here, we "forgot" to delete `p` if `f()` throws or returns. On the other hand, `unique_ptr` ensures that its object is properly destroyed whichever way we exit `f()`.

Its further uses include passing free-store allocated objects in and out of functions.

```c++
unique_ptr<X> make_X(int j) {  // make an X and immediately give it to a unique_ptr
  // ... check i, etc ...
  return unique_ptr<X> {new X{i}};
}
```

A `unique_ptr` is a handle to an individual object (or an array) in much the same way that a `vector` is a handle to a sequence of objects. Both control the lifetime of other objects (using RAII) and both rely on move semantics to make return simple and efficient.

The `shared_ptr` is similar to unique_ptr except that `shared_ptr`s are copied rather than moved. The `shared_ptr`s for an object share ownership of an object and that object is destroyed when the last of its `shared_ptr`s is destroyed.

```c++
void f(shared_ptr<fstream>);
void g(shared_ptr<fstream>);

void user(const string& name, ios_base::openmode mode) {
  shared_ptr<fstream> fp {new fstream(name, mode)};
  if (!*fp) throw No_file {};  // make sure the file was preperly opened

  f(fp);
  g(fp);
  // ...
}
```

Now, the file opened by `fp`’s constructor will be closed by the last function to (explicitly or implicitly) destroy a copy of `fp`. Note that `f()` or `g()` may spawn a task holding a copy of `fp` or in some other way store a copy that outlives `user()` Thus, `shared_ptr` provides a form of garbage collection that respects the destructor-based resource management of the memory-managed objects. This is neither cost free nor exorbitantly expensive, but does make the lifetime of the shared object hard to predict. Use `shared_ptr` only if you actually need shared ownership.
