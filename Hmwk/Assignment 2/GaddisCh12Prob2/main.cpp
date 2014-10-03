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
            cout<<"This Program will read a file and display the file on\n"
                <<"the screen, if the file is too large, it will display\n"
                <<"24 lines at a time while the user presses a key to \n"
                <<"continue displaying the text.\n"
                <<"Please type \"long.txt\" to continue...\n";
            cin>>readThis;
        }while(readThis!="long.txt");
        // Open the file in input mode.
        nameFile.open(readThis, ios::in);

        // If the file was successfully opened, continue.
        if (nameFile){
            // Read an item from the file.
            getline(nameFile, input);

            // While the last read operation
            // was successful, continue.
        do{
            for(int i=0;i<24;i++){
                // Display the last item read.
                cout << input << endl;
                // Read the next item.
                getline(nameFile, input);
            }
            cin.get();
            if(!nameFile.eof()){
            cout<<"The file has more than 24 lines!\n"
                <<"Press 'Enter' to continue reading form file.\n";
        }
        }while(cin.get()&&!nameFile.eof());

        if(nameFile.eof()){
            cout<<"This is the complete file\n";
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