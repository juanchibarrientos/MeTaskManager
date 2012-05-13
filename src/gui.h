#ifndef GUI_H
#define GUI_H

#include <gtkmm.h>
#include "pi.h"
#include "plain.h"
#include "main.h"

class Gui : public Gtk::Window
{
	public:
		Gui( Pi vector[]);
		virtual ~Gui();

	protected:
	//Signal handlers:
	void on_button_quit();
	void on_entry_button_click();	
	void reload();	
	void clean();
	void load_cli( Pi vector[], int length );
	//void read_db( Pi vector[], int length );
	//void on_done_button();
	
	

	//Tree model columns:
	class ModelColumns : public Gtk::TreeModel::ColumnRecord {
		public:

			ModelColumns()
		{ add(m_col_id); add(m_col_task); add(m_col_status); add(m_col_time); add(m_col_date); }

			Gtk::TreeModelColumn<unsigned int> m_col_id;
			Gtk::TreeModelColumn<Glib::ustring> m_col_task;
			Gtk::TreeModelColumn<Glib::ustring> m_col_status;
			Gtk::TreeModelColumn<Glib::ustring> m_col_time;
			Gtk::TreeModelColumn<Glib::ustring> m_col_date;
			
	};

		ModelColumns m_Columns;
	//Child widgets:
		Gtk::VBox m_Box;
				Gtk::Toolbar toolbar;
				Gtk::ToolButton toolbutton_exit;
				Gtk::ToolButton toolbutton_edit;
				Gtk::ToolButton toolbutton_remove;
				Gtk::ToolButton toolbutton_new;
				Gtk::ToolButton toolbutton_save;
				Gtk::ToolButton toolbutton_about;
				Gtk::ToolButton toolbutton_find;
				Gtk::ToolButton toolbutton_settings;
			Gtk::ScrolledWindow m_ScrolledWindow;
				Gtk::TreeView m_TreeView;
		 		Gtk::TreeModel::Row row;
				Glib::RefPtr<Gtk::ListStore> m_refTreeModel;
			Gtk::HSeparator m_Separator;
		    Gtk::HSeparator m_Separator2;
			Gtk::HBox hbox2;
				Gtk::Entry entry;
				Gtk::Button entry_button;
			

		private:
			Pi v[DB_SIZE];
			int l;
			Plain t;
			int counter;


};


#endif
