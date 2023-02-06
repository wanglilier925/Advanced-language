// Copyright 2022 CSCE 240 Lili wang
//

#include <hw5/inc/rational.h>
#ifndef HW5_INC_GRADE_H_
#define HW5_INC_GRADE_H_
#include <string>
#include <iomanip> 
#include <iostream>
#include <cmath>
namespace csce240{
namespace hw5{


// Grade class : Represents the outcome of a scored assignment consisting of scored
//               points of the assignment and total points of the assignment.
//               Grades are always non-negative. Grade extends Rational; Grade
//               objects are Rational Objects.
//
//  Example Usage:
//    Grade a(3, 6), b(4, 7);
//    Grade sum = a.Plus(b);  // calculate sum of a and b
//    Grade two(2, 1);
//    Grade avg = sum.DividedBy(two);  // calculate average of a and b

class Grade : public Rational
{
public:
  Grade();
  Grade(unsigned int scored, unsigned int total);

   unsigned int scored() const ;
   unsigned int total() const ;
   
  // constructor (unsigned int, unsigned int)
  //
  //  * Initializes instance with two integer parameters. First is points
  //    scored. Second is total points.
  //  * Precondition: first parameter is > -1, second is > 0. You may assert.

  // scored: accessor method for points scored
  //
  //  * Returns points scored as unsigned integer
  //  * Does not modify calling instance; const method


  // total: accessor method for total points possible
  //
  //  * Returns total points as unsigned integer
  //  * Does not modify calling instance; const method

  double ToDouble() const ;
  double ToDouble(unsigned int precision) const;
  

  // ToDouble: converts stored values into a precentage representing the
  //           percentage of scored points to total points.
  //
  //  * Accepts unsigned integer to set precision. The parameter represents the
  //    number of decimal places before rounding. For example, when parameter is
  //    3, 7/32 is returned as 21.875; when 2, 7/32 is returned as 21.88.
  //  * Returns floating point (double) approximation of the percentage of the
  //    total points earned.
  //  * Does not modify calling instance; const method.


  // error


  // double ToDouble(unsigned int precision=3);
  
  // ToDouble: as above, but OVERRIDES PARENT METHOD
  //
  //  * Precision is three (3)
  //  * Does not modify calling instance; const method.

  std::string ToString() const;
  // ToString: converts stored values into a printable format, e.g. 6/10
  //
  //  * Returns string containing s/p where s is the points scored and p is
  //    points possible. When s is 0, returns string 0/p, where p is total
  //    points possible.
  //  * Does not modify calling instance; const method.

  bool operator==(const Grade& rhs) const;
  // operator==: returns Boolean true or false depending on the equality of the
  //             ratio of the calling instance and the provided parameter, e.g.
  //             1/2 == 2/4 returns true, 1/2 == 1/4 returns false.
  //
  //  * Accepts an instance of Grade class. Parameter is used as the
  //    right-hand-side of the equation:
  //      calling instance == Grade parameter
  //  * Returns a boolean value which is true if the calling instance's ratio
  //    and Grade parameter's ratio are equal:
  //      scored:possible == scored:possible
  //    Ratios are calculated exactly---that is floating point values are not
  //    used, only integer values.
  //  * Does not modify calling instance; const method.

  bool operator==(int rhs) const;
  // operator==: As above, but accepts an int parameter as the right-hand-side
  //             operand, to allow calling object == int, e.g.
  //     Grade(2, 1) == 2



  private:
  unsigned int scored_;
  unsigned int total_;
};

  
// operator==: As class method above, but is a function and accepts an int
//             parameter as the left-hand-side operand and a Grade parameter
//             for the right-hand-side, e.g.
//    int == Grade object

  bool operator==(int lhs, const Grade& rhs);
} // namespace hw5
} // namespace csce240
#endif // HW5_INC_GRADE_H_

