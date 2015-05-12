#Project Stage4
***
### What I have done
* Design a base class and let 'Matrix' and 'Vector' inherit from it
* Well managed constructor
* The general method of 'set', 'get' and 'print'
* The special method of 'any' and 'all'
* Operator overloading of +, -, *, () and stream overloading
* Three Matrix's methods: transpose, determinant, inverse
* Add three basic operation: find_pivot_from, swap_row, replace
* Exception Handling

### The organization of my files
* **Three .h file. The main.cpp shows the method of Class Matrix and Class Vector and Exception handling. **
* The program will show a menu for you to choose which part of my work to show.


### Notes
* Add two member function called 'create' and 'clean'.Function 'create' is used to apply for memory. Function 'clean' is used to free memory.
* Add a destructor to well manage the memory. 
* Change all the member function to const if they needn't to modify the member data.
* I don't think it is necessary to add pure virtual  function in my program.


    ####Three basic matrix operation
* find_pivot_from :  Given an index, find the first non-zero entry in this column, return the index of the row
* swap_row : Given two numbers of rows. If they are the same, do nothing, else swap all of the elements.
* replace : Given two numbers of rows and a constant. Add the opposite number of the product of the entry in row1 and the constant to the corresponding entry in row 2.


    ####Compute the determinant of matrix
1.  Use Gaussian Elimination reducing the matrix to its echelon form
2.  The determinant of the matrix equals to the product of the diagonal entries.


    ####Compute the inverse of matrix
1.  'Write' down two matrices, one is the original matrix, one is the identity matrix of the same numbers of row.
2.  Use Gaussian Elimination reducing the matrix to its echelon form. Do the same operation on the right matrix.
3.  Reduce the left matrix to identity form. Do the same operation on the right matrix. When the left matrix become its identity form, the right matrix is the answer.

    ####Exception Handling
* The detailed description about exceptions is written on 'Exceptions.txt'.

**You can get my source code from [here](https://github.com/zhuangqh/Cpp_homework/tree/master/project)**
