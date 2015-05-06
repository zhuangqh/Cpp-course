#include <cstdlib>
template<typename T> class Array {
 private:
    T _data[100];
    int _length;
 public:
    Array() : _length(0) {}
    // just set the _length is enough
    Array(int length) : _length(length) {}
    // copy constructor
    Array(const Array& src);


    int getLength();

    Array& operator=(const Array& src);
    // use like array[10], we can edit its value
    T& operator[](int index);

    // slice is a useful feature
    // e.g array => [1, 2, 3, 4, 5]
    // array.slice(0, 3, 1) => [1, 2, 3]
    // array,slice(2, 4, 1) => [3, 4, 5]
    // array.slice(0, 4, 2) => [1, 3, 5]
    // array.slice(0, 4, -1) => [5, 4, 3, 2, 1]
    Array slice(int start, int end, int step);
    // traverse means 遍历
    // basically, it walk throught all the element in array
    // and let them do one specific thing
    // void (*visit)(T &) is a function-pointer 函数指针
  void traverse(void (*visit)(T &));
};
template <typename T>
Array<T>::Array(const Array& src) {
  _length = src._length;
  for (int i = 0; i < _length; ++i)
    _data[i] = src._data[i];
}
template <typename T>
int Array<T>::getLength() {
  return _length;
}
template <typename T>
Array<T>& Array<T>::operator=(const Array& src) {
  _length = src._length;
  for (int i = 0; i < _length; ++i)
    _data[i] = src._data[i];
  return *this;
}
template <typename T>
T& Array<T>::operator[](int index) {
  return _data[index];
}
template <typename T>
Array<T> Array<T>::slice(int sta, int end, int step) {
  Array<T> ans;
  int count = 0;
  if (step > 0) {
    for (int i = sta; i <= end; i += step) {
      ans._data[count++] = _data[i];
    }
  } else {
    for (int i = end; i >= sta; i += step) {
      ans._data[count++] = _data[i];
    }
  }
  ans._length = count;
  return ans;
}
template <typename T>
void Array<T>::traverse(void (*visit)(T &)) {
  for (int i = 0; i < _length; ++i)
    visit(_data[i]);
}
