/* 
 * File:   main.cpp
 * Author: David haro
 * Book: Gaddis 7th Edition
 * Chapter 11

 */


#include <cstdlib>
#include <iostream>
#include <string>
#include <iomanip>

//Chapter 13 Problem 1 Class
#include "Date.h"
//Chapter 13 Problem 2 Class
#include "Employee.h"
//Chapter 13 Problem 3 Class
#include "Car.h"
//Chapter 13 Problem 6 Class
#include "Inventory.h"
//Chapter 13 Problem 8 Class
#include "TestScore.h"
//Chapter 13 Problem 14 Class
#include "FBpoints.h"
//Chapter 14 Problem 1 Class
#include "Numbers.h"
//Chapter 14 Problem 2 Class
#include "DayOfYear.h"
using namespace std;


//prototypes
void Menu();
int getN();
void def(int);
void problem1();
void problem2();
void problem3();
void problem4();
void problem5();
void problem6();
void problem7();
void problem8();


//execute
int main(int argv,char *argc[]){
	int inN;
        do{
         Menu();
         inN=getN();
         switch(inN){
          case 1:    problem1();break;
          case 2:    problem2();break;
          case 3:    problem3();break;
          case 4:    problem4();break;
          case 5:    problem5();break;
          case 6:    problem6();break;
          case 7:    problem7();break;
          case 8:    problem8();break;
          default:   def(inN);}
        }while(inN<9);
        return 1;
    }
    void Menu()
    {
           cout<<"\nType 1 for problem 13.1"<<endl;
           cout<<"Type 2 for problem 13.2"<<endl;
           cout<<"Type 3 for problem 13.3"<<endl;
           cout<<"Type 4 for problem 13.6"<<endl;
           cout<<"Type 5 for problem 13.8"<<endl;
           cout<<"Type 6 for problem 13.14"<<endl;
           cout<<"Type 7 for problem 14.1"<<endl;
           cout<<"Type 8 for problem 14.2"<<endl;
           cout<<"Type 9 to exit \n"<<endl;
    }
    int getN()
    {
           int inN;
           cin>>inN;
           return inN;
    }

//----Problem 1 Chapter 13---- 
void problem1(){
//This Program will ask the user for a date.
	//It will check that dates are within range
	//and display them in a formatted manner
	//All inputs are integer values and 

	//declare variables
	int month;
	int day;
	int year;
	Date usrDay;

        
        cout<<"This program will ask for a date in mm/dd/yyyy and display\n"
            <<"the given date in 3 different formats.\n\n";
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
}


//----Problem 2 Chapter 13---- 
void problem2(){
Employee dude[3];
	string yourname;
	int number;
	string zone;		//department
	string role;		//position

        cout<<"This program will demonstrate an array of classes by prompting \n"
            <<"for input of strings and integer values and displaying information\n"
            <<"of the three classes at the end\n\n";
        
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
}



//Problem 3 Chapter 13
void problem3(){
	string make;
	int model;
	Car mustang;

	cout<<"This program will ask user for make, year, and model of car\n"
		<<"then display the results as well as the speed after accel 3 times.\n\n";
	//Prompt for user input
	cout<<"Enter the make of the vehicle: ";
        cin.ignore();
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


//problem 6 chapter 13
void problem4(){
	int itemNum;
	int qty;
	float cost;

    cout<<"Enter the item Number: ";
    cin>>itemNum;
    //grocery.setItemNumber(itemNum);
    cout<<"Enter the quantity: ";
    cin>>qty;
    //grocery.setQuantity(qty);
    cout<<"Enter the cost: ";
    cin>>cost;
    //grocery.setCost(cost);

    //declare object and pass in parameters
    Inventory grocery(itemNum,qty,cost);
    //display results
    cout<<"Item Number: "<<grocery.getItemNum()<<endl;
    cout<<"Quantity: "<<grocery.getQuantity()<<endl;
    cout<<"Item Cost: "<<grocery.getCost()<<endl;
    cout<<"Total cost: "<<grocery.getTotal()<<endl;
}


 
//problem 8 chapter 13
void problem5(){
    	//declare variables
	float a,b,c;		//test score variables
	TestScore student;

	//prompt for user input
	cout<<"Please enter the score for test #1: ";
	cin>>a;
	cout<<"Please enter the score for test #2: ";
	cin>>b;
	cout<<"Please enter the score for test #3: ";
	cin>>c;

	//pass results into TestScores class for calculation
	student.setOne(a);
	student.setTwo(b);
	student.setThree(c);
	cout<<endl<<endl<<endl;
	cout<<"Test1: "<<student.getOne()<<endl;
	cout<<"Test2: "<<student.getTwo()<<endl;
	cout<<"Test3: "<<student.getThree()<<endl;
	//display average score
	cout<<"Average Test Score: "<<student.avgScore()<<endl;
}


//problem 14 chapter 13
void problem6(){
    	FBpoints checkTmp;
	int temperature;
	cout<<"Enter a temperature (Fahrenheit) to check: ";
	cin>>temperature;

	checkTmp.setTemp(temperature);
	cout<<checkTmp.getTemp();
	cout<<"\n\n\n\n";
	cout<<"1: YES\n0: NO\n\n";
	cout<<"Oxygen:\n";
	cout<<"\t\t"<<"Frozen: "<<checkTmp.isOxygenFreezing()<<endl;
	cout<<"\t\t"<<"Boiling: "<<checkTmp.isOxygenBoiling()<<endl;

	cout<<"Ethyl Alcohol:\n";
	cout<<"\t\t"<<"Frozen: "<<checkTmp.isEthylFreezing()<<endl;
	cout<<"\t\t"<<"Boiling: "<<checkTmp.isEthylBoiling()<<endl;


	cout<<"Water:\n";
	cout<<"\t\t"<<"Frozen: "<<checkTmp.isWaterFreezing()<<endl;
	cout<<"\t\t"<<"Boiling: "<<checkTmp.isWaterBoiling()<<endl;
}


//problem 1 chapter 14
void problem7(){
    	//declare variables
	Numbers user;		//variable for users input to be translated

	int num;
	do{
		//prompt for user input
		cout<<"Enter a number to be translated into a phrase: ";
		cin>>num;
	}while(num>9999 || num < 0);

	user.setNum(num);
	user.print();
  
}

//problem 2 chapter 14
void problem8(){
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
}

    void def(int inN)
    {
           cout<<"You typed "<<inN<<" to exit the program"<<endl;
    }