#ifndef VECTOR_H
#define VECTOR_H
class Vector {
private:
  int _dim;
  int *_vector;
  void create(int);
public:
  Vector();
  Vector(const Vector &);
  ~Vector();
  explicit Vector(int dim);
  void set(const int *, int dim);
  void set_one(int index, int value);
  int dimension() const;
  int length() const;
  void print() const;
  Vector operator+(const Vector&) const;
  Vector operator-(const Vector&) const;
  Vector operator*(const Vector&) const;
};
#endif
