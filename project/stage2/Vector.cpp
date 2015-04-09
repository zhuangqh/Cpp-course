#include "Vector.h"
#include <iostream>
#include <cmath>
#include <iomanip>
using namespace std;
void Vector::create(int dim) {
  _dim = dim;
  _vector = new int[_dim];
  for (int i = 0; i < _dim; ++i)
    _vector[i] = 0;
}
Vector::Vector() {
  create(2);
}
Vector::Vector(const Vector &other) {
  create(other._dim);
  for (int i = 0; i < _dim; ++i)
    _vector[i] = other._vector[i];
}
Vector::Vector(int dim) {
  create(dim);
}
Vector::~Vector() {
  delete[]_vector;
}
void Vector::set(const int *C_array, int dim) {
  create(dim);
  for (int i = 0; i < _dim; ++i)
    _vector[i] = C_array[i];
}
void Vector::set_one(int index, int value) {
  if (index >= 0 && index < _dim)
    _vector[index] = value;
}
int Vector::dimension() const{
  return _dim;
}
int Vector::length() const{
  int length = 0;
  for (int i = 0; i < _dim; ++i)
    length += _vector[i] * _vector[i];
  length = sqrt(length);
  return length;
}
void Vector::print() const{
  cout << '(';
  for (int i = 0; i < _dim; ++i) {
    cout << _vector[i];
    if (i != _dim - 1) cout << ", ";
  }
  cout << ")\n";
}
Vector Vector::operator+(const Vector& other) const{
  Vector ans(_dim);
  for (int i = 0; i < _dim; ++i)
    ans._vector[i] = other._vector[i] + _vector[i];
  return ans;
}
Vector Vector::operator-(const Vector& other) const {
  Vector ans(_dim);
  for (int i = 0; i < _dim; ++i)
    ans._vector[i] = other._vector[i] - _vector[i];
  return ans;
}
Vector Vector::operator*(const Vector& other) const {
  Vector ans(1);
  for (int i = 0; i < _dim; ++i)
    ans._vector[0] += other._vector[i] * _vector[i];
  return ans;
}
