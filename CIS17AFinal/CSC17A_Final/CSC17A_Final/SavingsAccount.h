/* 
 * File:   SavingsAccount.h
 * Author: davidharo
 *
 * Created on December 11, 2014, 11:51 PM
 */

#ifndef SAVINGSACCOUNT_H
#define	SAVINGSACCOUNT_H

class SavingsAccount{
    private:
        float Withdraw(float);               //Utility Procedure
        float Deposit(float);                //Utility Procedure
        float balance;                       //Property
        int   freqWithdraw;                  //Property
        int   freqDeposit;                   //Property
    public:
        SavingsAccount(float);               //Constructor
        void  Transaction(float);            //Procedure
        float Total(float=0,int=0);	     //Savings Procedure
        float TotalRecursive(float=0,int=0);
        void  toString();                    //Output Properties

};

#endif	/* SAVINGSACCOUNT_H */