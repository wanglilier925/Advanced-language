/* Copyright Lili Wang exam1 */

#include <exam1/problem3.h>  // test correct header constuction
#include <cassert>
#include <iostream>
#include <sstream>
#include <string>
#include <fstream>
#include <vector>
#include <iterator>



using namespace std;

double Max(const string& path){
	ifstream file;
	
	string str;
	
	file.open(path);
		
	int n = 0; // current line number
	vector<double> data; //store doubles
	while (getline(file, str))
	{
		double num = stod(str);
		if ( n > 0)              //from second line to store
		    data.push_back(num); // put num in the vedtor
		n++;
	};
	
	double max;

	for (int i =0; i< data.size(); i++)
	 {
    	if(data[i]> max)
    	{
    		max=data[i];
    	}
	}
	 file.close();
	return max;
	
}

//   Accepts string parameter as file name, returns double value representing
//   the largest value of the doubles in file
double Min(const string& path){

	ifstream file;
	
	string str;
	
		file.open(path);
	int n = 0; // current line number
	vector<double> data; //store doubles
	while (getline(file, str))
	{
		double num = stod(str);
		if ( n > 0) //from second line to store
		    data.push_back(num); // put num in the vedtor
		n++;
	}
	double min;
	for (int i =0; i< data.size(); i++) {
    	if(data[i] < min)
    	{
    		min=data[i];
    	}
	}
	file.close();
	return min;
}
//   Accepts string parameter as file name, returns double value representing
//   the smallest value of the doubles in file
double Sum(const string& path){
	// ifstream file("problem5_doubles.txt");
	ifstream file;
	string str;
		file.open(path);
	int n = 0; // current line number
	vector<double> data; //store doubles
	while (getline(file, str))
	{
		double num = stod(str);
		if ( n > 0) //from second line to store
		    data.push_back(num); // put num in the vedtor
		n++;
	}
	double sum=0.0;
	for (int i =0; i< data.size(); i++ ) {
    	sum+=data[i];
	}
	file.close();
	return sum;
}
//   Accepts string parameter as file name, returns double value representing
//   the sum of the values of the doubles in file
double Avg(const string& path){
	// ifstream file("problem5_doubles.txt");
	ifstream file;	
	string str;
		file.open(path);

	int n = 0; // current line number
	vector<double> data; //store doubles
	while (getline(file, str))
	{
		double num = stod(str);
		if ( n > 0) // from second line to store
		    data.push_back(num); // put num in the vedtor
		n++;
	}
	double sum=0.0;
	int avg1=0;
	double avg;
	int j=0;
	for (int i =0; i< data.size(); i++) {
    	sum+=data[i];
    	j+=1;
	}
	avg1=sum/j;
	avg=static_cast<double>(avg1);
	file.close();
	return avg;

}
//   Accepts string parameter as file name, returns floating point value
//   representing the sum of the values of the doubles in file
void Sort(const string& path, double array[]){

	ifstream file;	
	string str;
	file.open(path);
	int n = 0; // current line number
	while (getline(file, str))
	{
		double num = stod(str);
		if ( n > 0) //from second line to store
			array[n-1]= num;
		n++;
	}
	// bubble sort; desconding
	for (int i = 0; i < n-2; i++) {
		for (int j = 0; j < n-i-2; j++)
		{
			if(array[j]>array[j+1])
			{
				double temp = array[j+1];
				array[j+1]=array[j];
				array[j]=temp;
			}
		}   	
	}
	file.close();
	
}

