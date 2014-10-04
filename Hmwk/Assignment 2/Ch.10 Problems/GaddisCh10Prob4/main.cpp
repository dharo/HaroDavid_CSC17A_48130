/* 
 * File:   main.cpp
 * Author: David Haro
 * Gaddis chapter 10, Problem 4
 * Purpose: This program will receive input from user in form of
 * a string and will return the number of words and average word size. 
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
void wordCnt(string);

//Execute
int main(int argc, char** argv) {
    //declare variables
    string phrase;
    char choice;
    do{
        //State Purpose
        cout<<"This program will accept a word in form of a string and\n"
            <<"display the word count and average word size."<<endl<<endl;
        //User Input
        do{
                cout<<"Please enter a phrase\nPress [ENTER] 2x: ";
                getline(cin,phrase);
                cin.ignore();
        }while(phrase[0]==' '||phrase[0]==NULL);
        //Pass argument
        wordCnt(phrase);
        //repeat program?
        do{                                                 //input validation
            cout<<"\n\nWould you like to try again? (y|n)";
            cin>>choice;
            cin.ignore();
        }while(choice!='y'&&choice!='Y'&&choice!='n'&&choice!='N');
    }while(choice=='y'||choice=='Y');
    return 0;
}
void wordCnt(string word){
    //declare variables
    int sizeOfstr=word.length();
    int count=0;
    int letter=0;
    float avgSize;
    char space=' ';
    for(int i=0;i<=sizeOfstr;i++){
        if(word[i]==space)
            count++;
        if(word[i]!=' '&&word[i]!=','&&word[i]!='.'&&word[i]!='?'&&word[i]!='!')
            letter++;
    }
    count=count+1;              //index for word count starts at 0
    letter=letter-1;            //to accommodate null terminator 
    //Determine average letter size
    avgSize=letter/(static_cast<float>(count));
    cout<<"Word Count: "<<count<<endl;
    cout<<"Letter Count: "<<letter<<endl;
    cout<<"Average word size (by letter): "<<avgSize<<endl;
}


