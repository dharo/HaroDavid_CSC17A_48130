//David Haro
//October 24, 2014
//Menu to be used for the midterm
//CSC 17A: Midterm

//Library includes Here!!!
#include <cstdlib>
#include <iostream>
#include <iomanip>
#include <string>
using namespace std;


//Structures
struct BankAcc{         //Problem 1
    int accNum;
    int inBal;
    int totDbt;
    int totCrdt;
};
struct Employee {       //problem 2
    string name;
    int wrkHrs;
    float payRte;
};

//Function Prototypes Here!!!
void calcBal(BankAcc *);               //Problem 1

void dispS(Employee*);                 //problem 2
float calc(Employee*);                 //problem 2
//Prototypes Problem 4
void encrypt(int&);
void decrypt(int&);
int * swap(int *,int);
void dispArr(int*, int);
int * unswap(int *,int);
bool isValid(int);


void Menu();
int getN();
void def(int);
void problem1();
void problem2();
void problem3();
void problem4();
void problem5();
void problem6();

//Begin Execution Here!!!
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
        default:   def(inN);}
    }while(inN>=1&&inN<=6);
    return 0;//If midterm not perfect, return something other than 1
}

void Menu(){
    cout<<"Menu for the Midterm"<<endl;
    cout<<"Type 1 for problem 1"<<endl;
    cout<<"Type 2 for problem 2"<<endl;
    cout<<"Type 3 for problem 3"<<endl;
    cout<<"Type 4 for problem 4"<<endl;
    cout<<"Type 5 for problem 5"<<endl;
    cout<<"Type 6 for problem 6"<<endl;
    cout<<"Type anything else to exit \n"<<endl;
}

int getN(){
        int inN;
        cin>>inN;
        return inN;
}

void problem1(){
        cout<<"In problem # 1"<<endl<<endl;
            //declare variables
    BankAcc cust1;

    //Display purpose
    cout<<"Problem 1: Bank Account";
    cout<<"This program will prompt for a 5 digit account number\n"
        <<"and then ask for\n"
        <<"1) The balance at the beginning of the month\n"
        <<"2) The total amount withdrawn from account\n"
        <<"3) The total amount deposit into account\n"
        <<"If amount withdrawn exceeds the sum of balance and credit, \n"
        <<"a $12 charge will be applied to account.\n\n\n";
    //Prompt for user input
    do{
        cout<<"Please input your 5 digit Account Number: ";
        cin>>cust1.accNum;
    }while(cust1.accNum>99999 || cust1.accNum < 10000);
    cout<<"Accessing Account: "<<cust1.accNum<<endl;
    do{
        cout<<"Please type in your balance at the beginning of the month\n";
        cin>>cust1.inBal;
    }while(cust1.inBal<0);
    cout<<"Initial Balance: $"<<cust1.inBal<<endl;
    do{
        cout<<"Please type in your total in deposits\n";
        cin>>cust1.totCrdt;
    }while(cust1.totCrdt<0);
    cout<<"Total deposit amount: $"<<cust1.totCrdt<<endl;
    do{
        cout<<"Please type in your withdrawn amount\n";
        cin>>cust1.totDbt;
    }while(cust1.totDbt<0);
    cout<<"Total amount withdrawn: $"<<cust1.totDbt<<endl;
    //pass struct to function to create calculations
    calcBal(&cust1);
}

void problem2(){
        cout<<"In problem # 2"<<endl<<endl;
        //declare variables
    int size;
    char correct;
    cout << "Problem 2: Gross Pay"
            << "This program will prompt for how many employees you are calculating\n"
            << "paychecks for and ask for Employee name, work hours, and pay rate\n"
            << "After each employee input, gross pay will be calculated and then \n"
            << "employee info as well as calculated amounts will be displayed.\n\n\n";
    cout << "Enter number of employees: ";
    cin>>size;
    Employee* payroll = new Employee[size];

    for (int i = 0; i < size; i++) {
        do {
            cin.ignore();
            cout << "Input Employee " << i + 1 << " name: ";
            getline(cin, payroll[i].name);
            cout << "Input Hours Worked: ";
            cin >> payroll[i].wrkHrs;
            cout << "Input Pay Rate: ";
            cin >> payroll[i].payRte;
            cout << endl << endl;
            dispS(&payroll[i]);
            cout << "Verify if data is correct. Press (Y/N)";
            cin>>correct;
            cout << endl << endl;
        } while (correct == 'n' || correct == 'N');
    }

    //destroy
    delete [] payroll;
    payroll = NULL;
}

void problem3(){
        cout<<"Problem 3 was not completed"<<endl<<endl;
}

void problem4(){
        cout<<"In problem # 4"<<endl<<endl;
        //declare variables
    int crypt;              //number to be encrypted
    char a,b;
    bool valid;
    cout<<"Problem 4: Encryption"<<endl;
    cout<<"THis program will take in a 4 digit integer(using digits 0-7 and \n"
        <<"encrypt then display the number. This will be followed\n"
        <<"by decrypting it once more.\n\n";
    do{
        do{
            cout<<"Would you like to encrypt or decrypt?\n"
                <<"1) Encrypt\n"
                <<"2) Decrypt\n";
            cin>>a;
        }while(a!='1' && a!='2');
        do{
            cout<<"Input a value (digits 0-7 only): ";
            cin>>crypt;
            valid=isValid(crypt);
        }while(!valid);
        if(a=='1')
            encrypt(crypt);
        if(a=='2')
            decrypt(crypt);
        cout<<"\n\nWould you like to try again? (Y/N)";
        cin>>b;
    }while(b=='y'||b=='Y');
    
}

void problem5(){
        cout<<"In problem # 5"<<endl<<endl;
            //declare variables
    short shrt=1;
    int intgr=1;
    unsigned int unInt=1;
    long lng=1, templ;
    float flt=1, tempf;
    double dbl=1;
    long double ldbl=1;
    int num=500;
    char c;
    
    
    //Display purpose
    cout<<"Problem 5: Factorial";
    cout<<"This program will calculate the highest factorial that a given\n"
        <<"primitive prototype can hold in a byte\n\n";
    
    
    //Short  
    for(int i=1;i<=num;i++){
        shrt=shrt*i;
        if(shrt<=0){
            shrt=i-1;
            break;
        } 
    }
    //Integer   
    for(int i=1;i<=num;i++){
        intgr=intgr*i;
        if(intgr<=0){
            intgr=i-1;
            break;
        } 
    }
    //Unsigned Integer   
    for(int i=1;i<=num;i++){
        
        unInt=unInt*i;
        if(unInt<=0){
            unInt=i-1;
            break;
        } 
    }
    //Long   
    for(int i=1;i<=num;i++){
        lng=lng*i;
        templ=lng;
        if((lng*i++)<templ){
            lng=i;
            break;
        } 
    }
    //Float  
    for(int i=1;i<=num;i++){
        flt=flt*i;
        tempf=flt;
        if((flt*i++)<tempf){
            flt=i;
            break;
        } 
    }
    //Double  
    for(int i=1;i<=num;i++){
        dbl=dbl*i;
        if(dbl<=0){
            dbl=i-1;
            break;
        } 
    }
    //Long Double  
    for(int i=1;i<=num;i++){
        ldbl=ldbl*i;
        if(ldbl<=0){
            ldbl=i-1;
            break;
        } 
    }
    cout<<"Highest factorial that can be held in a Short: "<<shrt<<endl;
    cout<<"Highest factorial that can be held in an Integer: "<<intgr<<endl;
    cout<<"Highest factorial that can be held in an Unsigned Integer: "<<unInt<<endl;
    cout<<"Highest factorial that can be held in a Long: "<<lng<<endl;
    cout<<"Highest factorial that can be held in a Float: "<<flt<<endl;
    cout<<"Highest factorial that can be held in a Double: "<<dbl<<endl;
    cout<<"Highest factorial that can be held in a Long Double: "<<ldbl<<endl;
    cout<<endl<<endl;
}

void problem6(){
        cout<<"In problem # 6"<<endl<<endl;
    //Mid-Term Problem 6
    cout << "2.125 to Binary: 10.001\n";
    cout << "2.125 to Octal: 2.1\n";
    cout << "2.125 to Hexadecimal: 2.2\n";
    cout << "0.06640625 to Binary: 0.00010001\n";
    cout << "0.06640625 to Octal: 0.042\n";
    cout << "0.06640625 to Hexadecimal: 0.11\n";
    cout << "-2.125 to float representation: C0080000\n";
    cout << "0.06640625 to float representation: 3D880000\n";
    cout << "46666601 float to decimal: 1.47455009765625e4\n";
    cout << "46666602 float to decimal: 1.4745501953125e4\n";
    cout << "B9999AFE float to decimal: -2.92979122605174779891967773438e-4\n\n\n";
}

void def(int inN){
        cout<<"You typed "<<inN<<" to exit the program"<<endl;
}

////////////////////////////////////////////////////////////////////////////////
//
//                              Problem 1
//  void calcBal(BankAcc *s) 
//                  receives structure contents of BankAcc and calculates
//                  balance after deposits,withdrawals and charges applied.  
////////////////////////////////////////////////////////////////////////////////

void calcBal(BankAcc *s){
    //calculate balance with charges, debts, and credits.
    s->inBal = (s->inBal+s->totCrdt)-s->totDbt;
    if(s->inBal<0){
        s->inBal-=12;
        cout<<"Account was overdrawn!\n"
            <<"A $12 Charge has been applied.\n"
            <<"Your new account balance is: $"<<s->inBal<<endl;
    }
    else{
        cout<<"Balance after charges: $"<<s->inBal<<endl;
    }

}
////////////////////////////////////////////////////////////////////////////////
//
//                              Problem 2
//  void dispS(Employee* s) 
//                  displays structure contents 
//  void calc(Employee* g)
//                  receives structure and calculates gross pay
//
////////////////////////////////////////////////////////////////////////////////

void dispS(Employee* s) {
    //Display Data
    float grossP = calc(s);
    cout << "Name: " << s->name << endl;
    cout << "Hours worked: " << s->wrkHrs << endl;
    cout << "Pay Rate: $" << s->payRte << endl;
    cout << "Gross Pay: $" << grossP << endl;
}

float calc(Employee* g) {
    //calculate gross pay
    float grossPay = 0;
    if (g->wrkHrs <= 20)
        grossPay = g->wrkHrs * g->payRte;
    if (g->wrkHrs > 20 && g->wrkHrs <= 40)
        grossPay = (20 * g->payRte)+((g->wrkHrs - 20)*(2 * g->payRte));
    if (g->wrkHrs > 40)
        grossPay = (20 * g->payRte)+(20 * (2 * g->payRte))+(g->wrkHrs - 40)*(3 * g->payRte);

    return grossPay;
}

////////////////////////////////////////////////////////////////////////////////
//
//                              Problem 4
//    
////////////////////////////////////////////////////////////////////////////////
void encrypt(int &num){
    int* swpd;
    cout<<num;
    int arr[4];
    //break off the numbers to individual integers
    for (int i=3;i>=0;i--){
        arr[i]=num%10;
        num /= 10;
        cout<<"\nnumber broken off is: "<<arr[i];
    }
    cout<<endl;
    for (int i=0;i<4;i++){
        cout<<arr[i];
    }
    //send out to get swapped and modded
    swpd=swap(arr,4);
    //display encrypted product
    dispArr(swpd,4);
}
int * swap(int* a,int s){
    int temp;       //temp value to hold values being swapped
    //add 3 mod 8 to each digit
    cout<<"\nINSIDE SWAP\n";
        for (int i=0;i<s;i++){
        a[i]=(a[i]+3)%8;
        cout<<"New Val: "<<a[i]<<endl;
    }
    //swap digits 1 and 2
    temp=a[0];
    a[0]=a[1];
    a[1]=temp;
    //swap digits 3 and 4
    temp=a[2];
    a[2]=a[3];
    a[3]=temp;
    
    return a;
}
void dispArr(int* a, int s){
    cout<<"\nProduct: \n";
    for (int i=0;i<s;i++){
        cout<<a[i];
    }
}
void decrypt(int &val){
    int* unswp;
    cout<<val;
    int arr[4];
    //break off the numbers to individual integers
    for (int i=3;i>=0;i--){
        arr[i]=val%10;
        val /= 10;
        cout<<"\nnumber broken off is: "<<arr[i];
    }
    cout<<endl;
    for (int i=0;i<4;i++){
        cout<<arr[i];
    }
    //send out to get swapped and modded
    unswp=unswap(arr,4);
    //display encrypted product
    dispArr(unswp,4);
}
int * unswap(int* b,int t){
    int temp;       //temp value to hold values being swapped
    //add 3 mod 8 to each digit
    cout<<"\nINSIDE SWAP\n";
    
    //swap digits 1 and 2
    temp=b[0];
    b[0]=b[1];
    b[1]=temp;
    //swap digits 3 and 4
    temp=b[2];
    b[2]=b[3];
    b[3]=temp;
    
    for (int i=0;i<t;i++){
        b[i]=(b[i]-3+8)%8;
        cout<<"New Val: "<<b[i]<<endl;
    }

    return b;
}
bool isValid(int value){
    int arrChk[4];
        for (int i=3;i>=0;i--){
        arrChk[i]=value%10;
        value /= 10;
        if(arrChk[i]>7||arrChk[i]<0)
            return false;
    }
    return true;
}