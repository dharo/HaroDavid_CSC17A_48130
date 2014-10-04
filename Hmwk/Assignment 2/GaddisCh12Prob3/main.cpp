/* 
 * File:   main.cpp
 * Author: davidharo
 * 
 * Created on October 3, 2014, 3:38 PM
 */

 #include <iostream>
 #include <fstream>
 #include <string>
using namespace std;

/*
 * 
 */

void showFile(fstream&);
void readLine(fstream&);
int main(int argc, char** argv) {
    //Declare Variables
    string input;       // To hold file input
    fstream joke, punch;   // File stream object
    char choice;        // Hold user input for repeating program
    do{
        //Open Files
        joke.open("joke.txt", ios::in);
        punch.open("punchline.txt", ios::in);

        cout<<"Gaddis Chapter 12 Problem 3"
            <<"This Program will open a file containing a joke and \n"
            <<"send it to a function to be displayed. Then another file\n"
            <<"contating the punchline to the joke will be sne to a different\n"
            <<"function to look for the last line in the file to display.\n\n\n";

        //Send files to functions
        showFile(joke);
        readLine(punch);
        //close files
        joke.close();
        punch.close();
    //repeat program?
    do{                                                   //input validation
            cout<<"\n\nWould you like to try again? (y|n)";
            cin>>choice;
        }while(choice!='y'&&choice!='Y'&&choice!='n'&&choice!='N');
    }while(choice=='y'||choice=='Y');
    return 0;
}

void showFile(fstream &file){
    string line;
    
    do{
        getline(file, line);
        cout<<line<<endl;
    }while(!file.eof());
}
void readLine(fstream &file){
    string line;
    int numLines;
    while(file){
        getline(file,line);
        numLines++;
        //cout<<numLines<<endl;
    }
    
    cout<<"\n\n----Now Reading Punchline!----\n\n";
    for(int i=0;i<=numLines;i++){
        getline(file,line);
        if(i==numLines-1){
            cout<<line<<endl;
        }
    }
}