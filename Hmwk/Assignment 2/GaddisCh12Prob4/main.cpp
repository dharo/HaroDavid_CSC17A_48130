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

int main() {

    string input; // To hold file input
    fstream nameFile; // File stream object
    string readThis; // To hold user input for file name
    char choice; // Hold user input for repeating program
    do {
        int lines = 0;
        int templines=0;

        do {
            
            cout << "This program will read the last 10 lines from one of two files\n"
                    << "\"tiny.txt\" and \"large.txt\". Please type in one to test.\n\n";
            cin >> readThis;
            cin.ignore();
        } while (readThis != "tiny.txt" && readThis != "large.txt");
        // Open the file in input mode.
        nameFile.open(readThis, ios::in);

        // If the file was successfully opened, continue.
        if (nameFile) {
            do {
                getline(nameFile, input);
                templines++;

            } while (!nameFile.eof());
            lines=templines;
            nameFile.clear();
            nameFile.seekg(0L, ios::beg);
            for (int i = 0; i <= templines; i++) {
                getline(nameFile, input);
                if (i >= templines-11)
                    cout << input << endl;
            }


            if (nameFile.eof()) {
                cout << "The file is less than 10 lines long!\n";
            } else {
                cout << "This file has more than 10 lines.\n";
            }

            // Close the file.
            nameFile.close();
            
        } else {
            cout << "ERROR: Cannot open file.\n";
        }
        
        //repeat program?
        do { //input validation
            cout << "Would you like to try again? (y|n)";
            cin >> choice;
            cin.ignore();
        } while (choice != 'y' && choice != 'Y' && choice != 'n' && choice != 'N');
    } while (choice == 'y' || choice == 'Y');
    cin.ignore();
    return 0;
} 