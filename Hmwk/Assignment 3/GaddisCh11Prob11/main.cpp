/* 
 * File:   main.cpp
 * Author: davidharo
 *
 * Gaddis Chapter 11 Problem 11
 * Month;y Budget
 * 
 * Housing 500.00
Utilities 150.00
Household Expenses 65.00
Transportation 50.00
Food 250.00
Medical 30.00
Insurance 100.00
Entertainment 150.00
Clothing 75.00
Miscellaneous 50.00
 * 
 * 
 * 
 * 
 * 
 * 
 */
#include <iostream>
#include <cstdlib>
#include <string>
#include <iomanip>
using namespace std;

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

void usrInpt(MonBud);
void ovrUndr(MonBud,MonBud);
/*
 * 
 */
int main(int argc, char** argv) {
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
    
    return 0;
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