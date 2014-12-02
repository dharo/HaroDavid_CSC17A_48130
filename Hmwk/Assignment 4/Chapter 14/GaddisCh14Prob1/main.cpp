/*
	David Haro
	Gaddis 7th Edition Chapter 14 Problem 1
	Numbers Class
	take an inteeger value and translate it into a phrase
*/

#include <iostream>
#include "Numbers.h"
using namespace std;

int main( int argc, const char* argv[] ){
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
	system("PAUSE");
}