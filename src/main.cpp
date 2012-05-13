#include "pi.h"
//#include "plain.h"
#include "main.h"
#include "gui.h"
#include <iostream>
#include <gtkmm/main.h>

//#include "plain.h"

// GIT REPOSITORY

using namespace std;

int main( int argc, char *argv[])
{
	std::cout << std::endl << APP_TITLE << " " << APP_VERSION << " -> " << DEFAULT_DB << std::endl << std::endl;
	std::cout << "INFO: Creating DB[" << DB_SIZE << "]" << std::endl << std::endl;
	Pi task[DB_SIZE];

	/*std::cout << "INFO: Populating DB..." << std::endl << std::endl;
	Plain t;
	t.plain_read_all(task, 0);
	t.print_tasks(task);	
	t.set_task(task, 12, "Fail");
	//t.update_db(task);*/
	
	Gtk::Main kit(argc, argv);

  	Gui window(task);
  	Gtk::Main::run(window);
	return 0;	
}



