#include"2-4-modularity-1-separate-compilation--Vector.h"  // get the interface

Vector::Vector(int s) :elem {new double[s]}, sz{s} {}

double& Vector::operator[](int i) {return elem[i];}

int Vector::size() {return sz;}
