/*
 * 
 * David Haro
 * Final Problem 4
 * SavingsAccount.cpp
 * 
 */

#include "SavingsAccount.h"
#include <cstdlib>
#include <iostream>
#include <sstream>

using namespace std;

SavingsAccount::SavingsAccount(float a){
    if(a>0){
        balance = a;
    }
    
    freqWithdraw = 0;
    freqDeposit = 0;
}

float SavingsAccount::Deposit(float dep){
    balance = balance + dep;
    freqDeposit++;
}
float SavingsAccount::Withdraw(float wdrw){
    if(wdrw>balance){
        cout<<"Insufficient Funds!\n"<<endl;
    }
    else{
        balance = balance - wdrw;
        freqWithdraw++;
    }
}
void SavingsAccount::Transaction(float amt){
    if(amt>0)
        Deposit(amt);
    else
        Withdraw(amt);
}
float SavingsAccount::Total(float intrst, int tme){
    if (tme <= 0){
        return balance;
    }
    
    float powr = (1.0 + intrst);
    for(int i=1; i<tme; i++){
        powr *= (1.0 + intrst);
    }
    return (balance * powr); 
}
void SavingsAccount::toString(){
    stringstream strObj;
    //write to string object
    strObj<<"Savings Account Information\n"
          <<"Balance: $"<<balance<<"\n"
          <<"Deposits Made: "<<freqDeposit<<"\n"
          <<"Withdrawals Made: "<<freqWithdraw<<"\n";
    //display as string
    cout<<strObj.str()<<endl;
}