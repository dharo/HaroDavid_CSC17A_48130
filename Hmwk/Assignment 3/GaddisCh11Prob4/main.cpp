/* 
 * File:   main.cpp
 * Author: davidharo
 *
 * Gaddis Chapter 11 Problem 4
 * Weather Stats
 */

#include <cstdlib>
#include <iostream>
#include <string>
using namespace std;

struct Weather{
    string month;
    int totRain;
    int hiTmp;
    int loTmp;
    int avgTmp;
};

int avgTemp(Weather a[], const int);
int avgRain(Weather a[], const int);
int totRain(Weather a[], const int);
Weather hiTemp(Weather a[], const int);
Weather loTemp(Weather a[], const int);

int main(int argc, char** argv) {
//declare variables
    const int SIZE=3;
    Weather a[SIZE];
    
    //take input for weather data per month
        for(int i=0;i<SIZE;i++){
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
    cout<<"Average RainFall: "<<avgRain(a,SIZE)<<endl;
    cout<<"Total RainFall: "<<totRain(a,SIZE)<<endl;
    cout<<"Average Temperature: "<<avgTemp(a,SIZE)<<endl;
    cout<<"Highest Temp: "<<hiTemp(a,SIZE).month<<": "<<hiTemp(a,SIZE).hiTmp<<endl;
    cout<<"Lowest Temp: "<<loTemp(a,SIZE).month<<": "<<loTemp(a,SIZE).loTmp<<endl;
    return 0;
}

int avgRain(Weather a[], const int SIZE){
    int avgRain=0;
    for(int i=0;i<SIZE;i++){
        avgRain+=a[i].totRain;
    }
    return avgRain/SIZE;
}
int totRain(Weather a[], const int SIZE){
    int total=0;
    for(int i=0;i<SIZE;i++){
        total+=a[i].totRain;
    }
    return total;
}
int avgTemp(Weather a[], const int SIZE){
    int avgTemp=0;
    for(int i=0;i<SIZE;i++){
        avgTemp+=a[i].avgTmp;
    }
    return avgTemp/SIZE;
}
Weather hiTemp(Weather a[], const int SIZE){
    Weather top;
    int max=-999;
    for(int i=0;i<SIZE;i++){
        if(a[i].hiTmp>max){
            max=a[i].hiTmp;
            top=a[i];
        }
    }
    return top;
}
Weather loTemp(Weather a[], const int SIZE){
    Weather low;
    int min=99999;
    for(int i=0;i<SIZE;i++){
        if(a[i].loTmp<min){
            min=a[i].loTmp;
            low=a[i];
        }
    }
    return low;
}