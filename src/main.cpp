#include "pi.h"
#include "main.h"
#include "gui.h"
#include <iostream>
#include <gtkmm/main.h>

// GIT REPOSITORY

using namespace std;

int main( int argc, char *argv[])
{
	std::cout << std::endl << APP_TITLE << " " << APP_VERSION << " -> " << DEFAULT_DB << std::endl << std::endl;
	std::cout << "INFO: Creating DB[" << DB_SIZE << "]" << std::endl << std::endl;
	Pi task[DB_SIZE];

	Gtk::Main kit(argc, argv);

  	Gui window(task);
  	Gtk::Main::run(window);
	return 0;	
}



