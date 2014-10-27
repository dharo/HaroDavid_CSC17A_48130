/* 
 * File:   main.cpp
 * Author: David Haro
 * Mid-Term CSC 17A: C++ Programming Objects
 * Problem 1
 * Due October 24, 2014
 */
//Libraries
#include <cstdlib>
#include <iostream>
#include <iomanip>
using namespace std;

//Structures
struct BankAcc{
    int accNum;
    int inBal;
    int totDbt;
    int totCrdt;
};

//Prototypes
void calcBal(BankAcc *);               //Problem 1


int main(int argc, char** argv) {
    //declare variables
    BankAcc cust1;

    //Display purpose
    cout<<"Problem 1: Bank Account";
    cout<<"This program will prompt for a 5 digit account number\n"
        <<"and then ask for\n"
        <<"1) The balance at the beginning of the month\n"
        <<"2) The total amount withdrawn from account\n"
        <<"3) The total amount deposit into account\n"
        <<"If amount withdrawn exceeds the sum of balance and credit, \n"
        <<"a $12 charge will be applied to account.\n\n\n";
    //Prompt for user input
    do{
        cout<<"Please input your 5 digit Account Number: ";
        cin>>cust1.accNum;
    }while(cust1.accNum>99999 || cust1.accNum < 10000);
    cout<<"Accessing Account: "<<cust1.accNum<<endl;
    do{
        cout<<"Please type in your balance at the beginning of the month\n";
        cin>>cust1.inBal;
    }while(cust1.inBal<0);
    cout<<"Initial Balance: $"<<cust1.inBal<<endl;
    do{
        cout<<"Please type in your total in deposits\n";
        cin>>cust1.totCrdt;
    }while(cust1.totCrdt<0);
    cout<<"Total deposit amount: $"<<cust1.totCrdt<<endl;
    do{
        cout<<"Please type in your withdrawn amount\n";
        cin>>cust1.totDbt;
    }while(cust1.totDbt<0);
    cout<<"Total amount withdrawn: $"<<cust1.totDbt<<endl;
    //pass struct to function to create calculations
    calcBal(&cust1);
    return 0;
}

////////////////////////////////////////////////////////////////////////////////
//
//                              Problem 1
//  void calcBal(BankAcc *s) 
//                  receives structure contents of BankAcc and calculates
//                  balance after deposits,withdrawals and charges applied.  
////////////////////////////////////////////////////////////////////////////////

void calcBal(BankAcc *s){
    //calculate balance with charges, debts, and credits.
    s->inBal = (s->inBal+s->totCrdt)-s->totDbt;
    if(s->inBal<0){
        s->inBal-=12;
        cout<<"Account was overdrawn!\n"
            <<"A $12 Charge has been applied.\n"
            <<"Your new account balance is: $"<<s->inBal<<endl;
    }
    else{
        cout<<"Balance after charges: $"<<s->inBal<<endl;
    }

}