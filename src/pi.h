#include "date.h"
#include "time.h"
#include "task.h"

#include <string>
#include <iostream>

#ifndef PI_H
#define PI_H
// PI -> PROGRAMMER INTERFACE
class Pi : public Date, public Time, public Task {
	public:
		Pi();
		void new_task( int id, std::string t );
		void edit_task( std::string t );
		void print_all_task();
		std::string get_task();
		void get_date();
		std::string get_time();
		int get_day();
		int get_month(); 
		int get_year();
		int get_hour();
		int get_minutes();
		int get_seconds();
		int get_status();
		int get_id();
		std::string get_d();
		void set_finished();
		void set_pixbuf_path( std::string path );
		std::string get_pixbuf_path();
		void set_id( int i );
		void set_status( int s );
		void set_day( int d );
		void set_month( int m );
		void set_year( int y );
		void set_hour( int h );
		void set_minutes( int m );
		void set_seconds( int s );
					
	private:
		std::string pixbuf_path;
		char *db;
};

#endif
