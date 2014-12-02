/*
 * main.cpp
 *
 *  Created on: Nov 13, 2014
 *      Author: davidharo
 */

#include <iostream>
#include <string>
#include "Car.h"

using namespace std;
int main( int argc, const char* argv[] ){
	string make;
	int model;
	Car mustang;

	cout<<"This program will ask user for make, year, and model of car\n"
		<<"then display the results as well as the speed after accel 3 times.\n\n";
	//Prompt for user input
	cout<<"Enter the make of the vehicle: ";
	getline(cin, make);
	mustang.setMk(make);

	cout<<"Enter the year model of the vehicle: ";
	cin>>model;
	mustang.setyrMod(model);

	cout<<"Model year: "<<mustang.getMod()<<endl;
	cout<<"Car Make: "<<mustang.getMk()<<endl;

	for (int i=0;i<5;i++){
		mustang.accel();
		cout<<"Current Speed: "<<mustang.getSpd()<<endl;
	}
	cout<<"Let's slow down now...\n";
	for (int i=0;i<5;i++){
		mustang.brake();
		cout<<"Current Speed: "<<mustang.getSpd()<<endl;
	}
	cout<<"We have stopped! \nTime to go!\n\n";
}


