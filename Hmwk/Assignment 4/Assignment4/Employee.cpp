/*
 * Employee.cpp
 *
 *  Created on: Nov 13, 2014
 *      Author: davidharo
 */

#include "Employee.h"
#include <iostream>
#include <string>
using namespace std;

Employee::Employee(){			//default
	name="";
	idNumber=0;
	department = "";
	position = "";
}
void Employee::setName(string iname){
	name = iname;
}
void Employee::setID(int num){
	idNumber = num;
}
void Employee::setDept(string idept){
	department = idept;
}
void Employee::setPos(string iPos){
	position = iPos;
}
void Employee::dispRes(){
	cout<<"Name: "<<name<<endl;
	cout<<"ID Num: "<<idNumber<<endl;
	cout<<"Dept: "<<department<<endl;
	cout<<"Position: "<<position<<endl;
}

