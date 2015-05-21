#ifndef MYALLOCATOR_H
#define MYALLOCATOR_H
#include <memory>
template <typename T>
class new_allocator : public std::allocator<T> {
 public:
  typedef std::allocator<T> Base;
  int * allocate(std::size_t size) {
    return Base::allocate(size);
  }
  void deallocate(int * p, std::size_t size) {
    Base::deallocate(p, size);
  }
  void construct(int * p, int val) {
    Base::construct(p, val);
  }
  void destory(int * p) {
    Base::destroy(p);
  }
};
#endif
