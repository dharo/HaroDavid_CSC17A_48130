/*
 * Employee.h
 *
 *  Created on: Nov 13, 2014
 *      Author: davidharo
 */

#ifndef EMPLOYEE_H_
#define EMPLOYEE_H_

#include <string>
using namespace std;
//Classes
class Employee{
	private:
		string name;
		int idNumber;
		string department;
		string position;
	public:
		Employee();							//default constructor
		void setName(string);				//setter funct->name
		void setID(int);					//setter funct->idNumber
		void setDept(string);				//setter funct->department
		void setPos(string);				//setter funct->position
		void dispRes();						//display results
};



#endif /* EMPLOYEE_H_ */
