/* copyright 2022
 hw1
 Lili Wang
 */
#include <iostream>
#include <cmath>
#include <string>
#include <sstream>
using namespace std;

int main(int argc, char* argv[]) {
int input;
//input a number;
cin >> input;

// while loop to calculate how many digits

int count = 0;
int number=input;
while(number != 0) {
number/=10;
count++;
}

// for loop to extract each digits

int num;
int array[count];
int input1=abs(input);

for(int i = 0; i < count ; i++) {
num = input1/(pow(10, count-i-1));
input1 = input1 % static_cast<int>(pow(10, count-i-1));//pow是double，static_cast<int>可以转换
array[i] = num * (pow(10, count-i-1));
}

//print result
string result;
string result1;
string result2;

for(int i = 0; i < count-1; i++) {   
  result += to_string(array[i])+" + ";
  //result +=(array[i])+" + ";
  //cout << array[i] << " + ";
} 
 result1=result+to_string(array[count-1]);


if(input>0)
{
 result2=result1;
}


else
 {result2= "-(" +result1 + ")";
}


//cout<<result1;

cout<<result2;

return 0;
}

