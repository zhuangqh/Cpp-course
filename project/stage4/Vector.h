#ifndef VECTOR_H
#define VECTOR_H
#include "Base.h"
#include <cmath>
template<typename T>
class Vector : public Base<T> {
 public:
  Vector() : Base<T>() {}
  Vector(const Vector<T> &other) : Base<T>(other) {}
  Vector(int col) : Base<T>(1, col) {}
  T length() const;
  int dimension() const;
  Vector<T> operator+(const Vector<T>&) const;
  Vector<T> operator-(const Vector<T>&) const;
  Vector<T> operator*(const Vector<T>&) const;
  template <typename S>
  friend ostream& operator<<(ostream&, const Vector<S>&);
};

template <typename T>
T Vector<T>::length() const{
  T length = 0;
  for (int i = 0; i < Base<T>::_col; ++i)
    length += Base<T>::_data[0][i] * Base<T>::_data[0][i];
  length = sqrt(length);
  return length;
}

template <typename T>
ostream& operator<<(ostream& output, const Vector<T>& v) {
  output << '(';
  for (int i = 0; i < v._col; ++i) {
    output << v._data[0][i];
    if (i != v._col - 1) output << ", ";
  }
  output << ")";
  return output;
}

template <typename T>
int Vector<T>::dimension() const {
  return Base<T>::_col;
}

template <typename T>
Vector<T> Vector<T>::operator+(const Vector<T>& other) const{
  if (other._col != Base<T>::_col)
    throw invalid_argument("The size of vector is not matched");

  Vector ans(Base<T>::_col);
  for (int i = 0; i < Base<T>::_col; ++i)
    ans._data[0][i] = other._data[0][i] + Base<T>::_data[0][i];
  return ans;
}

template <typename T>
Vector<T> Vector<T>::operator-(const Vector<T>& other) const {
  if (other._col != Base<T>::_col)
    throw invalid_argument("The size of vector is not matched");

  Vector<T> ans(Base<T>::_col);
  for (int i = 0; i < Base<T>::_col; ++i)
    ans._data[0][i] = other._data[0][i] - Base<T>::_data[0][i];
  return ans;
}

template<typename T>
Vector<T> Vector<T>::operator*(const Vector<T>& other) const {
  if (other._col != Base<T>::_col)
    throw invalid_argument("The size of vector is not matched");

  Vector<T> ans(1);
  for (int i = 0; i < Base<T>::_col; ++i)
    ans._data[0][0] += other._data[0][i] * Base<T>::_data[0][i];
  return ans;
}
#endif
