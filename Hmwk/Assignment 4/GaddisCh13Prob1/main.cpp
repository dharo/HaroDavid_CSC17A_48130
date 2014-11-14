/*
	David Haro
	Chapter 13 Problems Gaddis 7th Edition

*/


//Libraries

#include <iostream>
#include "Date.h"
#include <cstdlib>
using namespace std;


//Begin execution
int main(int argc,char *argv[]){
	//This Program will ask the user for a date.
	//It will check that dates are within range
	//and display them in a formatted manner
	//All inputs are integer values and 

	//declare variables
	int month;
	int day;
	int year;
	Date usrDay;

	//prompt for user input
		//input validation to keep values within range
	do{
		cout<<"Please input the month as a number value: (ex: if March, input should only be 3)"<<endl;
		cin>>month;
	}while(month > 12 || month < 1);
	do{
		cout<<"\nPlease input a day of the month: "<<endl;
		cin>>day;
	}while(day > 31 || day < 1);
	do{
		cout<<"Please input the year: (yyyy):\n";
		cin>>year;
	}while(year>9999 || year < 1000);

	//send to constructors
	usrDay.setMon(month);
	usrDay.setDay(day);
	usrDay.setYer(year);


	//display results
	cout<<"Standard date: ";
	usrDay.stdDte();

	cout<<"Gegorian date: ";
	usrDay.gregDte();

	cout<<"MLA date: ";
	usrDay.mlaDte();

   //system("PAUSE");
   //exit
    return 0;
}
