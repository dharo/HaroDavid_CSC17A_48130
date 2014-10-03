/* 
 * File:   main.cpp
 * Author: davidharo
 *
 * Created on October 3, 2014, 1:05 PM
 */
 // This program uses the getline function to read a line of
 // data from the file.
 #include <iostream>
 #include <fstream>
 #include <string>
 using namespace std;

int main(){

    string input;       // To hold file input
    fstream nameFile;   // File stream object
    string readThis;    // To hold user input for file name
    char choice;        // Hold user input for repeating program
    do{
    
        do{
            cout<<"This program will read 10 lines from one of two files\n"
                <<"\"short.txt\" and \"long.txt\". Please type in one to test.\n\n";
            cin>>readThis;
        }while(readThis!="short.txt"&&readThis!="long.txt");
        // Open the file in input mode.
        nameFile.open(readThis, ios::in);

        // If the file was successfully opened, continue.
        if (nameFile){
               // Read an item from the file.
               getline(nameFile, input);

               // While the last read operation
               // was successful, continue.

        for(int i=0;i<10;i++){

               // Display the last item read.
               cout << input << endl;
               // Read the next item.
               getline(nameFile, input);
        }
        if(nameFile.eof()){
            cout<<"The file is less than 10 lines long!\n";
        }
        else{
            cout<<"This file has more than 10 lines.\n";
        }

            // Close the file.
            nameFile.close();
        }
        else{
            cout << "ERROR: Cannot open file.\n";
        }
        //repeat program?
        do{                                                   //input validation
            cout<<"Would you like to try again? (y|n)";
            cin>>choice;
        }while(choice!='y'&&choice!='Y'&&choice!='n'&&choice!='N');
    }while(choice=='y'||choice=='Y');
    cin.ignore();
return 0;
}       