/*
	David Haro
	Gaddis Chapter 13 Problem 2
*/

//libraries
#include <iostream>
#include <string>
#include <cstdlib>
#include "Employee.h"
using namespace std;



//Function prototypes

//execute

int main(int argv,char *argc[]){
	
	Employee dude[3];
	string yourname;
	int number;
	string zone;		//department
	string role;		//position

	for(int i=0;i<3;i++){
		cout<<"Employee "<<i+1<<" name: ";
		getline(cin, yourname);
		dude[i].setName(yourname);

		cout<<"Employee "<<i+1<<" ID: ";
		cin>>number;
		dude[i].setID(number);
		cin.ignore();		//Fixes getline/cin mix

		cout<<"Employee "<<i+1<<" Department: ";
		getline(cin, zone);
		dude[i].setDept(zone);
	
		cout<<"Employee "<<i+1<<" Position: ";
		getline(cin, role);
		dude[i].setPos(role);
	}
	//Display Results
	cout<<"Results\n\n";
	for(int i=0;i<3;i++){
		dude[i].dispRes();		//display results
	}
	return 0;
}
