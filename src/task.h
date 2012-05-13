#ifndef TASK_H
#define TASK_H

#include <string>

class Task {
	public:
		Task();
		void set( std::string t );
		void set_id( int i );
		void set_status( int s );
		int get_status();
		int get_id();
		std::string print();
		int print_length();
	private:
		std::string task;
		int length;
		int id;
		int status;
};
#endif
