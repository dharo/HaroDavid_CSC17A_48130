/* 
 * File:   Graphics.cpp
 * Author: davidharo
 * 
 * Created on December 5, 2014, 11:48 PM
 */

#include "Hit.h"
#include <iostream>
#include <string>
#include <fstream>
#include <cstring>
using namespace std;


Hit::Hit() {
}

void Hit::setErr(){
    err="There was a problem reading the file!";
}

string Hit::getErr(){
    return err;
}

void Hit::getHit(){

    cout<<"\t\t\t\t\t     __  ____________\n"<<
          "\t\t\t\t\t    / / / /  _/_  __/\n"<<
          "\t\t\t\t\t   / /_/ // /  / /   \n"<<
          "\t\t\t\t\t  / __  // /  / /    \n"<<
          "\t\t\t\t\t /_/ /_/___/ /_/     \n"<<
          "\n";
    
}




