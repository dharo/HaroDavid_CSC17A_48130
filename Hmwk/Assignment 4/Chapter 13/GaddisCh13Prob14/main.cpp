/*
	David Haro
	Gaddis Chapter 13 Problem 14
*/

#include <iostream>
#include <cstdlib>
#include "FBpoints.h"
using namespace std;

int main(){
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

	system("PAUSE");
}