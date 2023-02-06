// Copyright 2022 CSCE 240 Exam 2 Lili Wang


#include <exam2/inc/time_span.h>
#include <istream>
#include <ostream>


// default
TimeSpan::TimeSpan() : hours_(0), minutes_(0), seconds_(0){ /* empty */ }

 // paremeter
TimeSpan::TimeSpan(int hours, int minutes, int seconds) : hours_(hours), minutes_(minutes), seconds_(seconds) {
	/* empty */
}

int TimeSpan::hours() const {
         return hours_;
         }

int TimeSpan::minutes() const {
         return minutes_;
         }

int TimeSpan::seconds() const {
         return seconds_;
         }

const TimeSpan TimeSpan::operator+(const TimeSpan& rhs) const{


	int h = rhs.hours_ + hours_;

	int m = rhs.minutes_ + minutes_;

	int s = rhs.seconds_ + seconds_;


	int hour = ( 60 * 60 * h + 60 * m + s ) / 3600;
	
	int minute = ( 60 * 60 * h + 60 * m + s ) % 3600 / 60;

	int second = ( 60 * 60 * h + 60 * m + s ) % 3600 % 60;

	return TimeSpan(hour, minute, second);

}

const TimeSpan TimeSpan::operator+(int rhs) const{


	int hour = (60 * 60 * hours_ + 60 * minutes_ + seconds_ + rhs ) / 3600 ;
	
	int minute = (60 * 60 * hours_ + 60 * minutes_ + seconds_ + rhs ) % 3600 / 60;

	int second = (60 * 60 * hours_ + 60 * minutes_ + seconds_  + rhs ) % 3600 % 60;


	return TimeSpan(hour, minute, second);

}

// insert time
std::istream& TimeSpan::Insert(std::istream* in) {
  char oper = ':';
  *in >> hours_ >> oper >> minutes_ >> oper >> seconds_;
  return *in;
}

// extract time
std::ostream& TimeSpan::Extract(std::ostream* out) const {
  *out << hours_ << " : " << minutes_ << " : " << seconds_;
  return *out;
}


const TimeSpan operator+(int lhs, const TimeSpan& rhs){
		
	return rhs.operator+ (lhs);		
}

std::istream& operator>>(std::istream& lhs, TimeSpan& rhs){
	return rhs.Insert(&lhs);
}

std::ostream& operator<<(std::ostream& lhs, const TimeSpan& rhs){
	return rhs.Extract(&lhs);
}