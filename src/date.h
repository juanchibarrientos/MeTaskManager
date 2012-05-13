#ifndef DATE_H
#define DATE_H

class Date {
	public:
		Date();
		// SET ALL VALUES
		void set( int d, int m, int y );
		void set_current_date();
		// SET INDIVIDUAL VALUES
		void set_day( int d );
		void set_month( int m );
		void set_year( int y );
		// PRINT ALL VALUES
		void print();
		// PRINT INDIVIDUAL VALUES
		int get_day();
		int get_month();
		int get_year();
	private:
		int day;
		int month;
		int year;
};

#endif