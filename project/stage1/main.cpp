#include "Matrix.h"
#include "Vector.h"
#include <iostream>
using namespace std;
int main() {
  //show the method of class Matrix
  int C_2D_array[3][3] = {
    { 1, 2, 3 },
    { 4, 5, 6 },
    { 7, 8, 9 }
  };
  Matrix example;
  //method #1
  cout << "example is " << endl;
  example.set((const int **)C_2D_array, 3, 3);
  example.print();
  //method #2
  cout << "example is " << endl;
  example.set_one(0, 0, 0);
  example.print();
  cout << "after set index[0][0] to 0" << endl;
  //method #4
  int *row_col_message = example.size();
  cout << "The row of example is " << row_col_message[0] << endl
    << "The column of example is " << row_col_message[1] << endl;
  delete row_col_message;
  //method #5
  cout << "entry of row 1 col 1 is "  << example.get(1, 1) << endl;
  //method #6
  cout << "row 1 is " << endl;
  example.row(1).print();
  //method #7
  cout << "col 1 is " << endl;
  example.col(1).print();
  //method #8
  cout << "The maxinum entry of example is ";
  cout << example.max_entry() << endl;
  //method #9
  cout << "The mininum entry of example is ";
  cout << example.min_entry() << endl;
  //method #10
  cout << "example + example =" << endl;
  Matrix sum = example + example;
  sum.print();
  //method #11
  cout << "example - example =" << endl;
  Matrix substract = example - example;
  substract.print();
  //method #12
  cout << "example * example =" << endl;
  Matrix multiply = example * example;
  multiply.print();

  //show the method of class Vector;
  Vector vec;
  int C_2D_array2[3] = {1, 2, 3};
  //method #1
  cout << "vec is ";
  vec.set(C_2D_array2, 3);
  vec.print();
  //mrthod #2
  cout << "vec is ";
  vec.set_one(0, 0);
  vec.print();
  cout << "after set index 0 to 0" << endl;
  //method #3
  cout << "The dimension of vec is " << vec.dimension() << endl;
  //method #4
  cout << "The length of vec is " << vec.length() << endl;
  //method #5
  cout << "vec + vec = ";
  Vector sum2 = vec + vec;
  sum2.print();
  //method #6
  cout << "vec - vec = ";
  Vector substract2 = vec - vec;
  substract2.print();
  //method #7
  cout << "vec * vec = ";
  Vector multiply2(vec * vec);
  multiply2.print();
  return 0;
}
