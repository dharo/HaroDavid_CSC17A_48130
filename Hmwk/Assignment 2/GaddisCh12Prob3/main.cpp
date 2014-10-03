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
void fnlLine(fstream&);
int main(int argc, char** argv) {

    string input;       // To hold file input
    fstream joke, punch;   // File stream object
    
    joke.open("joke.txt", ios::in);
    punch.open("punchline.txt", ios::in);
    
    showFile(joke);
    //getline(punch, input);
    //cout<<input;
    return 0;
}

void showFile(fstream &file){
    string line;
    do{
        getline(file, line);
        cout<<line<<endl;
    }while(!file.eof());
}
void fnlLine(fstream &file){
    
}