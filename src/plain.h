#include <iostream>
#include <fstream>
#include <string>
#include "pi.h"

#ifndef PLAIN_H
#define PLAIN_H

using namespace std;

class Plain {
	public:
		Plain();
		void plain_write_all( Pi vector[]);
		void plain_read_all( Pi vector[], int mode );
		void set_file(char* f);
		char* get_file();

		void populate_tasks(Pi v[], Pi vector[]);
		void print_contents(Pi v[]);
		std::string get_task(Pi vector[], int id);
		void set_task(Pi vector[], int id, std::string new_task);
		void update_db(Pi vector[]);
		int get_counter();
		
		
	private:
		char* file;
		int counter;
		
};

#endif
