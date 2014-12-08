/* 
 * File:   WBHit.cpp
 * Author: davidharo
 * 
 * Created on December 8, 2014, 6:51 AM
 */

#include "WBHit.h"
#include "Hit.h"
#include <iostream>
#include <string>
#include <fstream>
#include <cstring>
using namespace std;

WBHit::WBHit() {
}

void WBHit::getHit(){
    fstream file("wbhit.bin",ios::binary | ios::in);
        if(!file.is_open()){
            cout<< Hit::getErr();
        }
        file.seekg(0);
        char ch;
        while(file.good()){
            file.get(ch);
            cout<<ch;
        }
}

bool WBHit::isRead(){
    return 0;
}
