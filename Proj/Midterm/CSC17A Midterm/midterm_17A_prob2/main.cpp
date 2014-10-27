/* 
 * File:   main.cpp
 * Author: David Haro
 * Mid-Term CSC 17A: C++ Programming Objects
 * Problem 2
 * Due October 24, 2014
 */
//Libraries
#include <cstdlib>
#include <iostream>
#include <string>
using namespace std;
//Structures
struct Employee {
    string name;
    int wrkHrs;
    float payRte;
};

//Prototypes
void dispS(Employee*);
float calc(Employee*);

int main(int argc, char** argv) {
    //declare variables
    int size;
    char correct;
    cout << "Problem 2: Gross Pay"
            << "This program will prompt for how many employees you are calculating\n"
            << "paychecks for and ask for Employee name, work hours, and pay rate\n"
            << "After each employee input, gross pay will be calculated and then \n"
            << "employee info as well as calculated amounts will be displayed.\n\n\n";
    cout << "Enter number of employees: ";
    cin>>size;
    Employee* payroll = new Employee[size];

    for (int i = 0; i < size; i++) {
        do {
            cin.ignore();
            cout << "Input Employee " << i + 1 << " name: ";
            getline(cin, payroll[i].name);
            cout << "Input Hours Worked: ";
            cin >> payroll[i].wrkHrs;
            cout << "Input Pay Rate: ";
            cin >> payroll[i].payRte;
            cout << endl << endl;
            dispS(&payroll[i]);
            cout << "Verify if data is correct. Press (Y/N)";
            cin>>correct;
            cout << endl << endl;
        } while (correct == 'n' || correct == 'N');
    }

    //destroy
    delete [] payroll;
    payroll = NULL;
    return 0;
}

////////////////////////////////////////////////////////////////////////////////
//
//                              Problem 2
//  void dispS(Employee* s) 
//                  displays structure contents 
//  void calc(Employee* g)
//                  receives structure and calculates gross pay
//
////////////////////////////////////////////////////////////////////////////////

void dispS(Employee* s) {
    //Display Data
    float grossP = calc(s);
    cout << "Name: " << s->name << endl;
    cout << "Hours worked: " << s->wrkHrs << endl;
    cout << "Pay Rate: $" << s->payRte << endl;
    cout << "Gross Pay: $" << grossP << endl;
}

float calc(Employee* g) {
    //calculate gross pay
    float grossPay = 0;
    if (g->wrkHrs <= 20)
        grossPay = g->wrkHrs * g->payRte;
    if (g->wrkHrs > 20 && g->wrkHrs <= 40)
        grossPay = (20 * g->payRte)+((g->wrkHrs - 20)*(2 * g->payRte));
    if (g->wrkHrs > 40)
        grossPay = (20 * g->payRte)+(20 * (2 * g->payRte))+(g->wrkHrs - 40)*(3 * g->payRte);

    return grossPay;
}