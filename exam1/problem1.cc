/*  copyright 2022 
 	Lili Wang 
 	exam1
 */
#pragma GCC diagnostic ignored "-Wmultichar"
#include <iostream>
#include <cmath>
#include <string>
#include <stdio.h>
#include <iomanip>
using std::cin;
using std::cout;
using std::string;

int main() {
	double x;
	double y;
	std::string oper;

	std::cin >> x ;
	std::cin >> oper;
	std::cin >> y;

	if(oper == "<")
	{
		if(x<y)
			std::cout << "true";
		else std::cout << "false";
	}
			
	if(oper == "<="){
		if(x<=y)
			std::cout << "true";
		else std::cout << "false";
	}
			
	if(oper == "=="){
		if(x==y)
			std::cout << "true";
		else std::cout << "false";
	}	
			
	if(oper == ">=")
	{
		if(x>=y)
			std::cout << "true";
		else std::cout << "false";
	}
			
	if(oper == ">")
	{
		if(x>y)
			std::cout << "true";
		else std::cout << "false";
	}
			
	if(oper == "!=")
	{ 	
		if(x!=y)
			std::cout << "true";
		else std::cout << "false";
	}
	
 return 0;
					
}






//     Using the operands and operators and conditional statement(s) perform
//     the operation. Emit the string "true" or "false" as necessary.
//
//     DO NOT emit anything other than the result. This is a calculator. Simply
//     emit the result of the operation. Do not prompt for input. Just write the
//     result of the operation to STDOUT using std::cout.
//
//   
// Notes:
//   The two operands should be read as floating point data and the operator
//   can be read as an std::string. You need not set precision for the floating
//   point (in)equality operators. The default precision for a double is all
//   that is required.
//
// Points:
//  compilation: 1
//  style: 1
//  correctness: 2
//
