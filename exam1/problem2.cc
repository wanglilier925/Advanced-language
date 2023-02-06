/* copyright 2022 Lili Wang hw2 */
#include <exam1/problem2.h>
#include <iostream>
#include <string>
#include <cmath>
using namespace std;
using std::cin;
using std::cout;
using std::endl;

std::string SumDigits(const std::string& value){
	
    
	//
	for(int i = 0; i < value.length(); i++) {
	char ch = value.at(i);
	if( ch!='-'&& ch != '1' && ch != '2'&& ch != '3'&& ch != '4'&& ch != '5'&& ch != '6'&& ch != '7'&& ch != '8'&& ch != '9' && ch !='0')
		return "empty string";
	}



	//count numbers

	int number = stoi(value);
	int count = 0;

	int number1 =number;
	
	while(number1!= 0) {
	number1/=10;
	count++;
	}

	// extract numbers

int num;
int array[count];
int input1=abs(number);
int result = 0;
std::string result1;
std::string result2;

for(int i = 0; i < count ; i++) {
num = input1/(pow(10, count-i-1));

input1 = input1 % static_cast<int>(pow(10, count-i-1));//pow是double，static_cast<int>可以转换
array[i] = num;
result += array[i];
}
result1 = std::to_string(result);

if(number>0)
{
 result2 = result1;
}

else
 {result2 = "-" +result1;
}

return result2;
}
