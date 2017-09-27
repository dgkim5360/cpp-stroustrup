Using the default copy or move for a class in a hierarchy is typically a disaster: given only a pointer to a base, we simply don’t know what members the derived class has, so we can’t know how to copy them. So, the best thing to do is usually to delete the default copy and move operations, that is, to eliminate the default definitions of those two operations:

```c++
class Shape {
public:
  Shape(const Shape&) =delete;  // no copy operations
  Shape& operator=(const Shape&) =delete;

  Shape(Shape&&) =delete;  // no move operations
  Shape& operator=(Shape&&) =delete;

  ̃Shape();
  // ...
};
```

Now an attempt to copy a `Shape` will be caught by the compiler. If you need to copy an object in a class hierarchy, write some kind of clone function.

In this particular case, if you forgot to `delete` a copy or move operation, no harm is done. A move operation is not implicitly generated for a class where the user has explicitly declared a destructor. Furthermore, the generation of copy operations is deprecated in this case. This can be a good reason to explicitly define a destructor even where the compiler would have implicitly provided one.

A base class in a class hierarchy is just one example of an object we wouldn’t want to copy. A resource handle generally cannot be copied just by copying its members.

The `=delete` mechanism is general, that is, it can be used to suppress any operation.
