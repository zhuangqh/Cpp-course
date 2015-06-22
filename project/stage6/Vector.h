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
  template <unsigned N, unsigned M>
    Vector(const T (&keys)[N][M]) : Base<T>(keys) {}

  T length() const;
  int dimension() const;
  void hear(const std::string &, const Vector<T>&);

  template <typename S>
    friend std::ostream& operator<<(std::ostream&, const Vector<S>&);
  void setByFile(const char *filename, int len) {
    Base<T>::setByFile(filename, 1, len);
  }

  Vector<T> operator+(const Vector<T>&) const;
  Vector<T> operator-(const Vector<T>&) const;
  Vector<T> operator*(const Vector<T>&) const;
  T& operator()(int index);
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
std::ostream& operator<<(std::ostream& output, const Vector<T>& v) {
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
void Vector<T>::hear(const std::string &str, const Vector<T>& v) {
  if (str == "I love") *this = *this + v;
  if (str == "I hate") *this = *this - v;
}

template <typename T>
Vector<T> Vector<T>::operator+(const Vector<T>& other) const{
  if (other._col != Base<T>::_col)
    throw std::invalid_argument("The size of vector is not matched");

  Vector ans(Base<T>::_col);
  for (int i = 0; i < Base<T>::_col; ++i)
    ans._data[0][i] = other._data[0][i] + Base<T>::_data[0][i];
  return ans;
}

template <typename T>
Vector<T> Vector<T>::operator-(const Vector<T>& other) const {
  if (other._col != Base<T>::_col)
    throw std::invalid_argument("The size of vector is not matched");

  Vector<T> ans(Base<T>::_col);
  for (int i = 0; i < Base<T>::_col; ++i)
    ans._data[0][i] = other._data[0][i] - Base<T>::_data[0][i];
  return ans;
}

template<typename T>
Vector<T> Vector<T>::operator*(const Vector<T>& other) const {
  if (other._col != Base<T>::_col)
    throw std::invalid_argument("The size of vector is not matched");

  Vector<T> ans(1);
  for (int i = 0; i < Base<T>::_col; ++i)
    ans._data[0][0] += other._data[0][i] * Base<T>::_data[0][i];
  return ans;
}

template <typename T>
T& Vector<T>::operator()(int index) {
  return Base<T>::operator()(0, index);
}
#endif
