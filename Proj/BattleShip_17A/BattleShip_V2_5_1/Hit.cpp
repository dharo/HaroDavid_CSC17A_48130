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
string Hit::getErr() const{
    return err;
}
void Hit::getHit() const{
    fstream file("hit.bin",ios::binary | ios::in);
        if(!file.is_open()){
            cout<<getErr();
        }
        file.seekg(0);
        char ch;
        while(file.good()){
            file.get(ch);
            cout<<ch;
        }
}




