#include <list>
#include <vector>
#include "myAllocator.h"
#include <iostream>
int main() {
  typedef std::vector< int, new_allocator<int> > myVector;
  typedef std::list< int, new_allocator<int> > myList;
  myVector v;
  myList l;

  int n, t;
  std::cin >> n;
  for (int i = 0; i < n; ++i) {
    std::cin >> t;
    v.push_back(t);
    l.push_back(t);
  }

  myVector::iterator vi = v.begin();
  myList::iterator li = l.begin();
  ++vi;
  ++li;
  vi = v.insert(vi, 0);
  li = l.insert(li, 0);
  v.erase(++vi);
  l.erase(++li);
  for (vi = v.begin(); vi != v.end(); ++vi)
    std::cout << *vi << ' ';
  std::cout << std::endl;
  for (li = l.begin(); li != l.end(); ++li)
    std::cout << *li << ' ';
  std::cout << std::endl;
  return 0;
}
