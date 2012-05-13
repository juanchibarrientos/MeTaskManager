#include "plain.h"
#include "pi.h"
#include "main.h"
#include <iostream>
#include <fstream>
#include <string>
#include <cstdlib>
#include <cstring>
#include <vector>

using namespace std;

Plain::Plain() { file = DEFAULT_DB; }


void Plain::plain_write_all( Pi vector[]) {
	ofstream plain_file;
	plain_file.open(file);
	if (plain_file.is_open()) {
		for ( int x = 0; x < DB_SIZE; x++ ) {
			plain_file << "\n[SOF]\n";
			plain_file << vector[x].get_id() << "\n";
			plain_file << vector[x].get_task() << "\n";
			if ( vector[x].get_status() == 0 ) {
				plain_file << "Pendient" << "\n";
			}
			else if ( vector[x].get_status() == 1 ) {
				plain_file << "Finished" << "\n";				
			}
			else {
				plain_file << "UNDEFINED" << "\n";
			}
			plain_file << vector[x].get_day() << "/" 
				<< vector[x].get_month() << "/" << vector[x].get_year() << "\n";
			plain_file << vector[x].get_hour() << ":"
				<< vector[x].get_minutes() << ":" << vector[x].get_seconds() << "\n";
			plain_file << "[EOF]\n";
		}
		plain_file.close();
	}
	else cout << "Unable to write file: " << file << "\n"; 
}
void Plain::plain_read_all( Pi vector[], int mode) {
	string buffer;
	int x = 0;
	char *ptr;
	ifstream plain_file(file);
  	if ( plain_file.is_open() ) {
    	while ( plain_file.good() )	{
      		getline ( plain_file, buffer );
			if ( buffer == "[SOF]") {
				while ( buffer != "[EOF]" ) {
						getline ( plain_file, buffer );
						if ( mode == 1) { 
							cout << "----------\n";
							cout << "ID: " << buffer << endl;	
						}
						// ID DEFINES LATER...
						getline ( plain_file, buffer );
						if ( mode == 1) {
							cout << "TASK: " << buffer << endl;	
						}
						vector[x].edit_task(buffer);
						getline ( plain_file, buffer );
						if ( mode == 1) {
							cout << "STATUS: " << buffer << endl;
						}
						vector[x].set_status(atoi(buffer.c_str()));
						getline ( plain_file, buffer );
						if ( mode == 1) {
							cout << "DATE: " << buffer << endl;	
						}
						// Tokens Divide
  						string  temp;
						int date[3];
						int time[3];
						int y = 0;
  						while (buffer.find("/", 0) != string::npos)	{
  							size_t  pos = buffer.find("/", 0); 
   							temp = buffer.substr(0, pos);   
   							buffer.erase(0, pos + 1);          
   							date[y] = atoi(temp.c_str());
						 	y++;	  
 						}
						date[y] = atoi(buffer.c_str());
						vector[x].set_day(date[0]);
						vector[x].set_month(date[1]);
						vector[x].set_year(date[2]);
 						y = 0;
						getline ( plain_file, buffer );
						if ( mode == 1) {
							cout << "TIME: " << buffer << endl;	
						}
						temp = "";
						while (buffer.find(":", 0) != string::npos)	{
  							size_t  pos = buffer.find(":", 0); 
   							temp = buffer.substr(0, pos);   
   							buffer.erase(0, pos + 1);          
   							time[y] = atoi(temp.c_str());
						 	y++;	  
 						}
						time[y] = atoi(buffer.c_str());
						y = 0;
						vector[x].set_hour(time[0]);
						vector[x].set_minutes(time[1]);
						vector[x].set_seconds(time[2]);
						getline ( plain_file, buffer );
						x++;
						
				}
			}
    	}
	
	counter = x;	
	if ( mode == 1) {
		std::cout << "Counter: " << counter << std::endl;
	}
   	plain_file.close();
  	}
	else { counter = 0;	}

	for(x=0; x < DB_SIZE; x++) { vector[x].set_id(x+1); }

}
void Plain::set_file(char* f) {	file = f; }
char* Plain::get_file() { return file; }
void Plain::populate_tasks(Pi v[], Pi vector[]) {
	std::cout << "INFO: Populating tasks..." << std::endl;
	for ( int x = 0; x < DB_SIZE; x++ ) {
		v[x] = vector[x];
		if(vector[x].get_task() != "NULL") {
			std::cout << "task[" << x+1 << "] -> " << vector[x].get_task() << std::endl;
		}
		else {
			std::cout << "WARNING: task[" << x+1 << "] is empty" << std::endl;
		}
	}	
}
void Plain::print_contents(Pi v[]) {
	for ( int x = 0; x < DB_SIZE; x++ ) {
		if(v[x].get_task() != "NULL") {
			std::cout << "task[" << x+1 << "] -> " << v[x].get_task() << std::endl;
		}
		else {
			std::cout << "WARNING: task[" << x+1 << "] is empty" << std::endl;
		}
	}		
}
std::string Plain::get_task(Pi vector[], int id) {
	if(id > 0 && id <= DB_SIZE) return vector[id-1].get_task();
}
void Plain::set_task(Pi vector[], int id, std::string new_task) {
	if(id <= DB_SIZE) { 
		vector[id-1].edit_task(new_task);
		vector[id-1].set_id(id);
		std::cout << "INFO: Editing vector[" << id << "] to " << new_task << std::endl;
	}
	else {
		std::cout << "ERROR: vector size is " << DB_SIZE << std::endl;
	}
}
void Plain::update_db(Pi vector[]) {
	std::cout << "INFO: Saving changes to " << file << std::endl;
	plain_write_all(vector);
	std::cout << "INFO: Populating DB..." << std::endl;
	plain_read_all(vector, 0);
}
int Plain::get_counter() { return counter; }
