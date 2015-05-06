#ifndef FUCK_H
#define FUCK_H
#include <string>
using namespace std;
class Object {
 public:
  virtual int isme() { return 0; }
};
class Animal : public Object {
 public:
  virtual int isme() { return 1; }
};
class Dog : public Animal {
 public:
  int isme() { return 2; }
};
class Cat : public Animal {
 public:
  int isme() { return 3; }
};
class Vehicle : public Object {
 public:
  virtual int isme() { return 4; }
};
class Bus : public Vehicle {
 public:
  int isme() { return 5; }
};
class Car : public Vehicle {
 public:
  int isme() { return 6; }
};
string instanceOf(Object *obj) {
  if (obj == NULL) {
    return string("NULL");
  } else {
    int me = obj->isme();
    string id[7] = {"Object", "Animal", "Dog", "Cat",
                    "Vehicle", "Bus", "Car"};
    return id[me];
  }
}
#endif
