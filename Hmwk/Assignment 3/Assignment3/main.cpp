/* 
 * File:   main.cpp
 * Author: David haro
 * Book: Gaddis 7th Edition
 * Chapter 11

 */


#include <cstdlib>
#include <iostream>
#include <string>
#include <iomanip>

using namespace std;

//structures
//problem 1
struct MovieData{
    string title;
    string director;
    int year;
    int movLen;
    int prodCost;
    int revenue;
};
//problem 2
struct Movie_Data{
    string title;
    string director;
    int year;
    int movLen;
    int prodCost;
    int revenue;
};
//problem 3
struct SalesData{
    string divName;
    float firstSls;
    float secSls;
    float thrdSls;
    float frthSls;
};
//problem 4
struct Weather{
    string month;
    int totRain;
    int hiTmp;
    int loTmp;
    int avgTmp;
};
//problem 5
struct Weathera{
    string month;
    int totRain;
    int hiTmp;
    int loTmp;
    int avgTmp;
};
enum Month {JAN,FEB,MAR,APR,MAY,JUN,JUL,AUG,SEP,OCT,NOV,DEC};
//problem 6
struct Player{
    string name;
    int num;
    int points;
};
//problem 7
struct MonBud{
    float hous;
    float util;
    float housexp;
    float trans;
    float food;
    float med;
    float ins;
    float ent;
    float cloth;
    float misc;
};



//prototypes
void Menu();
int getN();
void def(int);
void problem1();
void problem2();
void problem3();
void problem4();
void problem5();
void problem6();
void problem7();
//Problem 1
void dispMov(MovieData);
//preoblem 2
void dispMov(Movie_Data);
int profit(Movie_Data);
//problem 3
void dspData(SalesData);
float totannsales(SalesData);
float avgQuartSales(SalesData);
//problem 4
int avgTemp(Weather a[], const int);
int avgRain(Weather a[], const int);
int totRain(Weather a[], const int);
Weather hiTemp(Weather a[], const int);
Weather loTemp(Weather a[], const int);
//problem 5
int avg_Temp(Weathera a[], const int);
int avg_Rain(Weathera a[], const int);
int tot_Rain(Weathera a[], const int);
Weathera hi_Temp(Weathera a[], const int);
Weathera lo_Temp(Weathera a[], const int);
//problem 6
int totPoints(Player a[],const int);
Player topScore(Player a[],const int);
//problem 7
void usrInpt(MonBud);
void ovrUndr(MonBud,MonBud);



//execute
int main(int argv,char *argc[]){
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
        }while(inN<8);
        return 1;
    }
    void Menu()
    {
           cout<<"\nType 1 for problem 11.1"<<endl;
           cout<<"Type 2 for problem 11.2"<<endl;
           cout<<"Type 3 for problem 11.3"<<endl;
           cout<<"Type 4 for problem 11.4"<<endl;
           cout<<"Type 5 for problem 11.5"<<endl;
           cout<<"Type 6 for problem 11.6"<<endl;
           cout<<"Type 7 for problem 11.11"<<endl;
           cout<<"Type 8 to exit \n"<<endl;
    }
    int getN()
    {
           int inN;
           cin>>inN;
           return inN;
    }

//----Problem 1 Chapter 11---- 
void problem1(){
    //initialize 2 MovieData variables
    MovieData movie1={"Cosmos; A Personal Voyage","Carl Sagan",1980,60};
    MovieData movie2={"Cosmos; A SpaceTime Odyssey","Neil deGrasse Tyson",2014,44};
    
    dispMov(movie1);
    dispMov(movie2);
}
void dispMov(MovieData a){
    cout<<"Title: "<<a.title<<endl;
    cout<<"Director: "<<a.director<<endl;
    cout<<"Year Released: "<<a.year<<endl;
    cout<<"Movie Run-Time: "<<a.movLen<<endl;
    cout<<endl<<endl;
}

//----Problem 2 Chapter 11---- 
void problem2(){
    //initialize 2 Movie_Data variables
    Movie_Data movie1={"Cosmos; A Personal Voyage","Carl Sagan",1980,60, 500000, 320212};
    Movie_Data movie2={"Cosmos; A SpaceTime Odyssey","Neil deGrasse Tyson",2014,44,234523,456342};
    
    
    dispMov(movie1);
    dispMov(movie2);
}
void dispMov(Movie_Data a){
    cout<<"Title: "<<a.title<<endl;
    cout<<"Director: "<<a.director<<endl;
    cout<<"Year Released: "<<a.year<<endl;
    cout<<"Movie Run-Time: "<<a.movLen<<endl;
    cout<<"First Year Profit: $"<<profit(a)<<endl;
    cout<<endl<<endl;
}

int profit(Movie_Data a){
    return a.revenue-a.prodCost;
}


//Problem 3 Chapter 11
void problem3(){
    //declare variables
    SalesData East={"East",500.21,321.43,354.74,346.89};
    SalesData West={"West",658.54,345.64,748.66,156.81};
    SalesData North={"North",868.66,628.62,264.62,686.28};
    SalesData South={"South",394.24,629.87,346.86,387.56};
    
    dspData(East);
    dspData(West);
    dspData(North);
    dspData(South);
}
void dspData(SalesData a){
    //display data in a formatted manner
    cout<<"Division: "<<a.divName<<endl;
    cout<<"First-Quarter Sales: $"<<a.firstSls<<endl;
    cout<<"Second-Quarter Sales: $"<<a.secSls<<endl;
    cout<<"Third-Quarter Sales: $"<<a.thrdSls<<endl;
    cout<<"Fourth-Quarter Sales: $"<<a.frthSls<<endl;
    cout<<"Total Annual Sales: $"<<totannsales(a)<<endl;
    cout<<"Average Quarterly Sales: $"<<avgQuartSales(a)<<endl;
    cout<<endl<<endl;
}

float totannsales(SalesData a){
    return (a.firstSls+a.secSls+a.thrdSls+a.frthSls);
}
float avgQuartSales(SalesData a){
    return (a.firstSls+a.secSls+a.thrdSls+a.frthSls)/4;
}

//problem 4 chapter 11
void problem4(){
//declare variables
    const int SIZE=3;
    Weather a[SIZE];
    
    //take input for weather data per month
        for(int i=0;i<SIZE;i++){
        cout<<"Please enter Weather Data for month "<<i+1<<": \n";
        cout<<"Month Name:";
        cin>>a[i].month;
        cout<<"Total Rain: ";
        cin>>a[i].totRain;
        cout<<"Highest Temperature: ";
        cin>>a[i].hiTmp;
        cout<<"Lowest Temperature: ";
        cin>>a[i].loTmp;
        //calculate avg temperature
        a[i].avgTmp=(a[i].hiTmp+a[i].loTmp)/2;
    }
    cout<<"Average RainFall: "<<avgRain(a,SIZE)<<endl;
    cout<<"Total RainFall: "<<totRain(a,SIZE)<<endl;
    cout<<"Average Temperature: "<<avgTemp(a,SIZE)<<endl;
    cout<<"Highest Temp: "<<hiTemp(a,SIZE).month<<": "<<hiTemp(a,SIZE).hiTmp<<endl;
    cout<<"Lowest Temp: "<<loTemp(a,SIZE).month<<": "<<loTemp(a,SIZE).loTmp<<endl;
}
int avgRain(Weather a[], const int SIZE){
    int avgRain=0;
    for(int i=0;i<SIZE;i++){
        avgRain+=a[i].totRain;
    }
    return avgRain/SIZE;
}
int totRain(Weather a[], const int SIZE){
    int total=0;
    for(int i=0;i<SIZE;i++){
        total+=a[i].totRain;
    }
    return total;
}
int avgTemp(Weather a[], const int SIZE){
    int avgTemp=0;
    for(int i=0;i<SIZE;i++){
        avgTemp+=a[i].avgTmp;
    }
    return avgTemp/SIZE;
}
Weather hiTemp(Weather a[], const int SIZE){
    Weather top;
    int max=-999;
    for(int i=0;i<SIZE;i++){
        if(a[i].hiTmp>max){
            max=a[i].hiTmp;
            top=a[i];
        }
    }
    return top;
}
Weather loTemp(Weather a[], const int SIZE){
    Weather low;
    int min=99999;
    for(int i=0;i<SIZE;i++){
        if(a[i].loTmp<min){
            min=a[i].loTmp;
            low=a[i];
        }
    }
    return low;
}
 

 
//problem 5 chapter 11
void problem5(){
    //declare variables
    const int SIZE=12;
    Weathera a[SIZE];
    
    //take input for weather data per month
        for(int i=JAN;i<DEC;i++){
        cout<<"Please enter Weather Data for month "<<i+1<<": \n";
        cout<<"Month Name:";
        cin>>a[i].month;
        cout<<"Total Rain: ";
        cin>>a[i].totRain;
        cout<<"Highest Temperature: ";
        cin>>a[i].hiTmp;
        cout<<"Lowest Temperature: ";
        cin>>a[i].loTmp;
        //calculate avg temperature
        a[i].avgTmp=(a[i].hiTmp+a[i].loTmp)/2;
    }
    cout<<"Average RainFall: "<<avg_Rain(a,SIZE)<<endl;
    cout<<"Total RainFall: "<<tot_Rain(a,SIZE)<<endl;
    cout<<"Average Temperature: "<<avg_Temp(a,SIZE)<<endl;
    cout<<"Highest Temp: "<<hi_Temp(a,SIZE).month<<": "<<hi_Temp(a,SIZE).hiTmp<<endl;
    cout<<"Lowest Temp: "<<lo_Temp(a,SIZE).month<<": "<<lo_Temp(a,SIZE).loTmp<<endl;

}
int avg_Rain(Weathera a[], const int SIZE){
    int avgRain=0;
    for(int i=0;i<SIZE;i++){
        avgRain+=a[i].totRain;
    }
    return avgRain/SIZE;
}
int tot_Rain(Weathera a[], const int SIZE){
    int total=0;
    for(int i=0;i<SIZE;i++){
        total+=a[i].totRain;
    }
    return total;
}
int avg_Temp(Weathera a[], const int SIZE){
    int avgTemp=0;
    for(int i=0;i<SIZE;i++){
        avgTemp+=a[i].avgTmp;
    }
    return avgTemp/SIZE;
}
Weathera hi_Temp(Weathera a[], const int SIZE){
    Weathera top;
    int max=-999;
    for(int i=0;i<SIZE;i++){
        if(a[i].hiTmp>max){
            max=a[i].hiTmp;
            top=a[i];
        }
    }
    return top;
}
Weathera lo_Temp(Weathera a[], const int SIZE){
    Weathera low;
    int min=99999;
    for(int i=0;i<SIZE;i++){
        if(a[i].loTmp<min){
            min=a[i].loTmp;
            low=a[i];
        }
    }
    return low;
}

//problem 6 chapter 11
void problem6(){
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

//problem 11 chapter 11
void problem7(){
        //initialize variables
    MonBud budget={500,150,65,50,250,30,100,150,75,50};
    
    //display budget in a formatted manner
    cout<<showpoint<<fixed<<setprecision(2)<<endl;
    cout<<setw(25);
    cout<<"Budget"<<endl;
    cout<<"Housing:$ "<<right<<setw(31)<<budget.hous<<endl;
    cout<<"Utilities:$ "<<right<<setw(29)<<budget.util<<endl;
    cout<<"Household Expenses:$ "<<right<<setw(20)<<budget.housexp<<endl;
    cout<<"Transportation:$ "<<right<<setw(24)<<budget.trans<<endl;
    cout<<"Food:$ "<<right<<setw(34)<<budget.food<<endl;
    cout<<"Medical:$ "<<right<<setw(31)<<budget.med<<endl;
    cout<<"Insurance:$ "<<right<<setw(29)<<budget.ins<<endl;
    cout<<"Entertainment:$ "<<right<<setw(25)<<budget.ent<<endl;
    cout<<"Clothes:$ "<<right<<setw(31)<<budget.cloth<<endl;
    cout<<"Miscellaneous:$ "<<right<<setw(25)<<budget.misc<<endl;
    
    usrInpt(budget);
}
void usrInpt(MonBud bud){
    MonBud user;
    
    cout<<"Please Fill in your expenses this month: \n";
    cout<<"Housing:$ ";
    cin>>user.hous;
    cout<<"Utilities:$ ";
    cin>>user.util;
    cout<<"Household Expenses:$ ";
    cin>>user.housexp;
    cout<<"Transportation:$ ";
    cin>>user.trans;
    cout<<"Food:$ ";
    cin>>user.food;
    cout<<"Medical:$ ";
    cin>>user.med;
    cout<<"Insurance:$ ";
    cin>>user.ins;
    cout<<"Entertainment:$ ";
    cin>>user.ent;
    cout<<"Clothes:$ ";
    cin>>user.cloth;
    cout<<"Miscellaneous:$ ";
    cin>>user.misc;
    cout<<endl<<endl;
    ovrUndr(bud,user);
}

void ovrUndr(MonBud bud,MonBud user){
    //checks if over or under and displays message
    float budTotal;
    float actTotal;

    budTotal=bud.cloth+bud.ent+bud.food+bud.hous+bud.housexp+bud.ins+bud.med+bud.misc+bud.trans+bud.util;
    actTotal=user.cloth+user.ent+user.food+user.hous+user.housexp+user.ins+user.med+user.misc+user.trans+user.util;
    
    cout<<"Allowance for Budget: $"<<budTotal<<endl;
    cout<<"Amounts Consumed: $"<<actTotal<<endl;
    
    
    if (user.hous>bud.hous){
        cout<<"Housing Over Budget by: $"<<user.hous-bud.hous<<endl;
    }
    else{
        cout<<"Housing Under Budget by: $"<<bud.hous-user.hous<<endl;
    }
    
    if (user.util>bud.util){
        cout<<"Utilities Over Budget by: $"<<user.util-bud.util<<endl;
    }
    else{
        cout<<"Utilities Under Budget by: $"<<bud.util-user.util<<endl;
    }
    
    if (user.housexp>bud.housexp){
        cout<<"Housing Expenses Over Budget by: $"<<user.housexp-bud.housexp<<endl;
    }
    else{
        cout<<"Housing Expenses Under Budget by: $"<<bud.housexp-user.housexp<<endl;
    }
    if (user.trans>bud.trans){
        cout<<"Transportation Over Budget by: $"<<user.trans-bud.trans<<endl;
    }
    else{
        cout<<"Transportation Under Budget by: $"<<bud.trans-user.trans<<endl;
    }
    if (user.food>bud.food){
        cout<<"Food Over Budget by: $"<<user.food-bud.food<<endl;
    }
    else{
        cout<<"Food Under Budget by: $"<<bud.food-user.food<<endl;
    }
    if (user.med>bud.med){
        cout<<"Medical Over Budget by: $"<<user.med-bud.med<<endl;
    }
    else{
        cout<<"Medical Under Budget by: $"<<bud.med-user.med<<endl;
    }
    if (user.ins>bud.ins){
        cout<<"Insurance Over Budget by: $"<<user.ins-bud.ins<<endl;
    }
    else{
        cout<<"Insurance Under Budget by: $"<<bud.ins-user.ins<<endl;
    }
    if (user.ent>bud.ent){
        cout<<"Entertainment Over Budget by: $"<<user.ent-bud.ent<<endl;
    }
    else{
        cout<<"Entertainment Under Budget by: $"<<bud.ent-user.ent<<endl;
    }
    if (user.cloth>bud.cloth){
        cout<<"Clothes Over Budget by: $"<<user.cloth-bud.cloth<<endl;
    }
    else{
        cout<<"Clothes Under Budget by: $"<<bud.cloth-user.cloth<<endl;
    }
    if (user.misc>bud.misc){
        cout<<"Misc. Over Budget by: $"<<user.misc-bud.misc<<endl;
    }
    else{
        cout<<"Misc. Under Budget by: $"<<bud.misc-user.misc<<endl;
    }
}
    void def(int inN)
    {
           cout<<"You typed "<<inN<<" to exit the program"<<endl;
    }