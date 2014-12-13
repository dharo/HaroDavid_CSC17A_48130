/* 
 * File:   main.cpp
 * Author: David Haro
 *
 * Created on December 11, 2014, 11:46 PM
 */

#include <cstdlib>
#include <iostream>
#include "SavingsAccount.h"
using namespace std;

/*
 * 
 */
int main(int argc, char** argv) {
SavingsAccount mine(-300);

	for(int i=1;i<=10;i++){
            mine.Transaction((float)(rand()%500)*(rand()%3-1));
	}
	mine.toString();
	cout<<"Balance after 7 years given 10% interest = "
		<<mine.Total((float)(0.10),7)<<endl;
    return 0;
}

