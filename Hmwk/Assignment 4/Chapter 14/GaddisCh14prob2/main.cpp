/*
	David Haro
	Gaddis 7th Edition Chapter 14 Problem 2
	Day of the Year
	Purpose: take an int from 1-365 and convert it to the equivalent Month-Day 
*/

#include <iostream>
#include "DayOfYear.h"
using namespace std;

int main( int argc, const char* argv[] ){
	//declare variables
	int day=NULL;
	DayOfYear a;
	char again='n';
	do{
		do{
			//prompt for input
			cout<<"Please enter a day of the year. (1-365)\n";
			cin>>day;
		}while(day > 365 || day < 1);
		//pass into class
		a.setNum(day);
		//print results
		a.print();
		//repeat?
		cout<<"Again? (Y/N): ";
		cin>>again;
	}while(again == 'y' || again == 'Y');
	return 0;
}