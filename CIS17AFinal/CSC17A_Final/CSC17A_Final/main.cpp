/* 
 * File:   main.cpp
 * Author: David Haro
 *
 * CSC 17A Final
 * Due: December 12, 2014 @ 11:59PM
 */

#include <cstdlib>
#include <iostream>
#include <ctime>
#include <iomanip>
#include <fstream>
#include <cstring>

#include "Prob1Random.h"
#include "Prob3TableInherited.h"
#include "SavingsAccount.h"
#include "Employee.h"
using namespace std;

void Menu();
int getN();
void def(int);
void problem1();
void problem2();
void problem3();
void problem4();
void problem5();
void problem6();
void problem7();
void problem8();


    int main(int argv,char *argc[])
    {
	int inN;
        do{
         Menu();
         inN=getN();
         switch(inN){
          case 1:    problem1();break;
          case 2:    problem2();break;
          case 3:    problem3();break;
          case 4:    problem4();break;
          case 5:    problem5();break;
          default:   def(inN);}
        }while(inN<6);
        system("PAUSE");
        return EXIT_SUCCESS;
    }
    void Menu()
    {
        //Read from binary file
        fstream file("Note_to_DrLehr.bin",ios::binary | ios::in);
        if(!file.is_open()){
            cout<<"Error opening File!\n";
        }
        file.seekg(0);
        char cc;
        while(file.good()){
            file.get(cc);
            cout<<cc;
        }
        cout<<"\n"<<endl;
           cout<<"Type 1 for Problem 1: Random"<<endl;
           cout<<"Type 2 for problem 3: Sum Rows/Cols"<<endl;
           cout<<"Type 3 for problem 4: Savings Account"<<endl;
           cout<<"Type 4 for problem 5: Employee"<<endl;
           cout<<"Type 5 for Problem 6: Conversions (Show Work for all 3 Conversions)"<<endl;
           cout<<"Type 6 to exit \n"<<endl;
    }
    int getN()
    {
           int inN;
		   cin>>inN;
           return inN;
    }
    void problem1()
    {
         cout<<"In problem #1: Random"<<endl<<endl;
         cout<<"If this problem errors out\n"
             <<"I have included Problem 1 in a separate program\n"
             <<"Labeled Final1\n"<<endl;
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
    }
    void problem2()
    {
        cout<<"Final Problem #3: Row/Col Sum\n"<<endl;
        cout<<"Entering problem number 3"<<endl;
	int rows=5;
	int cols=6;
	Prob3TableInherited<int> tab("Problem3.txt",rows,cols);
	const int *naugT=tab.getTable();
	for(int i=0;i<rows;i++){
            for(int j=0;j<cols;j++){
                cout<<naugT[i*cols+j]<<" ";
            }
            cout<<endl;
	}
	cout<<endl;
	const int *augT=tab.getAugTable();
	for(int i=0;i<=rows;i++){
            for(int j=0;j<=cols;j++){
                cout<<augT[i*(cols+1)+j]<<" ";
            }
            cout<<endl;
	}
        cout<<"\n"<<endl;
    }
    void problem3()
    {
           cout<<"In problem #4: Savings Account"<<endl<<endl;
           SavingsAccount mine(-300);

	for(int i=1;i<=10;i++){
            mine.Transaction((float)(rand()%500)*(rand()%3-1));
	}
	mine.toString();
	cout<<"Balance after 7 years given 10% interest = "
		<<mine.Total((float)(0.10),7)<<endl;
        cout<<"\n"<<endl;
    }
    void problem4()
    {
        cout<<"In problem #5: Employee"<<endl<<endl;
        Employee Mark("Mark","Boss",215.50);
        
        
	Mark.setHoursWorked(-3);
	Mark.toString();
        
	Mark.CalculatePay(Mark.setHourlyRate(20.0),Mark.setHoursWorked(25));
	Mark.toString();
        
	Mark.CalculatePay(Mark.setHourlyRate(40.0),Mark.setHoursWorked(25));
	Mark.toString();
        
	Mark.CalculatePay(Mark.setHourlyRate(60.0),Mark.setHoursWorked(25));
	Mark.toString();

        
        
	Employee Mary("Mary","VP",50.0);
	Mary.toString();
        
	Mary.CalculatePay(Mary.setHourlyRate(50.0),Mary.setHoursWorked(40));
	Mary.toString();
        
	Mary.CalculatePay(Mary.setHourlyRate(50.0),Mary.setHoursWorked(50));
	Mary.toString();
        
	Mary.CalculatePay(Mary.setHourlyRate(50.0),Mary.setHoursWorked(60));
	Mary.toString();
        cout<<"\n"<<endl;
        
    }
    void problem5()
    {
           cout<<"In problem #6: Conversions (Show Work)"<<endl<<endl;
               
        //Read from binary file
        fstream file("Problem6proof.bin",ios::binary | ios::in);
        if(!file.is_open()){
            cout<<"Error opening File!\n";
        }
        file.seekg(0);
        char ch;
        while(file.good()){
            file.get(ch);
            cout<<ch;
        }
    }
    
    void def(int inN)
    {
           cout<<"You typed "<<inN<<" to exit the program"<<endl;
    }
    