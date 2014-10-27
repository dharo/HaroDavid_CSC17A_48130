/* 
 * File:   main.cpp
 * Author: David Haro
 * Mid-Term CSC 17A: C++ Programming Objects
 * Problem 4
 * Due October 24, 2014
 */
//Libraries
#include <cstdlib>
#include <iostream>
using namespace std;

//Prototypes Problem 4
void encrypt(int&);
void decrypt(int&);
int * swap(int *,int);
void dispArr(int*, int);
int * unswap(int *,int);
bool isValid(int);
int main(int argc, char** argv) {
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
    return 0;
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