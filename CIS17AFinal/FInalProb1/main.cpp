/* 
 * File:   main.cpp
 * Author: David Haro
 *
 * Created on December 11, 2014, 8:28 PM
 */

#include <cstdlib>
#include <iostream>
#include "Prob1Random.h"
using namespace std;

/*
 * 
 */
int main(int argc, char** argv) {
char n=5;
	char rndseq[]={16,34,57,79,144};
	int ntimes=100000;
	Prob1Random a(n,rndseq);
	for(int i=1;i<=ntimes;i++)
	{
		a.randFromSet();
	}
	int *x=a.getFreq();
	char *y=a.getSet();
	for(int i=0;i<n;i++)
	{
		cout<<int(y[i])<<" occured "<<x[i]<<" times"<<endl;
	}
	cout<<"The total number of random numbers is "<<a.getNumRand()<<endl;
    return 0;
}

