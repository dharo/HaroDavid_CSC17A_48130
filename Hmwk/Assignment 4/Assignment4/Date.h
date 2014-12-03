#ifndef DATE_H
#define DATE_H

#include <string>
using namespace std;

//Classes
class Date{
	private:		//mutators
		int mon;
		int day;
		int yer;
	public:					//accessors
		void setMon(int);		
		void setDay(int);
		void setYer(int);
		int getMon() const;
		int getDay() const;
		int getYer() const;
		void stdDte();		 //displays as mm/dd/yyyy
		void gregDte();		 //displays as Month dd, yyyy
		void mlaDte();		 //displays as dd Month yyyy
		string months(int);  //Generate months from int values
};

#endif