/*
	David Haro
	Date class implementation file
	Gaddis Chapter 13 Problem 1
*/


#include <string>
#include <iostream>
#include "Date.h"
using namespace std;


//Implementation File for Date Class
	//Setter functions
void Date::setMon(int m){
	mon=m;
}
void Date::setDay(int d){
	day=d;
}
void Date::setYer(int y){
	yer=y;
}
int Date::getMon() const{
	return mon;
}
int Date::getDay() const{
	return day;
}
int Date::getYer() const{
	return yer;
}


	//displays date in specified format
void Date::stdDte(){
	//displays as mm/dd/yyyy
	cout<<mon<<"/"<<day<<"/"<<yer<<endl;
}
void Date::gregDte(){
	//declare variable
	string fullMon;
	//displays as Month dd, yyyy

	//change int to full name
	fullMon=months(mon);					//because both functions are in the same class, no need to
											//do anything special when calling functions
	cout<<fullMon<<" "<<day<<", "<<yer<<endl;
}
void Date::mlaDte(){
	//declare variables
	string fullMon;
	//change from int to name
	fullMon=months(mon);
	//displays as dd Month yyyy
	cout<<day<<" "<<fullMon<<" "<<yer<<endl;
}


	//Takes in int value for month and converts it to a string/char array (Word)
char* Date::months(int m){
	//change month from int to string
	switch(m){
	case 1:
		return "January";
		break;
	case 2:
		return "February";
		break;
	case 3:
		return "March";
		break;
	case 4:
		return "April";
		break;
	case 5:
		return "May";
		break;
	case 6:
		return "June";
		break;
	case 7:
		return "July";
		break;
	case 8:
		return "August";
		break;
	case 9:
		return "September";
		break;
	case 10:
		return "October";
		break;
	case 11:
		return "November";
		break;
	case 12:
		return "December";
		break;
	default:				//exit on error
		return "ERROR";		//a value higher than 12 cannot be 
		break;				//generated from user input
	}						//input validation during user input
}
