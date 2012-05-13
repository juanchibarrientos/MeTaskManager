#include "task.h"
#include "main.h"
#include <iostream>
#include <string>
using namespace std;

Task::Task() { task = DEFAULT_TASK; status = DEFAULT_STATUS; }

void Task::set( string t ) {
	length = t.length();
	if ( length >= MIN_CHAR_TASK ) {
		task = t;
	}
	else {
		cout << "ERROR: Task length less than 3" << endl;
	}
}
void Task::set_id( int i ) {
	// TODO: AUTO-SET ID BASES ON REGISTERED TASKS
	id = i;
}
void Task::set_status( int s ) { 
	if ( s >= 0 && s < 2 ) status = s;
}
int Task::get_status() {
	return status;
}
int Task::get_id() {
	return id;
}
string Task::print() {
	string result = task;
	if(result.length() == 0) {
		result = "NULL";
	}
	else {
		if ( length >= MAX_PRINT_LENGTH ) {
		result = result.substr( 0, MAX_PRINT_LENGTH);
		result += "...";	
		}
	}	
	return result;
}
int Task::print_length() {
	return length;
}
