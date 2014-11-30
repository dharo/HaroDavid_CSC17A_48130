/* 
 * File:   main.cpp
 * Author: davidharo
 * Corporate Sales data
 * Gaddis Chapter 11 Problem 3
 */

#include <cstdlib>
#include <iostream>
#include <string>
using namespace std;

struct SalesData{
    string divName;
    float firstSls;
    float secSls;
    float thrdSls;
    float frthSls;
};

void dspData(SalesData);
float totannsales(SalesData);
float avgQuartSales(SalesData);

int main(int argc, char** argv) {
//declare variables
    SalesData East={"East",500.21,321.43,354.74,346.89};
    SalesData West={"West",658.54,345.64,748.66,156.81};
    SalesData North={"North",868.66,628.62,264.62,686.28};
    SalesData South={"South",394.24,629.87,346.86,387.56};
    
    dspData(East);
    dspData(West);
    dspData(North);
    dspData(South);
    return 0;
}

void dspData(SalesData a){
    //display data in a formatted manner
    cout<<"Division: "<<a.divName<<endl;
    cout<<"First-Quarter Sales: $"<<a.firstSls<<endl;
    cout<<"Second-Quarter Sales: $"<<a.secSls<<endl;
    cout<<"Third-Quarter Sales: $"<<a.thrdSls<<endl;
    cout<<"Fourth-Quarter Sales: $"<<a.frthSls<<endl;
    cout<<"Total Annual Sales: $"<<totannsales(a)<<endl;
    cout<<"Average Quarterly Sales: $"<<avgQuartSales(a)<<endl;
    cout<<endl<<endl;
}

float totannsales(SalesData a){
    return (a.firstSls+a.secSls+a.thrdSls+a.frthSls);
}
float avgQuartSales(SalesData a){
    return (a.firstSls+a.secSls+a.thrdSls+a.frthSls)/4;
}