#include "pi.h"
#include "date.h"
#include "time.h"
#include "task.h"
#include "main.h"
#include <sstream>

#include <iostream>
#include <iomanip>


Pi::Pi()
	: Date(), Time(), Task() { pixbuf_path = DEFAULT_PIXBUF_PATH; db = DEFAULT_DB; }

void Pi::new_task( int id, std::string t ) {
	Task::set( t );
	Task::set_id( id );
	Task::set_status( DEFAULT_STATUS );
}
void Pi::print_all_task() {
	std::cout << Task::get_id() << " " << Task::print() << " ";
	Time::print(TIME_PRINT_FORMAT);
	std::cout << " At ";
	Date::print();
	std::cout << "\n";
}
void Pi::set_finished() { Task::set_status( STATUS_FINISHED ); }
void Pi::set_status( int s ) { Task::set_status( s ); }
void Pi::edit_task( std::string t ) { 
	Task::set( t ); 
	Date::set_current_date(); 
	Time::set_current_time();
}
int Pi::get_status() { return Task::get_status(); }
std::string Pi::get_task() { return Task::print(); }
void Pi::get_date() { Date::print(); }
std::string Pi::get_d() {
	std::stringstream buffer;
	if ( Pi::get_day() < 10 ) { buffer << "0"; }
	buffer << Pi::get_day();
	buffer << "/";
	if ( Pi::get_month() < 10 ) { buffer << "0"; }
	buffer << Pi::get_month();
	buffer << "/";
	buffer << Pi::get_year();

	return buffer.str();
}
int Pi::get_day() { return Date::get_day(); }
int Pi::get_month() { return Date::get_month(); }
int Pi::get_year() { return Date::get_year(); }
int Pi::get_hour() { return Time::get_hour(); }
int Pi::get_minutes() {	return Time::get_minutes(); }
int Pi::get_seconds() { return Time::get_seconds(); }
std::string Pi::get_time() {
	std::stringstream buffer;
	if ( Pi::get_hour() < 10 ) { buffer << "0"; }
	buffer << Pi::get_hour();
	buffer << ":";
	if ( Pi::get_minutes() < 10 ) { buffer << "0"; }
	buffer << Pi::get_minutes();
	buffer << ":";
	if ( Pi::get_seconds() < 10 ) { buffer << "0"; }
	buffer << Pi::get_seconds();
	
	return buffer.str();
}
int Pi::get_id() { return Task::get_id(); }
void Pi::set_day( int d ) {	Date::set_day(d); }
void Pi::set_month( int m ) { Date::set_month(m); }
void Pi::set_year( int y ) { Date::set_year(y); }
void Pi::set_hour( int h ) { Time::set_hour(h); }
void Pi::set_minutes( int m ) {	Time::set_minutes(m); }
void Pi::set_seconds( int s ) {	Time::set_seconds(s); }
void Pi::set_pixbuf_path( std::string path ) {
	// TODO: CHECK IF PATH EXISTS
	pixbuf_path = path;
}
std::string Pi::get_pixbuf_path() {	return pixbuf_path; }
void Pi::set_id( int i ) { Task::set_id( i ); }

