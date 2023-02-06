//  Copyright Lili Wang csce 240
//  CharMatrix Points:
//   Compiles: 0.5 (make test_char_matrix)
//   Style: 0.5 (make test-char-matrix-style)
//   TestFillConstructor: 1
//   TestCopyConstructor: 1
//   TestAssignOperator: 1
//   test-char-matrix-memory: 1 (make test-char-matrix-memory)

#ifndef EXAM3_INC_CHAR_MATRIX_H_
#define EXAM3_INC_CHAR_MATRIX_H_

#include <cassert>  // assert
#include <cstdlib>  // atoi
#include <iostream>


//  This is a small character matrix class to test your ability to manage
//   memory in a class. You must Implement a fill constructor, a copy
//   constructor, and assignment operator, and a destructor.
class CharMatrix {
 public:
  // implement default constructor, does not need to allocate memory
  CharMatrix() : matrix_(nullptr), rows_(0), cols_(0) { /* empty */ }

  // chars is a two-dimensional array with rows x cols cells
  CharMatrix(const char** chars, ::size_t rows, ::size_t cols);

  // implement me
  CharMatrix(const CharMatrix& that);

  // implement me
  ~CharMatrix();

  // implement me
  const CharMatrix& operator=(const CharMatrix& rhs);

  friend class CharMatrixTester;  // ignore me

 private:
  char **matrix_;  // you must use me
  ::size_t rows_;    // ^
  ::size_t cols_;    // ^^
};


#endif  // EXAM3_INC_CHAR_MATRIX_H_

