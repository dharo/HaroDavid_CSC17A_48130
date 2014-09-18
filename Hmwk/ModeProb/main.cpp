/* 
 * File:   main.cpp
 * Author: David Haro
 * Purpose: This program will take in an array of numbers and display
 * them in a sorted manner, and display the set's mean, median and mode(s).
 *
 * Created on September 16, 2014, 3:55 PM
 */
//Libraries
#include <cstdlib>
#include <ctime>
#include <iostream>
using namespace std;

//Constants: NA

//Function Prototypes
void generate ();
void sortAry(int[], int);
void prntAry(int[], int);
void mean(int [],int);
void median(int [],int);
int *mode(int [],int);
//Execute
int main(int argc, char** argv) {
    //Generate Array to be sorted and product determined
    generate();
    
    return 0;
}

void generate (){
    //Declare Variables
    int SIZE;
    srand(time(NULL));
    //This Function will generate an array
    cout<<"Enter SIZE of array: ";
    cin>>SIZE;
    //Build Array
    int num[SIZE];
    //Generate an array of random numbers between 0-5
    for(int i=0; i<SIZE;i++){
            num[i]=rand()%6;                    //Array element = randnum between 0-5
            cout<<num[i]<<" ";
    }
    cout<<endl;
    //Export array to be sorted
    sortAry(num, SIZE);
}

void sortAry(int num[], int SIZE){
    //This Function takes in an array and begins a sort.
    bool swap;
    int temp;
    cout<<"Sorting has begun...\n";
    do{
        swap=false;
        for(int i=0; i<(SIZE-1); i++){
            if(num[i]>num[i+1]){
                temp=num[i];
                num[i]=num[i+1];
                num[i+1]=temp;
                swap=true;
            }
        }
    }while(swap);
    //Print Sorted Array
    for(int j=0;j<SIZE;j++){
        cout<<num[j]<<" ";
    }
    cout<<endl<<endl;
    //Send to get the average (MEAN)
    mean(num ,SIZE);
}
void mean(int num[],int SIZE){
    float mean, sum=0;
    //This Function will determine the mean of the array (average number)
    cout<<"The MEAN of this array \n";
    for(int j=0;j<SIZE;j++){
        cout<<num[j]<<" ";
    }
    cout<<endl;
    //Calculate MEAN
    for(int i=0;i<SIZE;i++){
        sum+=num[i];
    }
    mean=sum/SIZE;
    cout<<"MEAN: "<<mean;
    cout<<"\n\n";
    //pass array to retrieve Median
    median(num, SIZE);
}

void median(int num[],int SIZE){
    int med_pos1, med_pos2, oddMed;
    float medianSUM, median;
    //This Function will determine the median number of the array
    cout<<"The MEDIAN of this array \n";
    for(int j=0;j<SIZE;j++){
        cout<<num[j]<<" ";
    }
    cout<<endl;
    if(SIZE%2==0){              //if EVEN
        med_pos1=SIZE/2;        
        med_pos2=SIZE/2-1;      //go back 1 position to get 2nd middle number
        medianSUM=num[med_pos1]+num[med_pos2];
        median=medianSUM/2;
        
    }
    else if(SIZE%2!=0){         //if ODD
        oddMed=((SIZE-1)/2);    //Minus 1 because index starts at 0
        median=num[oddMed];
    }
    cout<<"MEDIAN: "<<median<<endl<<endl;
    
    mode(num,SIZE);
}
int *mode(int num[],int SIZE){
    int temp_freq=1;            //Checking if instance > 1
    int max_freq=1;             //Max # times number appears
    //int numVal=-1;          //Number value being compared
    
    
    for (int i=0;i<SIZE;i++){
        int numVal=num[i];
        if(numVal==num[i+1]){
            temp_freq++;
        }
        if(temp_freq>max_freq){
            max_freq=temp_freq;
        }
        if(numVal!=num[i+1]){
            temp_freq=1;
        }
    }
    cout<<"THIS IS THE HIGHEST FREQ: "<<max_freq<<endl;
    
    return 0;
}