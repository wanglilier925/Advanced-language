// Copyright 2022 CSCE 240 Exam 2 Lili Wang
#ifndef EXAM2_INC_TIME_SPAN_H_
#define EXAM2_INC_TIME_SPAN_H_

#include <istream>
#include <ostream>

// TimeSpan Points:
//   Compiles: 0.5 (make test-time-span)
//   Lints: 1.0  (make test-time-span-style)
//   TestPlusTimeSpan: 1.25
//   TestPlusInt: 1.25
//   TestPlusExtract: 1.0
//   TestPlusInsert: 1.0

// A measurement of time, representable as a number of hours, minutes, and
// seconds.
//
//  You must define the declared portions of the public interface without
//  change. You may add other useful methods or amend the header, as
//  necessary.
//
class TimeSpan {
 public:
  // represents no time
  TimeSpan();

  // represents a span covering the parameters
  TimeSpan(int hours, int minutes, int seconds);


  int hours() const ; // returns the whole hours in the span
  int minutes() const ;  // returns the whole minutes in the span
  int seconds() const ; // returns the seconds in the span


  // returns the sum of two TimeSpan instances

  const TimeSpan operator+(const TimeSpan& rhs) const;

  const TimeSpan operator+(int rhs) const;

  std::ostream& Extract(std::ostream* out) const;
  std::istream& Insert(std::istream* in);

  private:
    int hours_;
    int seconds_;
    int minutes_;

};

// returns the sum of a number of seconds as an int and a TimeSpan
const TimeSpan operator+(int lhs, const TimeSpan& rhs);

// extracts the TimeSpan as HH : MM : SS
std::istream& operator>>(std::istream& lhs, TimeSpan& rhs);

// inserts the TimeSpan from HH : MM : SS each being formatted as an int
std::ostream& operator<<(std::ostream& lhs, const TimeSpan& rhs);




#endif  // EXAM2_INC_TIME_SPAN_H_