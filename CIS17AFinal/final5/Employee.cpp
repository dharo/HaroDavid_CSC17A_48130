/* 
 * File:   Employee.cpp
 * Author: davidharo
 
 */

#include "Employee.h"
#include <iostream>
#include <sstream>
using namespace std;

Employee::Employee(char name[],char position[],float payRate) {
    //initialize employee data
    for(int i=0;i<20;i++){
        MyName[i] = name[i];
        JobTitle[i] = position[i];
    }
    if (payRate<=0 || payRate > 200){
        HourlyRate = 0;
        cout<<"Invalid PayRate!\n";
    }
    else{
        HourlyRate = payRate;
    }
    HoursWorked = 0;
    GrossPay = 0;
    NetPay = 0;
}
float Employee::Tax(float gross){
    //initialize tax tiers and temp values
    float tax = 0;
    float temp = 0;
    float tier1 = 0.1f;       //gross < 500          
    float tier2 = 0.2f;       //gross < 1000 && gross > 500
    float tier3 = 0.3f;       //gross > 1000
    
    if(gross>1000){
        temp = gross - 1000;
        tax = tax + temp * tier3;
        gross = gross - temp;
    }
    if(gross>500){
        temp = gross - 500;
        tax = tax + temp * tier2;
        gross = gross - temp;
    }
    tax = tax + gross * tier1;
    
    return tax;
}

float Employee::CalculatePay(float x, int y){
    return getNetPay(getGrossPay(setHourlyRate(x)
		,setHoursWorked(y)));
}

float Employee::getGrossPay(float payRate, int wrkHrs){
    float gross = 0;
    
    if (wrkHrs<40){
        gross = payRate*wrkHrs;
        GrossPay = gross;
    }
    else if(wrkHrs>=40 && wrkHrs < 50){
        gross = (payRate*39);  //39 hours is max straight time
        wrkHrs = wrkHrs - 39;
        payRate *= 1.5;        //time and a half pay
        gross = gross + (wrkHrs*payRate);  //new gross pay
        GrossPay = gross;
    }
    else if(wrkHrs>=50){
        gross = (payRate*39);                     //39 hours is max straight-time
        gross = gross+((payRate*1.5)*10);         //10 hours is max time and a half
        gross = gross+((payRate*2)*(wrkHrs-49));    //double-time pay
        GrossPay = gross;
    }
    
    return GrossPay;
}
float Employee::getNetPay(float a){
    NetPay = GrossPay - Tax(a);
    return NetPay;
}

int Employee::setHoursWorked(int a){
    if(a > 0 && a < 84){
        HoursWorked = a;
    }
    else{
        cout<<"Invalid Work Hours!"<<endl;
        HoursWorked = 0;
    }
    return HoursWorked;
}
float Employee::setHourlyRate(float a){
    if(a > 0 && a < 200){
        HourlyRate = a;
    }
    else{
        cout<<"Invalid Pay Rate!"<<endl;
        HourlyRate = 0;
    }
    return HourlyRate;
}
void Employee::toString(){
    stringstream Obj;
    //write to string object
    cout<<endl<<endl;
    Obj<<"Name = "<<string(MyName)<<" \n"<<"Position: "<<string(JobTitle)<<"\n"
       <<"Hourly Rate: $"<<HourlyRate<<"\n"<<"Hours Worked: "<<HoursWorked<<"\n"
       <<"Gross Pay: $"<<GrossPay<<"\n"<<"Net Pay: $"<<NetPay;
    //display as string
    cout<<Obj.str()<<endl;
}