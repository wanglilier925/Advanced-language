// Copyright 2022 CSCE 240 lili wang

#include <hw5/inc/grade.h>
#include <cstddef>  // size_t
#include <iostream> // std::cout, std::fixed
#include <cmath>
#include <string>
#include <iomanip> // setprecision

using namespace std;


namespace csce240 {
namespace hw5 {

Grade::Grade() : scored_(0), total_(1) { /* empty */}

Grade::Grade(unsigned int scored, unsigned int total) 
: Rational((scored), (total))

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
  double percentage = int((points *1000.0*100) / (total_points)) / 1000.0;

  return percentage;
}


double Grade::ToDouble(unsigned int precision) const
{
  
  double points = scored_;
  double total_points = total_;

 

  if(precision >=0)
  {
  
  double per = int(points * 100.0 *pow(10, precision)/ total_points) / pow(10,precision);

  
  return per;
}

  else 
  {
    double per = round((points *1000.0*100) / (total_points)) / 1000.0;

    return per;
  }

}


std::string Grade::ToString() const
{

  if (scored_ == 0 )
  {

    std::string st = "0/" + std::to_string (total_);
    return st;
  }
  else 
  {
    std::string st = std::to_string (scored_) + "/" + std::to_string (total_);
  return st;
  }

}

bool Grade::operator==(const Grade& rhs) const
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

 bool Grade::operator==(int rhs) const
 {

  unsigned int a = scored_ / total_;
 
  if (a == rhs)
    return true;
  return false;

 }

  bool operator==(int lhs, const Grade& rhs)
  {
    
  if (Grade(rhs).operator==(lhs))
    return true;
  return false;

  }

}  // namespace hw5
}  // namespace csce240