Surprisingly often, it is useful to introduce a synonym for a type or a template. For example, the standard header `<cstddef>` contains a definition of the alias `size_t`, maybe:
```c++
using size_t = unsigned int;
```
The actual type named `size_t` is implementation-dependent, so in another implementation `size_t` may be an `unsigned long`. Having the alias `size_t` allows the programmer to write portable code.

```c++
template<typename T>
class Vector {
public:
  using value_type = T;
  // ...
}
```

In fact, every standard-library container provides value_type as the name of its value type. This allows us to write code that will work for every container that follows this convention.

```c++
template<typename C>
using Element_type = typename C::value_type;

template<typename Container>
void algo(Container& c) {
  Vector<Element_type<Container>> vec;  // keep results here
}
```

The aliasing mechanism can be used to define a new template by binding some or all template arguments.

```c++
template<typename Key, typename Value>
class Map {
  // ...
}

template<typename Value>
using String_map = Map<string, Value>;

String_map<int> m;  // m is a Map<string, int>
```
