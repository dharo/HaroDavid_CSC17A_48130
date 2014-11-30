/* 
 * File:   main.cpp
 * Author: davidharo
 * Gaddis 7th Edition Chapter 11 Problem 1
 */

#include <cstdlib>
#include <iostream>
#include <string>
using namespace std;


struct MovieData{
    string title;
    string director;
    int year;
    int movLen;
};

void dispMov(MovieData);

int main(int argc, char** argv) {
    //initialize 2 MovieData variables
    MovieData movie1={"Cosmos; A Personal Voyage","Carl Sagan",1980,60};
    MovieData movie2={"Cosmos; A SpaceTime Odyssey","Neil deGrasse Tyson",2014,44};
    
    dispMov(movie1);
    dispMov(movie2);
    return 0;
}

void dispMov(MovieData a){
    cout<<"Title: "<<a.title<<endl;
    cout<<"Director: "<<a.director<<endl;
    cout<<"Year Released: "<<a.year<<endl;
    cout<<"Movie Run-Time: "<<a.movLen<<endl;
    cout<<endl<<endl;
}