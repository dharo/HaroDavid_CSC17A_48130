/* main.cpp
     Author: davidharo
	 
	 Final_Prob1
*/

//Libraries
#include <iostream>
#include "Prob1Random.h"

using namespace std;
//Function Prototypes


//execute main
int main () {

	unsigned char n=5;
	unsigned char rndseq[]={16,34,57,79,144};
	Prob1Random a(n,rndseq);
	int ntimes=100000;
        srand(time(0));              
 

		for(int i=1;i<=ntimes;i++){
			a.randFromSet();
		}

		int *x=a.getFreq();
		unsigned char *y=a.getSet();
		for(int i=0;i<n;i++){
			cout<<int(y[i])<<" occurred "<<x[i]<<" times"<<endl;
		}

		cout<<"The total number of random numbers is "<<a.getNumRand()<<endl;
    return 0;
}//exit
