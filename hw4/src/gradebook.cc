// copyright 2022 240 Lili wang


#include <hw4/inc/gradebook.h>
#include <cstddef> // using size_t

#include <vector>

#include <cmath>
using std::vector;



GradeBook::GradeBook()
{

}

const size_t GradeBook::size() const 
{
    return grades.size();
}

const Grade GradeBook::Get(unsigned int index) const
{
  return grades[index];
}

void GradeBook::Add(Grade item)
{
  grades.push_back(item);
}

const GradeBook GradeBook::Add(const GradeBook& bl) const
{
  GradeBook CPD;

  for( int i=0; i< grades.size(); i++)
  {
    CPD.grades.push_back(grades[i]);
  }

  for( int i=0; i< bl.size(); i++)
  {
    CPD.grades.push_back(bl.Get(i));
  }

	return CPD;

}

const Grade GradeBook::CalcAverage() const
{
	unsigned int sum = 0;
	unsigned int sumTotal = 0;
  for( int i=0; i< grades.size(); i++)
   {
    sum += grades[i].scored();
    sumTotal += grades[i].total();

   }

   return Grade(sum, sumTotal);






}