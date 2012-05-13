#include "time.h"
#include <iostream>
#include <ctime>

Time::Time() { set_current_time(); }

void Time::set( int h, int m, int s ) {
	hour = ( h >= 0 && h < 24 ) ? h : 0;
	minutes = ( m >= 0 && m < 60 ) ? m : 0;
	seconds = ( s >= 0 && s < 60 ) ? s : 0;
}
void Time::set_current_time() {
	time_t currentTime;
	time (&currentTime);
	struct tm * ptm= localtime(&currentTime);
	hour = ptm->tm_hour;
	minutes = ptm->tm_min;
	seconds = ptm->tm_sec;
}
void Time::set_hour( int h ) {
	hour = ( h >= 0 && h < 24 ) ? h : 0;
}
void Time::set_minutes( int m ) {
	minutes = ( m >= 0 && m < 60 ) ? m : 0;
}
void Time::set_seconds( int s ) {
	seconds = ( s >= 0 && s < 60 ) ? s : 0;
}
void Time::print( int x ) { // TODO: FUNCTION RETURN STRING
	std::cout << hour << ":";
	if ( minutes < 10 ) { std::cout << "0"; }
	std::cout << minutes;
	if ( x == 0 ) {
		std::cout << ":";
		if ( seconds < 10 ) { std::cout << "0"; }
		std::cout << seconds;
	}
}
int Time::get_hour() {
	return hour;
}
int Time::get_minutes() {
	return minutes;
}
int Time::get_seconds() {
	return seconds;
}
