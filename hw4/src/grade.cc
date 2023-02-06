// Copyright 2022 CSCE 240 lili wang
#include <hw4/inc/grade.h>
#include <cstddef>  // size_t
#include <iostream>
#include <cmath>
#include <string>
#include <iomanip>

using std::cout;

Grade::Grade() : scored_(0), total_(1) { /* empty */}

Grade::Grade(unsigned int scored, unsigned int total)
{
	scored_ = scored;
  total_ = total;
}

unsigned int Grade::scored() const 
{
    return scored_;
}

unsigned int Grade::total() const
{
    return total_;
}

double Grade::ToDouble() const
{
  double points = scored_;
  double total_points = total_;
  double percentage = (int)ceil((points / total_points * 1000.0 * 100.0 )) / 1000.0 ;

  return percentage;
}

double Grade::ToDouble(unsigned int precision) const
{

  double points = scored_;
  double total_points = total_;
  double percentage = (int)ceil((points * 100 *100 / total_points)) /100.0;
  std::cout << std::fixed;
  std::cout << std::setprecision(precision);

  return percentage;
}

std::string Grade::ToString() const
{

  if (scored_ == 0 )
  {
    return "0";
  }
  else 
  {
    std::string st = std::to_string (scored_) + "/" + std::to_string (total_);
  return st;
  }

}

std::string Grade::ToLetter() const
{

  double grade_percent = static_cast<double>(scored_ * 100) / (double)(total_* 1.0);
  if (grade_percent >= 90.0) 
  {
  return "A";
  } 
  else if (grade_percent >= 80.0 && grade_percent < 90.0) 
  {
  return "B";
  } 
  else if (grade_percent >= 70.0 && grade_percent < 80.0) 
  {
  return "C";
  } 
  else if (grade_percent >= 60 && grade_percent < 70.0) 
  {
  return "D";
  } 
  else 
  {
  return "F";
  }


}
std::string Grade::ToLetter(unsigned int range) const
{
  double grade_percent = static_cast<double>(scored_ * 100) / (double)(total_ * 1.0);
  if (grade_percent >= 97.5) 
  {
  return "A+";
  } 
  else if (grade_percent < 97.5 && grade_percent >= 90.0)
  {
  return "A";
  } 
  else if (grade_percent < 90.0 && grade_percent >= 87.5) 
  {
  return "B+";
  } 
  else if (grade_percent < 87.5 && grade_percent >=80.0)
  {
  return "B";
  } 
  else if (grade_percent < 80 && grade_percent >= 77.5)
  {
  return "C+";
  } 
  else if (grade_percent < 77.5 && grade_percent >= 70.0)
  {
  return "C";
  } 
  else if (grade_percent< 70 && grade_percent >= 67.5)
  {
  return "D+";
  } 
  else if (grade_percent< 67.5 && grade_percent >= 60.0)
  {
  return "D";
  } 
  else 
  {
  return "F";
  }


} 

 bool Grade::Equals(const Grade& rhs) const
 {
  unsigned int x = scored_ * rhs.total_;
  unsigned int y = total_ * rhs.scored_;
 
  if (x == y) 
  {
    return true;
  } 
  else
  {
    return false;
  }

 }

Grade Grade::DividedBy(const Grade& rhs)const
 {

  unsigned int x = scored_ * rhs.total_;
  unsigned int y = rhs.scored_ * total_;

  return Grade(x, y);

 }

 Grade Grade::Plus(const Grade& rhs) const 
 {
  
  unsigned int x = scored_ * rhs.total_+ rhs.scored_ * total_;
  unsigned int y = total_ * rhs.total_;
  return Grade(x, y);
  
 }



