#ifndef VECTOR_H
#define VECTOR_H
#include "Base.h"
class Vector : public Base {
 public:
  Vector() : Base() {}
  Vector(const Vector &other) : Base(other) {}
 Vector(int col) : Base(col) {}
  ~Vector() { clean(); }
  void set_one(int value, int pos_x, int pos_y);
  int length() const;
  void print() const;
  int get(int pos_x, int pos_y) const;
  Vector operator+(const Vector&) const;
  Vector operator-(const Vector&) const;
  Vector operator*(const Vector&) const;
};
#endif
