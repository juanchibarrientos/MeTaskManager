#include "date.h"
#include <iostream>
#include <ctime>

Date::Date() { set_current_date(); }

void Date::set( int d, int m, int y ) {
	day = ( d > 0 && d <= 31 ) ? d : 0;
	month = ( m > 0 && m <= 12 ) ? m : 0;
	year = ( y > 1800 && y <= 3000 ) ? y : 0;
}
void Date::set_current_date() {
	using namespace std;
	time_t t = time(0);   // get time now
    struct tm * now = localtime( & t );
	day = now->tm_mday;
	month = now->tm_mon + 1;
	year = now->tm_year + 1900;
}	
void Date::set_day( int d ) {
	day = ( d > 0 && d <= 31 ) ? d : 0;
}
void Date::set_month( int m ) {
	month = ( m > 0 && m <= 12 ) ? m : 0;
}
void Date::set_year( int y ) {
	year = ( y > 1800 && y <= 3000 ) ? y : 0;
}
void Date::print() {
	std::cout << day << "/" << month << "/" << year;
}
int Date::get_day() {
	return day;
}
int Date::get_month() {
	return month;
}
int Date::get_year() {
	return year;
}
