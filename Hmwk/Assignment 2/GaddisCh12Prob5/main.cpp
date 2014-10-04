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
            cout<<"This Program is the same as Gaddis Ch12 Prob 2\n"
                <<"Except this program will number the lines on the left.\n"
                <<"Pleast type 'longfile.txt' to continue\n";
            cin>>readThis;
        }while(readThis!="longfile.txt");
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
                cout<<i+1<<": ";
                cout << input << endl;
                // Read the next item.
                getline(nameFile, input);
            }
            cin.get();                   //pause and wait for user input
            if(!nameFile.eof()){
            cout<<"The file has more than 24 lines!\n"
                <<"Press 'Enter' to continue reading from file.\n";
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
        do{                                //input validation
            cout<<"Would you like to try again? (y|n)";
            cin>>choice;
        }while(choice!='y'&&choice!='Y'&&choice!='n'&&choice!='N');
    }while(choice=='y'||choice=='Y');
    cin.ignore();
return 0;
}        