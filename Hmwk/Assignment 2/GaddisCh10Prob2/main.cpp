/* 
 * File:   main.cpp
 * Author: David Haro
 * Gaddis chapter 10, Problem 2
 * Purpose: This program will receive input from user
 * in form of a string and will return the string spelled backwards. 
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
void reverse(char*);

//Execute
int main(int argc, char** argv) {
    //declare variables
    char *phrase;
    char choice;
    do{
        //State Purpose
        cout<<"This program will accept a word in form of a string and\n"
            <<"display the word(string) spelled backwards."<<endl<<endl;
        //User Input
        cout<<"Please enter a word: ";
        cin>>phrase;
        //Pass argument
        reverse(phrase);
        //repeat program?
        do{                                                   //input validation
            cout<<"\n\nWould you like to try again? (y|n)";
            cin>>choice;
        }while(choice!='y'&&choice!='Y'&&choice!='n'&&choice!='N');
    }while(choice=='y'||choice=='Y');
    return 0;
}
void reverse(char* word){
    //size word
    int size=strlen(word);
    //reverse and display order
    cout<<"This is your word spelled backwards: ";
    for(int i=size;i>=0;i--){
        cout<<word[i];
    }
}
