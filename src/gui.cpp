#include "gui.h"
#include "main.h"
#include "plain.h"

#include <gtkmm/stock.h>
#include <iostream>


// INIT FUNCTION
Gui::Gui( Pi vector[] )
	: entry_button(Gtk::Stock::ADD) {
	
	// READ Pi Vector[]
	t.plain_read_all(vector, 0);
	// POPULATE Plain T
	t.populate_tasks(v, vector);

	set_title(APP_TITLE);
	set_default_size(UI_W, UI_H);
	add(m_Box); 

	m_ScrolledWindow.add(m_TreeView);
	m_ScrolledWindow.set_policy(Gtk::POLICY_AUTOMATIC, Gtk::POLICY_AUTOMATIC);

	
	m_refTreeModel = Gtk::ListStore::create(m_Columns);
 	m_TreeView.set_model(m_refTreeModel);
	// SHOW TASKS ON TREE VIEW
	reload();

	m_TreeView.append_column("ID", m_Columns.m_col_id);
	//m_TreeView.insert_column_editable("ID", m_Columns.m_col_id, 1);
  	m_TreeView.append_column("Task", m_Columns.m_col_task);
	///TODO: SET TASK COLUMN EXPAND
	m_TreeView.append_column("Time", m_Columns.m_col_time);
	m_TreeView.append_column("Date", m_Columns.m_col_date);
	
	
	
	// DECLARE ENTRY
	entry.set_max_length(MAX_CHAR_TASK);
	entry.set_text("Write a new task...");
	//entry.set_text(m_Entry.get_text() + " world");
	entry.select_region(0, entry.get_text_length());
	

	toolbutton_exit.set_icon_name("application-exit");
	toolbutton_edit.set_icon_name("gtk-edit");
	toolbutton_remove.set_icon_name("gtk-apply");
	toolbutton_new.set_icon_name("gtk-new");
	toolbutton_save.set_icon_name("document-save");
	toolbutton_about.set_icon_name("gtk-about");
	toolbutton_find.set_icon_name("gtk-find");
	toolbutton_settings.set_icon_name("gtk-properties");
	
	
	toolbar.insert(toolbutton_new, 0);
	//toolbar.insert(toolbutton_edit, 1);
	toolbar.insert(toolbutton_remove, 1);
	//toolbar.insert(toolbutton_save, 3);
	toolbar.insert(toolbutton_about, 2);
	toolbar.insert(toolbutton_find, 3);
	toolbar.insert(toolbutton_settings, 4);
	toolbar.insert(toolbutton_exit, 5);
	
	m_Box.pack_start(toolbar, Gtk::PACK_SHRINK);
	
	m_Box.pack_start(m_Separator, Gtk::PACK_SHRINK);
	
	m_Box.pack_start(m_ScrolledWindow);
		
	m_Box.pack_start(m_Separator2, Gtk::PACK_SHRINK);
	m_Box.pack_start(hbox2, Gtk::PACK_SHRINK);
		hbox2.pack_start(entry);
		hbox2.pack_start(entry_button);
	// SIGNALS
	toolbutton_exit.signal_clicked().connect( sigc::mem_fun(*this,
              &Gui::on_button_quit) );
	entry_button.signal_clicked().connect( sigc::mem_fun(*this,
              &Gui::on_entry_button_click) );
	toolbutton_new.signal_clicked().connect( sigc::mem_fun(*this,
              &Gui::clean) );
	counter = 1;
	while(v[counter-1].get_task() != "NULL" && counter <= DB_SIZE) {
		counter++;
		
		if(counter == DB_SIZE ) {
			counter++;
			break;
		}
		std::cout << "UPDATE: Counter -> " << counter << std::endl;
	}
 	show_all_children();
}


Gui::~Gui()
{
}
void Gui::clean() { 
	std::cout << "INFO: Cleaning tree..." << std::endl;
	m_refTreeModel->clear(); 
	}
void Gui::reload() {
	std::cout << "INFO: Reading file..." << std::endl;
	t.plain_read_all(v, 0);
	
	clean();
	for ( int x = 0; x < DB_SIZE; x++ ) { 
		if(v[x].get_task() != "NULL") {
			row = *(m_refTreeModel->append());
  			row[m_Columns.m_col_id] = v[x].get_id();
  			row[m_Columns.m_col_task] = v[x].get_task();
			/// TODO: SET CURRENT DATE
  		 	row[m_Columns.m_col_time] = v[x].get_time();
		 	row[m_Columns.m_col_date] = v[x].get_d();
		}
	}
	std::cout << "INFO: Filling tree..." << std::endl;
}
void Gui::on_button_quit() {  hide(); }
// GET TEXT FROM ENTRY
void Gui::on_entry_button_click() {
	if ( entry.get_text() != DEFAULT_TASK && entry.get_text() != "Write a new task...") {
	
		if(counter <= DB_SIZE && counter > 0) {
			std::cout << "INFO: Editing v[" << counter << "] -> " << entry.get_text() << std::endl;
			v[counter-1].edit_task(entry.get_text());
			std::cout << "INFO: Saving changes..." << std::endl;
			t.plain_write_all(v);
			reload();
			if(entry.get_text().length() >= MIN_CHAR_TASK ){ 
				entry.set_text("");
				counter++;
			}
		}
		else {
			std::cout << "ERROR: Cant access vector[" << counter << "]" << std::endl;
		}
	}
}
