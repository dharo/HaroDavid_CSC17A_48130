/* 
 * File:   main.cpp
 * Author: davidharo
 *
 * Gaddis Chapter 11 Problem 5
 * Weather Stats with Enum
 */

#include <cstdlib>
#include <iostream>
#include <string>
using namespace std;

struct Weathera{
    string month;
    int totRain;
    int hiTmp;
    int loTmp;
    int avgTmp;
};
enum Month {JAN,FEB,MAR,APR,MAY,JUN,JUL,AUG,SEP,OCT,NOV,DEC};
int avg_Temp(Weathera a[], const int);
int avg_Rain(Weathera a[], const int);
int tot_Rain(Weathera a[], const int);
Weathera hi_Temp(Weathera a[], const int);
Weathera lo_Temp(Weathera a[], const int);

int main(int argc, char** argv) {
//declare variables
    const int SIZE=12;
    Weathera a[SIZE];
    
    //take input for weather data per month
        for(int i=JAN;i<DEC;i++){
        cout<<"Please enter Weather Data for month "<<i+1<<": \n";
        cout<<"Month Name:";
        cin>>a[i].month;
        cout<<"Total Rain: ";
        cin>>a[i].totRain;
        cout<<"Highest Temperature: ";
        cin>>a[i].hiTmp;
        cout<<"Lowest Temperature: ";
        cin>>a[i].loTmp;
        //calculate avg temperature
        a[i].avgTmp=(a[i].hiTmp+a[i].loTmp)/2;
    }
    cout<<"Average RainFall: "<<avg_Rain(a,SIZE)<<endl;
    cout<<"Total RainFall: "<<tot_Rain(a,SIZE)<<endl;
    cout<<"Average Temperature: "<<avg_Temp(a,SIZE)<<endl;
    cout<<"Highest Temp: "<<hi_Temp(a,SIZE).month<<": "<<hi_Temp(a,SIZE).hiTmp<<endl;
    cout<<"Lowest Temp: "<<lo_Temp(a,SIZE).month<<": "<<lo_Temp(a,SIZE).loTmp<<endl;
    return 0;
}

int avg_Rain(Weathera a[], const int SIZE){
    int avgRain=0;
    for(int i=0;i<SIZE;i++){
        avgRain+=a[i].totRain;
    }
    return avgRain/SIZE;
}
int tot_Rain(Weathera a[], const int SIZE){
    int total=0;
    for(int i=0;i<SIZE;i++){
        total+=a[i].totRain;
    }
    return total;
}
int avg_Temp(Weathera a[], const int SIZE){
    int avgTemp=0;
    for(int i=0;i<SIZE;i++){
        avgTemp+=a[i].avgTmp;
    }
    return avgTemp/SIZE;
}
Weathera hi_Temp(Weathera a[], const int SIZE){
    Weathera top;
    int max=-999;
    for(int i=0;i<SIZE;i++){
        if(a[i].hiTmp>max){
            max=a[i].hiTmp;
            top=a[i];
        }
    }
    return top;
}
Weathera lo_Temp(Weathera a[], const int SIZE){
    Weathera low;
    int min=99999;
    for(int i=0;i<SIZE;i++){
        if(a[i].loTmp<min){
            min=a[i].loTmp;
            low=a[i];
        }
    }
    return low;
}