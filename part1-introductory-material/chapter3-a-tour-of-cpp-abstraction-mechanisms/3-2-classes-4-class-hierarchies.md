```c++
using namespace std;

class Shape {
public:
  // pure virtual
  virtual Point center() const = 0;
  virtual void move(Point to) = 0;

  virtual void draw() const = 0;  // draw on current "Canvas"
  virtual void rotate(int angle) = 0;

  virtual ~Shape() {}  // destructor
  // ...
}

void rotate_all(vector<Shape *> &v, int angle) {  // rotate all v's elements
  for (auto p: v)
    p->rotate(angle);
}

class Circle :public Shape {
public:
  Circle(Point p, int rr);  // constructor

  Point center() const { return x; }
  void move(Point to) { x = to; }

  void draw() const;
  void rotate(int) {}  // nice simple algorithm
private:
  Point x;  // center
  int r;  // radius
}

class Smiley :public Circle {
public:
  Smiley(Point p, int r) : Circle {p, r}, mouth {nullptr} {}
  ~Smiley() {
    delete mouth;
    for (auto p: eyes) delete p;
  }

  void move(Point to);

  void draw() const;
  void rotate(int);

  void add_eye(Shape *s) { eyes.push_back(s); }
  void set_mouth(Shape*s);
  virtual void wink(int i);  // wink eye number i

  // ...
private:
  vector<Shape *> eyes;  // usually two eyes
  Shape *mouth;
}

void Smiley::draw() {
  Circle::draw();
  for (auto p: eyes)
    p->draw();
  mouth->draw();
}  // it is our task to place the eyes and mouth appropriately within the circle
```

Concrete classes – especially classes with small representations – are much like built-in types: we define them as local variables, access them using their names, copy them around, etc. Classes in class hierarchies are different: we tend to allocate them on the free store using new, and we access them through pointers or references.

```c++
enum class Kind { circle, triangle, smiley };

Shape *read_shape(istream &is) {  // read shape descriptions from input stream
  // ... read shape header from is and find its Kind k ...
  switch (k) {
    case Kind::circle:
      // read circle data {Point, int} into p and r
      return new Circle {p, r};
    case Kind::triangle:
      // read triangle data {P, P, P} into p1, p2, p3
      return new Triangle {p1, p2, p3};
    case Kind::smiley:
      // read smiley data {Point, int, Shape, Shape, Shape} into p, r, e1, e2, m
      Smiley *ps = new Smiley {p, r};
      ps->add_eye(e1);
      ps->add_eye(e2);
      ps->set_mouth(m);
      return ps;
  }
}

void user() {
  vector<Shape *> v;

  while (cin)
    v.push_back(read_shape(cin));
  draw_all(v);  // call draw() for each element
  rotate_all(v, 45);
  for (auto p: v) delete p;  /* user's responsibility to deallocate because
  there are no pointers to the shapes outside user().
  In this case, a Smiley deletes its eyes and mouth objects. */
}  // user() has absolutely no idea of which kinds of shapes it manipulates.
```

Functions returning a pointer to an object allocated on the free store are dangerous. `std::unique_ptr` resolves this issue.

```c++
unique_ptr<Shape> read_shape(istream &is) {
  // ...
  switch (k) {
    // ...
    case Kind::circle:
      return unique_ptr<Shape> {new Circle {p, r}};
    // ...
  }
}

void user() {
  vector<unique_ptr<Shape>> v;
  while (cin)
    v.push_back(read_shape(cin));
  draw_all(v);
  rotate_all(v, 45);
}  // all Shapes implicitly destroyed, since their unique_ptr goes out of scope
```
