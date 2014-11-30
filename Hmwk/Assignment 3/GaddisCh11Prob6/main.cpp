/* 
 * File:   main.cpp
 * Author: davidharo
 *
 * Gaddis Chapter 11 Problem 6
 * Soccer PLayers
 */

#include <cstdlib>
#include <iostream>
#include <string>
using namespace std;

struct Player{
    string name;
    int num;
    int points;
};

int totPoints(Player a[],const int);
Player topScore(Player a[],const int);

int main(int argc, char** argv) {
    //initialize team
    const int SIZE=3;
    Player a[SIZE];
    
    
    //Prompt for user input
    for(int i=0;i<SIZE;i++){
        cout<<"Please enter the Player's Name, NUmber, and Points Scored: \n";
        cout<<"Player "<<i+1<<" name: ";
        cin>>a[i].name;
        cout<<"Player "<<i+1<<" number: ";
        cin>>a[i].num;
        cout<<"Player "<<i+1<<" Points Scored: ";
        cin>>a[i].points;
    }
    cout<<"\n\n\n";
    cout<<"Total Team Points Scored: "<<totPoints(a,SIZE)<<endl;
    cout<<"Top Scorer: "<<topScore(a,SIZE).name<<" with "<<topScore(a,SIZE).points<<" points scored!"<<endl;
    return 0;
}

int totPoints(Player a[],const int SIZE){
    //sum the teams goals
    int teamScore=0;
    for(int i=0;i<SIZE;i++){
        teamScore+=a[i].points;
    }
    return teamScore;
}

Player topScore(Player a[],const int SIZE){
    Player top;
 
    int max=0;
    for(int i=0;i<SIZE;i++){
        if(a[i].points>max){
            max=a[i].points;
            top=a[i];
        }
        

    }
    return top;
}