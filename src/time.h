#ifndef TIME_H
#define TIME_H

//#include <string>

class Time {
	public:
		Time();
		// SET ALL VALUES
		void set( int h, int m, int s );
		void set_current_time();
		// SET INDIVIDUAL VALUES
		void set_hour( int h );
		void set_minutes( int m );
		void set_seconds( int s );
		// PRINT ALL VALUES
		void print( int x ); // x = 0 --> with seconds
		// PRINT INDIVIDUAL VALUES
		int get_hour();
		int get_minutes();
		int get_seconds();
	private:
		int hour;
		int minutes;
		int seconds;
};

#endif