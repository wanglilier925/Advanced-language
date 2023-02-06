// Copyright 2022 CSCE 240 Lili wang
// hw5
#include <hw5/inc/rational.h>

#include <cstdlib>  // atoi
#include <iostream>
//#include <iomanip>
#include <cmath>
#include <string>

//using std::cout;
namespace csce240{
namespace hw5{

Rational::Rational() : num_(0), den_(1) { /* empty */ }

Rational::Rational(int num)
{
  num_ = num;
  den_ = 1;
}

Rational::Rational(int num, int den)
{
  
  if( den <0)
  {
    num_ = num*(-1);
    den_ = den*(-1);
  }

  else
  {
  num_ = num;
  den_ = den;
  }

}

signed int Rational::num() const
{
	return num_;
}

signed int Rational::den() const
{
  return den_;
}

double Rational::ToDouble() const
{
  double num = num_;
  double den = den_;
  double percentage = (num * 1.0) / (den / 1.0);

  return percentage;
}


std::string Rational::ToString() const
{
  if (num_== 0 )
  {
    return "0";
  }
  else 
  {
    std::string st = std::to_string (num_) + "/" + std::to_string (den_);
    return st;
  }
}

bool Rational::Equals(const Rational& rhs) const
{
  signed int x =  num_* rhs.den_;
  signed int y = den_* rhs.num_;
 
  if (x == y) 
  {
    return true;
  } 
  else
  {
    return false;
  }


}
 bool Rational::operator==(const Rational& rhs) const
 {

  return Equals(rhs);

 }
bool Rational::Equals(int rhs) const
{
  signed int x = den_;
  signed int y = num_;
  signed int z = y / x;
 
  if (z == rhs) 
  {
    return true;
  } 
  else
  {
    return false;
  }
}

bool Rational::operator==(int rhs) const
{
  return Equals(rhs);
}

const Rational Rational::DividedBy(const Rational& rhs) const
{
  signed int x = num_* rhs.den_;
  signed int y = rhs.num_ * den_;

  return Rational(x, y);

}
const Rational Rational::operator/(const Rational& rhs) const
{
  return DividedBy(rhs);

}

// err
const Rational Rational::DividedBy(int rhs) const
{
   signed int x = num_;
   signed int y = rhs* den_;

   return Rational(x, y);


}



const Rational Rational::operator/(int rhs) const
{
  

  return DividedBy(rhs);

}







const Rational Rational::Plus(const Rational& rhs) const
{
  signed int x = num_+ den_;
  signed int y = rhs.den_;
  return Rational(x, y);
}

const Rational Rational::operator+(const Rational& rhs) const
{
  return Plus(rhs);
}

const Rational Rational::Plus(int rhs) const
{
  signed int x = num_+den_*rhs;
  signed int y = den_;
  return Rational(x, y);
}
const Rational Rational::operator+(int rhs) const
{
  return Plus(rhs);
}

const bool operator==(int lhs, const Rational& rhs)
{
  return rhs.Equals(lhs);
}
const Rational operator/(int lhs, const Rational& rhs)
{
   
  Rational x = rhs.DividedBy(lhs);


   return Rational(x.den(), x.num());
}
const Rational operator+(int lhs, const Rational& rhs)
{
  return rhs.operator+(lhs);
}


} // namespace hw5
} // namespace csce240