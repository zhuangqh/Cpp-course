#ifndef MYVECTOR_H
#define MYVECTOR_H
#include <iostream>
#include "test.h"
using namespace std;
template <typename T, typename A>
class myVector {
 public:
  typedef T* iterator;
  typedef const T* const_iterator;
 private:
  iterator start;
  iterator finish;
  iterator end_of_store;
  A Alloc;
 public:
  iterator begin() {return start;}
  const_iterator begin() const {return start;}
  iterator end() {return finish;}
  const_iterator end() const {return finish;}
  myVector();
  myVector(const size_t&, const T&);
  template <typename InputIterator>
  myVector(InputIterator, InputIterator);
  myVector(const myVector&);
  ~myVector();
  myVector& operator=(const myVector&);

  size_t size() const {return finish - start;}
  void resize(const size_t&);
  void resize(const size_t&, const T&);
  size_t capacity() const {return end_of_store - start;}
  bool empty() const {return start == finish;}
  void reserve(const size_t&);

  T& operator[](const size_t& n) {return *(start + n);}
  const T& operator[](const size_t& n) const {return *(start + n);}
  T& front() {return *start;}
  const T& front() const {return *start;}
  T& back() {return *(finish - 1);}
  const T& back() const {return *(finish - 1);}
  T* data() {return start;}
  const T* data() const {return start;}

  template <typename InputIterator>
  void assign(InputIterator, InputIterator);
  void push_back(const size_t, const T&) {}
  void pop_back() {}
  void clear();
};
template <typename T, typename A>
myVector<T, A>::myVector() {
  start = Alloc.allocate(1);
  finish = start;
  end_of_store = start + 1;
}
template <typename T, typename A>
myVector<T, A>::myVector(const size_t& n, const T& value) {
  start = Alloc.allocate(n);
  finish = start + n;
  end_of_store = finish;
  for (size_t i = 0; i < n; ++i) {
    Alloc.construct(start + i, value);
  }
}
template <typename T, typename A>
template <typename InputIterator>
myVector<T, A>::myVector(InputIterator beg, InputIterator ed) {
  size_t n = ed - beg;
  start = Alloc.allocate(n);
  finish = start + n;
  end_of_store = finish;
  for (size_t i = 0; beg != ed; ++i) {
    Alloc.construct(start + i, *beg);
    ++beg;
  }
}
template <typename T, typename A>
myVector<T, A>::myVector(const myVector& other) {
  size_t n = other.finish - other.start;
  start = Alloc.allocate(n);
  finish = start + n;
  end_of_store = finish;
  iterator p = other.start;
  for (size_t i = 0; p != other.finish; ++i) {
    Alloc.construct(start + i, *p);
    ++p;
  }
}
template <typename T, typename A>
myVector<T, A>::~myVector() {
  clear();
  Alloc.deallocate(start, capacity());
}
template <typename T, typename A>
myVector<T, A>& myVector<T, A>::operator=(const myVector& other) {
  if (other.start == start) return *this;
  size_t oldsize = size();
  Alloc.deallocate(start, oldsize);
  iterator tmp = Alloc.allocate(other.size());
  iterator p = other.start;
  for (size_t i = 0; p != other.finish; ++i) {
    Alloc.construct(tmp + i, *p);
    ++p;
  }
  start = tmp;
  finish = other.size() + tmp;
  end_of_store = finish;
  return *this;
}
template <typename T, typename A>
void myVector<T, A>::resize(const size_t& n, const T& value) {
  if (n < size()) {
    for (iterator p = start + n; p != finish; ++p) {
      Alloc.destory(p);
    }
    finish = start + n;
  } else {
    size_t _size = size();
    reserve(n);
    for (size_t i = _size; i != n; ++i)
      Alloc.construct(start + i, value);
    finish = start + n;
  }
}
template <typename T, typename A>
void myVector<T, A>::resize(const size_t& n) {
  if (n < size()) {
    for (iterator p = start + n; p != finish; ++p) {
      Alloc.destory(p);
    }
    finish = start + n;
  } else {
    reserve(n);
    finish = start + n;
  }
}
template <typename T, typename A>
void myVector<T, A>::reserve(const size_t& n) {
  if (n < size()) return;
  size_t oldsize = size();;
  iterator p = Alloc.allocate(n);
  for (size_t i = 0; i < oldsize; ++i) {
    Alloc.construct(p + i, start[i]);
    Alloc.destory(start + i);
  }
  Alloc.deallocate(start, oldsize);
  start = p;
  finish = p + oldsize;
  end_of_store = start + n;
}
template <typename T, typename A>
template <typename InputIterator>
void myVector<T, A>::assign(InputIterator beg, InputIterator ed) {
  clear();
  finish = start + (ed - beg);
  for (size_t i = 0; beg != ed; ++beg, ++i) {
    Alloc.construct(start + i, *beg);
  }
}
template <typename T, typename A>
void myVector<T, A>::clear() {
  for (iterator p = start; p != finish; ++p)
    Alloc.destory(p);
  finish = start;
}
#endif
