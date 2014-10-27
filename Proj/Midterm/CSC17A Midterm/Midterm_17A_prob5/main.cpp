/* 
 * File:   main.cpp
 * Author: davidharo
 *
 * Created on October 22, 2014, 9:31 PM
 */

#include <cstdlib>
#include <iostream>
using namespace std;


/*
 * 
 */
int main(int argc, char** argv) {
    //declare variables
    short shrt=1;
    int intgr=1;
    unsigned int unInt=1;
    long lng=1, templ;
    float flt=1, tempf;
    double dbl=1;
    long double ldbl=1;
    int num=500;
    char c;
    
    
    //Display purpose
    cout<<"Problem 5: Factorial";
    cout<<"This program will calculate the highest factorial that a given\n"
        <<"primitive prototype can hold in a byte\n\n";
    
    
    //Short  
    for(int i=1;i<=num;i++){
        shrt=shrt*i;
        if(shrt<=0){
            shrt=i-1;
            break;
        } 
    }
    //Integer   
    for(int i=1;i<=num;i++){
        intgr=intgr*i;
        if(intgr<=0){
            intgr=i-1;
            break;
        } 
    }
    //Unsigned Integer   
    for(int i=1;i<=num;i++){
        
        unInt=unInt*i;
        if(unInt<=0){
            unInt=i-1;
            break;
        } 
    }
    //Long   
    for(int i=1;i<=num;i++){
        lng=lng*i;
        templ=lng;
        if((lng*i++)<templ){
            lng=i;
            break;
        } 
    }
    //Float  
    for(int i=1;i<=num;i++){
        flt=flt*i;
        tempf=flt;
        if((flt*i++)<tempf){
            flt=i;
            break;
        } 
    }
    //Double  
    for(int i=1;i<=num;i++){
        dbl=dbl*i;
        if(dbl<=0){
            dbl=i-1;
            break;
        } 
    }
    //Long Double  
    for(int i=1;i<=num;i++){
        ldbl=ldbl*i;
        if(ldbl<=0){
            ldbl=i-1;
            break;
        } 
    }
    cout<<"Highest factorial that can be held in a Short: "<<shrt<<endl;
    cout<<"Highest factorial that can be held in an Integer: "<<intgr<<endl;
    cout<<"Highest factorial that can be held in an Unsigned Integer: "<<unInt<<endl;
    cout<<"Highest factorial that can be held in a Long: "<<lng<<endl;
    cout<<"Highest factorial that can be held in a Float: "<<flt<<endl;
    cout<<"Highest factorial that can be held in a Double: "<<dbl<<endl;
    cout<<"Highest factorial that can be held in a Long Double: "<<ldbl<<endl;
        
}

