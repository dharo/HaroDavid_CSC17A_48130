/* 
 * File:   main.cpp
 * Author: David Haro
 * Due: September 8, 2014 by 11:59PM
 * Purpose:  Review Chapters 1-8 for Gaddis C++
 */
//Libraries
#include <cstdlib>
#include <iostream>
#include <fstream>
#include <iomanip>
using namespace std;

//function prototypes
float celsius(int);                     //For Problem 5
int biSearch(string[],string,int);      //For Problem 7
void print(string[],int);               //For Problem 7
void sort(string[],int);                //For Problem 7
void sumNavg(int [],int,int&,float&);   //For Problem 6
void sort(int [],int,int&,int&);        //For Problem 6
void print(int [],int);                 //For problem 6
void fill(int [],int);                  //For Problem 6
void Menu();                            //For Menu v
int getN();
void def(int);
void problem1();
void problem2();
void problem3();
void problem4();
void problem5();
void problem6();
void problem7();                        //For Menu ^


//Begin execution
int main(int argc, char** argv) {
	int inN;
        do{
         Menu();
         inN=getN();
         switch(inN){
          case 1:    problem1();break;
          case 2:    problem2();break;
          case 3:    problem3();break;
          case 4:    problem4();break;
          case 5:    problem5();break;
          case 6:    problem6();break;
          case 7:    problem7();break;

          default:   def(inN);}
        }while(inN>=1&&inN<=7);
        return 0;
}

//Menu Functions
void Menu(){
           cout<<"Type 1 for Gaddis Ch.3 Prob. 12"<<endl;
           cout<<"Type 2 for Gaddis Ch.3 Prob. 13"<<endl;
           cout<<"Type 3 for Gaddis Ch.4 Prob. 10"<<endl;
           cout<<"Type 4 for Gaddis Ch.5 Prob. 11"<<endl;
           cout<<"Type 5 for Gaddis Ch.6 Prob. 7"<<endl;
           cout<<"Type 6 for Gaddis Ch.7 Prob. 6"<<endl;
           cout<<"Type 7 for Gaddis Ch.8 Prob. 7"<<endl;
           cout<<"Type anything else to exit \n"<<endl;
    }
int getN(){             //Hold value for Menu Choice
           int inN;
		   cin>>inN;
           return inN;
    }
void problem1(){
    //declare repeat value
    char repeat;
    do{
        
        cout<<"Gaddis Chapter 3 Problem 12: Monthly Sales Tax\n";
        //Declare constants and variables
        const float CNTY_TAX = 2.0e-2;              //county sales tax
        const float STTE_TAX = 4.0e-2;              //state sales tax
        float total_SLS = 0;                        //total amount collected
        float totlSlsTX = 0;                        //total + tax
        float calc_CNTY_TAX = 0;   //calculated county sales tax
        float calc_STTE_TAX = 0;   //calculated state sales tax
        float total = 0;
        short year;
        string month;

        //Display purpose
        cout<<"This program will prompt for month, year and amount collected\n"
                "at register and add sales tax.\n";
        //prompt for user input
        cout<<"Month: ";
        cin>>month;
        cout<<"Year: ";
        cin>>year;
        cout<<"Input total amount collected at register: $";
        cin>>total_SLS;
        //calculate

        calc_CNTY_TAX = CNTY_TAX*total_SLS;
        calc_STTE_TAX = STTE_TAX*total_SLS;
        totlSlsTX = calc_CNTY_TAX + calc_STTE_TAX;
        total = total_SLS + totlSlsTX;

        //display results
        cout<<showpoint<<fixed<<setprecision(2)<<endl;
        cout<<"Month: "<<month<<endl;
        cout<<"------------------------------\n";
        cout<<"Total Collected:  $"<<setw(9)<<total<<endl;
        cout<<"Sales:            $"<<setw(9)<<total_SLS<<endl;
        cout<<"County Sales Tax: $"<<setw(9)<<calc_CNTY_TAX<<endl;
        cout<<"State Sales Tax:  $"<<setw(9)<<calc_STTE_TAX<<endl;
        cout<<"Total Sales Tax:  $"<<setw(9)<<totlSlsTX<<endl;
        
        
        //Ask user if they would like to repeat the program 
        cout<<"Would you like to repeat the program? Enter Y"<<endl;
        cout<<"to repeat or enter anything else to exit:"; 
        cin>>repeat; 
        system("CLS");
        cin.ignore(); 
    }while(repeat=='Y'||repeat=='y');
        
        //Exit Problem 1
        cout<<"\n\nExited Problem 1\n\n";
        
    }
void problem2(){
    //declare repeat value
    char repeat;
    do{
        
        //Declare Variables 
        const float         PAVALUE=6.0e-1,          //60%
                            PTVALUE=6.4e-3;          //64cents for every $100
        float               pptyVal=0,
                            pptyTax=0,
                            assVal=0;
        //Display Purpose
        cout<<"This program will calculate the property tax based on your property value.\n";
        cout<<"Please enter the value of your property/land: $";
        cin>>pptyVal;
        //calculate
        assVal=pptyVal*PAVALUE;     //assessment value = 60% of Property Value
        pptyTax=assVal*PTVALUE;     //Proprty Tax = $0.0064 for every $1
        //Format and Display Results
        cout<<fixed<<setprecision(2);
        cout<<"Property Value:"<<setw(5)<<"$"<<setw(10)<<pptyVal<<endl;
        cout<<"Assessment Value:"<<setw(3)<<"$"<<setw(10)<<assVal<<endl;
        cout<<"Property Tax:"<<setw(7)<<"$"<<setw(10)<<pptyTax<<endl;
        
                //Ask user if they would like to repeat the program 
                cout<<"Would you like to repeat the program? Enter Y"<<endl;
                cout<<"to repeat or enter anything else to exit:"; 
                cin>>repeat; 
                system("CLS");
                cin.ignore(); 
    }while(repeat=='Y'||repeat=='y');
        
        cout<<"\n\nExited Problem 2\n\n";
        
    }
void problem3(){
    //declare repeat value
    char repeat;
    do{
            //Declare variables
            const int   TWNTYPCT=20,              //Constant Discount Percentages
                        THRTYPCT=30,
                        FORTYPCT=40,
                        FIFYPCT=50;
            int         swSales=0,                //Software sales
                        discApl=0;                //Discount Applied
            //Display Purpose
            cout<<"This program will calculate discounts based on software sales.\n";
            do{
                cout<<"Enter the amount of software units sold: ";
                cin>>swSales;
            }while(swSales<1);                    //check if sales > 0
            //Determine Discount Applied.
            if(swSales>=10 && swSales<=19) discApl=TWNTYPCT;
            else if(swSales>=20 && swSales<=49) discApl=THRTYPCT;
            else if(swSales>=50 && swSales<=99) discApl=FORTYPCT;
            else if(swSales>=100) discApl=FIFYPCT; 
            //Display Discount Qualified
            cout<<"According to software sales of "<<swSales<<". The Discount applied\n"
                    <<discApl<<"%.\n"<<endl;

                    //Ask user if they would like to repeat the program 
                    cout<<"Would you like to repeat the program? Enter Y"<<endl;
                    cout<<"to repeat or enter anything else to exit:"; 
                    cin>>repeat; 
                    system("CLS");
                    cin.ignore(); 
       }while(repeat=='Y'||repeat=='y');
        
        //exit
        cout<<"\n\nExited Problem 3\n\n";
        
    }
void problem4(){
    //declare repeat value
    char repeat;
    do{
            //Declare Variables
            int         orgnsm=0,
                        days=0;
            float       popIncr=0,
                        popltn=0;

            //Display purpose
            cout<<"This program will calculate the population of a set of organisms"<<endl;
            //Prompt for user input.
            do{                         //Check to make sure organisms can reproduce
                cout<<"Enter the starting number of organisms: ";
                cin>>orgnsm;
            }while(orgnsm<2);
            do{
                cout<<"Enter the average daily population increase as a %: ";
                cin>>popIncr;
            }while(popIncr<0);
            do{                         //Organisms need time to reproduce
                cout<<"Enter the number of days the organisms will be alive: ";
                cin>>days;
            }while(days<1);
            //Calculate data
            for(int i=1; i<=days; i++){
                popltn=(orgnsm*(popIncr*1.0e-2*i))+orgnsm;
                cout<<"Day: "<<i<<": ";
                cout<<popltn<<endl;
            }
            //Ask user if they would like to repeat the program 
            cout<<"Would you like to repeat the program? Enter Y"<<endl;
            cout<<"to repeat or enter anything else to exit:"; 
            cin>>repeat; 
            system("CLS");
            cin.ignore(); 
        }while(repeat=='Y'||repeat=='y');
        //exit
        cout<<"\n\nExited Problem 4\n\n";
        
    }
void problem5(){
    //declare repeat value
    char repeat;
    
    do{
                //Declare Variables
                float conv=0;
                int fahrenheit=0;
                //Display Purpose
                cout<<"This program will display a table of Conversion from \n"
                        "Fahrenheit to Celsius\n"<<endl;
                for(int i=0; i<=20;i++){
                    fahrenheit=i;
                    conv=celsius(fahrenheit);
                    cout<<fixed<<setprecision(2);                 //Calcualte to 2nd decimal
                    cout<<"Fahrenheit: "<<fahrenheit<<" Celsius: "<<conv<<endl;
                }
                    //Ask user if they would like to repeat the program 
                    cout<<"Would you like to repeat the program? Enter Y"<<endl;
                    cout<<"to repeat or enter anything else to exit:"; 
                    cin>>repeat; 
                    cin.ignore(); 
        }while(repeat=='Y'||repeat=='y');
        //exit
            cout<<"\n\nExited Problem 5\n\n";
    }
void problem6(){
    //Declare repeat variable
    char repeat;
    
    do{
       //Declare Variables
       const int SIZE=25;
       int array[SIZE]={};
       int high=0,low=0,sum=0;
       float avg;

       //Fill and print the array for the first time
       fill(array,SIZE);
       print(array,SIZE);

       //Sort the array and print again
       sort(array,SIZE,high,low);
       print(array,SIZE);

       //Find the sum and average of the array elements
       sumNavg(array,SIZE,sum,avg);        

       //Output results to user
       cout<<"               Array Statistics "<<endl<<endl;
       cout<<"High: "<<high<<endl;
       cout<<"Low: "<<low<<endl;
       cout<<"Total: "<<sum<<endl;
       cout<<"Average: "<<avg<<endl;


       //Ask user if they would like to repeat the program 
       cout<<"Would you like to repeat the program? Enter Y"<<endl;
       cout<<"to repeat or enter anything else to exit:"; 
       cin>>repeat;  
       }while(repeat=='Y'||repeat=='y');

        //End of program
        
    }
void problem7(){
            //Declare repeat variable
            char repeat;
            string value;
            do{
                //Declare Variables
                const int SIZE = 20;
                int foundIn=0;
                string nameAry[SIZE]={"Collins, Bill","Smith, Bart","Allen, Jim","Griffin, Jim","Stamey, Marty",
                              "Rose, Geri","Taylor, Terri","Johnson, Jill","Alison, Jeff","Looney, Joey",
                              "Wolfe, Bill","James, Jean","Weaver, Jim","Pore, Bob","Rutherford, Greg",
                              "Javens, Renee","Harrison, Rose","Setzer, Cathy","Pike, Gordon","Holland, Beth"};

                cin.ignore();
                cout<<endl;
                //Print the unsorted array
                print(nameAry,SIZE);

                //Have the user input a name to search for
                cout<<"Enter one of the names exactly as it appears to search for it:";

                getline(cin,value);
                cout<<endl;

                //Sort the array of names
                sort(nameAry,SIZE);
                print(nameAry,SIZE);//Print the array again

                //Search for a string value using the binary search
                foundIn=biSearch(nameAry,value,SIZE);

                //Output results to user
                if(foundIn>-1){
                   cout<<value<<" was found in subscript number "<<foundIn<<"."<<endl;}
                else{
                   cout<<value<<" was not found in the array."<<endl;}    

                //Ask user if they would like to repeat the program 
                cout<<"Would you like to repeat the program? Enter Y"<<endl;
                cout<<"to repeat or enter anything else to exit:"; 
                cin>>repeat; 
                system("CLS");
                cin.ignore(); 
           }while(repeat=='Y'||repeat=='y');

            //End of program
           cout<<"\n\nExited Problem 7\n\n";
            
        
    }
void def(int inN){
           cout<<"You typed "<<inN<<" to exit the program"<<endl;
    }
    
//Problem Functions
float celsius(int f){
    //declare/initialize Celsius
    float c=(0.55555555)*(f-32);
    //return value to main
    return c;
}
void sort(string array[],int size){
    for(int i=0;i<size-1;i++){
        for(int j=i+1;j<size;j++){
            if(array[j]<array[i]){
            string temp = array[i];
            array[i] = array[j];
            array[j] = temp;}}}
}
void print(string array[],int size){
    for(int i=0;i<size;i++){
        cout<<array[i]<<" | ";
        if(i%5==4){ cout<<endl;}
    }
    cout<<endl;
}       
int biSearch(string array[],string value, int size){
    int low=0, high=size-1, position = -1, middle;
    bool found = false;
    
    while(!(found)&&low<=high){
       middle = (high+low)/2;
       if(array[middle]==value){
          found=true;
          position=middle;}
       else if(array[middle]>value){
          high=middle-1;}
       else{
          low=middle+1;}     
    } 
    return position;
}
void fill(int array[],int size){
   ifstream istream;
   istream.open("Numbers.dat");
   
   for(int i=0;i<size;i++){
        int temp;
        istream>>array[i];}
            
   istream.close();
}
void print(int array[],int size){
    for(int i=0;i<size;i++){
        cout<<array[i]<<" ";
        if(i%5==4){cout<<endl;}}
   cout<<endl;
}
void sort(int array[],int size,int& high, int& low){
    
    for(int i=0;i<size-1;i++){
        for(int j=i+1;j<size;j++){
           if(array[j]<array[i]){
               int temp=array[i];
               array[i]=array[j];
               array[j]=temp;}}}
    low=array[0];
    high=array[size-1];
   cout<<endl;
}
void sumNavg(int array[],int size,int& sum,float& avg){
   for(int i=0;i<size;i++){
        sum+=array[i];}    
   avg=sum/static_cast<float>(size); 
}