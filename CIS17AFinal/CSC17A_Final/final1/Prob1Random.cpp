/*Prob1Random.cpp
     Author: davidharo

*/

#include "Prob1Random.h"
#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;
/*  Prob1Random(char,char *);     			  //Constructor
	~Prob1Random(void);                       //Destructor
	char randFromSet(void);                   //Returns a random number from the set
	int *getFreq(void) const;                 //Returns the frequency histogram
	char *getSet(void) const;                 //Returns the set used
	int getNumRand(void) const;               //Gets the number of times randFromSet has
											  //been called*/


Prob1Random::Prob1Random(unsigned char n,unsigned char *numSet){
	set = numSet;
	nset = n;
	numRand = 0;
	for(int i=0;i<nset;i++){
		freq[i]=0;
	}
}
Prob1Random::~Prob1Random(void){}
unsigned char Prob1Random::randFromSet(void){

	//rand is seeded in main to prevent same # being counted
	int pos = rand() % 5+1;		//random position generator

	freq[pos-1]+=1;
	numRand++;
	return set[pos-1];
}

int* Prob1Random::getFreq(void) const{
	return freq;
}

unsigned char* Prob1Random::getSet(void) const{
	return set;
}

int Prob1Random::getNumRand(void) const{
	return numRand;
}
