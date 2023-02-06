/*  copyright 2022 Lili Wang hw2*/

#include<hw2/parse_scores.h>
#include <iostream>
#include <string>
#include <stdexcept>   // std::invalid_argument
#include <cstdlib>
#include <array>

using std::stoi;
using std::stod;
using std::string;

double GetGrade(size_t grade_index, const std::string input[], size_t size)
{
	try{
		// get the number of grades
		int indexbuffer = static_cast<int>(size);
        int num = std::stoi(input[1]);
        // check grade_index
        // first index input 0 and the largest index = indexbuffer-3
        int size_max=indexbuffer-3;
        if (grade_index < 0 || grade_index > size_max)
                        return -2;
        // check grade size is correct or not
        if (num != indexbuffer-2)
            { 
            	return -1;
            }
        // check 
        for (int i = 2 ; i < indexbuffer ; i++)
         {
                if (std::stod(input[i]) < 0)
                        return -1;
        }
        // get the grade
        double Grade = std::stod(input[grade_index+2]);
        return Grade;
    }catch (const std::invalid_argument& exception) {
        return -1;
}
return 0;
}



std::string GetID(const std::string input[], size_t size){
 // get_ID
	int index = 0; 
	int indexbuffer = static_cast<int>(size);
	// check size is positive
	
	// else return "";// index =1

	std::string ID = input[index]; // " aname "

	if(index < indexbuffer) 
		index++; 

	// int get_num_grades = std::stoi(input[index]);
	if(indexbuffer < 1+ index)
		return "";
	else return ID;
}

int GetGradeCount(const std::string input[], size_t size){
	try
	{

	int indexbuffer = static_cast<int>(size);

    int num = std::stoi(input[1]);// get num

	if (num != indexbuffer-2) // check num
            { 
            	return -1;
            }
     
	// check 
    for (int i = 2 ; i < indexbuffer ; i++)
        {
            if (std::stod(input[i]) < 0)
                    return -1;
        }
     return num;
     }catch (const std::invalid_argument& exception) {
        return -1;
}
return 0;

}
double GetMaxGrade(const std::string input[], const size_t kSize){
	try{
	// convert size to int 
	int indexbuffer = static_cast<int>(kSize); // indexbuffer = 6

	// check number is positive or not
	int num = std::stoi(input[1]); // num_grades = 4
	if(num != indexbuffer-2 )
	{
		return -1.0;
	}
	if(num == 0)
		return -2.0;

	// check format of each grade
 
	double Max=0.0;
	for(int i = 2 ; i < indexbuffer; i++)
	{
		if(Max<std::stod(input[i]))
			Max=std::stod(input[i]);
		if(std::stod(input[i])<0)
			return -1.0;
	}
	return Max;
	}catch (const std::invalid_argument& exception) {
        return -1;
}
return 0;
	
  	}

 

