/* 
 * File:   main.cpp
 * Author: David Haro
 * Gaddis chapter 10, Problem 1
 * Purpose: This program will receive input from user
 * in form of a string and will return the string length. 
 * This is to be done by passing the string as a pointer to a function.
 *
 * Created on October 1, 2014, 2:37 PM
 */
//Libraries
#include <string>
#include <cstring>
#include <iostream>
#include <cstdlib>
using namespace std;
//Function prototypes
int phlength(char*);

//Execute
int main(int argc, char** argv) {
    //declare variables
    char *phrase;
    int wrdSize=0;
    char choice;
    do{
        //State Purpose
        cout<<"This program will accept a word in form of a string and\n"
            <<"display the word(string) size."<<endl<<endl;
        //User Input
        cout<<"Please enter a word: ";
        cin>>phrase;
        //Pass argument
        wrdSize=phlength(phrase);
        //Output Result
        cout<<"The length of your word is: "
            <<wrdSize<<endl;
        //repeat program?
        do{                                                   //input validation
            cout<<"Would you like to try again? (y|n)";
            cin>>choice;
        }while(choice!='y'&&choice!='Y'&&choice!='n'&&choice!='N');
    }while(choice=='y'||choice=='Y');
    return 0;
}
int phlength(char* word){
    return strlen(word);
}
