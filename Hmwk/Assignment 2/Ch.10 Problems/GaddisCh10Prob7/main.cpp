/* 
 * File:   main.cpp
 * Author: David Haro
 * Gaddis Chapter 10 Problem 7
 * The purpose of this program is to save a name, middle name and last name 
 * in their own unique arrays and rearrange them in the following
 * order: lastname, firstname middlename
 *
 * Created on October 1, 2014, 4:43 PM
 */

#include <cstdlib>
#include <string>
#include <cstring>
#include <iostream>
using namespace std;

void conCatStr(string,string,string);
/*
 * 
 */
int main(int argc, char** argv) {
    //declare variables
    string first;
    string middle;
    string last;
    string out;
    int size;
    char choice;
    do{
        //State Purpose
        cout<<"This program will prompt for your first, middle and last names\n"
            <<"and display them in (Last, First Middle) format."<<endl<<endl;
        //User Input
        do{
                cout<<"Please enter your first name: ";
                getline(cin,first);
                cin.ignore();
        }while(first[0]==' '||first[0]==NULL);
        do{
                cout<<"Please enter your middle name: ";
                getline(cin,middle);
                cin.ignore();
        }while(middle[0]==' '||middle[0]==NULL);
        do{
                cout<<"Please enter your last name: ";
                getline(cin,last);
                cin.ignore();
        }while(last[0]==' '||last[0]==NULL);
        //Concatenate char arrays(Copy char arrays to 1 array)
        conCatStr(first,middle,last);
        
        
        //repeat program?
        do{                                                 //input validation
            cout<<"\n\nWould you like to try again? (y|n)";
            cin>>choice;
            cin.ignore();
        }while(choice!='y'&&choice!='Y'&&choice!='n'&&choice!='N');
    }while(choice=='y'||choice=='Y');
    return 0;
}

void conCatStr(string first, string middle, string last){
    int firstsize = first.length();
    int midsize=middle.length();
    int lastsize=last.length();
    int nuSize=firstsize+midsize+lastsize+3;            //+1 for \0
    char nuArry[nuSize];
    char temp1, temp2;
    bool flag=true;
    
    
    //test for successful pass
    cout<<"conCatStr: "<<first<<" "<<middle<<" "<<last<<endl;
    cout<<"first name length: "<<firstsize<<endl;
    cout<<"middle name length: "<<midsize<<endl;
    cout<<"last name length: "<<lastsize<<endl;
    cout<<"Size of new array: "<<nuSize<<endl;
    
    //add strings to single array
    for(int x=1;x<=3;x++){
        switch(x){
            case 1:for(int i=0;i<lastsize;i++){
                    nuArry[i]=last[i];
                   }
            nuArry[lastsize]=',';
            nuArry[lastsize+1]=' ';
                break;
            case 2:for(int i=0;i<firstsize;i++){
                    nuArry[i+lastsize+2]=first[i];
                   }
                   nuArry[firstsize+lastsize+2]=' ';
                break;
            case 3:for(int i=0;i<midsize;i++){
                    nuArry[i+lastsize+firstsize+3]= middle[i];
                   }
                break;
        } 
    }
    for(int i=0;i<nuSize;i++){
        cout<<nuArry[i];
    }
}