/* 
 * File:   main.cpp
 * Author: David Haro
 * Purpose: Menu
 * 
 * 
 * Created on October 1, 2014
 */

//libraries
 #include <iostream>
 #include <fstream>
 #include <string>
using namespace std;

//function prototypes
void Menu();
int getN();
void def(int);
void problem1();
void problem2();
void problem3();
void problem4();
void problem5();
//function prototypes for problems
//problem3
void showFile(fstream&);
void readLine(fstream&);

//execution
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

          default:   def(inN);}
        }while(inN>=1&&inN<=5);
        return 1;
}
    void Menu(){
    		cout<<"Gaddis Ch.12 Problems 1-5"<<endl;
           cout<<"Type 1 for problem 1"<<endl;
           cout<<"Type 2 for problem 2"<<endl;
           cout<<"Type 3 for problem 3"<<endl;
           cout<<"Type 4 for problem 4"<<endl;
           cout<<"Type 5 for problem 5"<<endl;  
           cout<<"Type anything else to exit \n"<<endl;
    }
    int getN(){
           int inN;
		   cin>>inN;
           return inN;
    }
    void problem1(){
        cout<<"In problem # 1"<<endl<<endl;
        string input;       // To hold file input
        fstream nameFile;   // File stream object
        string readThis;    // To hold user input for file name
        char choice;        // Hold user input for repeating program
                do{

                do{
                        cout<<"This program will read the first 10 lines from one of two files\n"
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

    }
    void problem2(){
            cout<<"In problem # 2"<<endl<<endl;

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
                        <<"Please type \"longfile.txt\" to continue...\n";
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

    }
    void problem3(){
           cout<<"In problem # 3"<<endl<<endl;       
            //Declare Variables
            string input;       // To hold file input
            fstream joke, punch;   // File stream object
            char choice;        // Hold user input for repeating program
            do{
                //Open Files
                joke.open("joke.txt", ios::in);
                punch.open("punchline.txt", ios::in);

                cout<<"Gaddis Chapter 12 Problem 3"
                    <<"This Program will open a file containing a joke and \n"
                    <<"send it to a function to be displayed. Then another file\n"
                    <<"contating the punchline to the joke will be sne to a different\n"
                    <<"function to look for the last line in the file to display.\n\n\n";

                //Send files to functions
                showFile(joke);
                readLine(punch);
                //close files
                joke.close();
                punch.close();
            //repeat program?
            do{                                                   //input validation
                    cout<<"\n\nWould you like to try again? (y|n)";
                    cin>>choice;
                }while(choice!='y'&&choice!='Y'&&choice!='n'&&choice!='N');
            }while(choice=='y'||choice=='Y');
    }
    void problem4(){
            cout<<"In problem # 4"<<endl<<endl;
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

    }
    void problem5(){
            cout<<"In problem # 5"<<endl<<endl;
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


    }

    void def(int inN){
           cout<<"You typed "<<inN<<" to exit the program"<<endl;
    }

//------------------PROBLEM3----------------------------------------------------
void showFile(fstream &file){
    string line;
    
    do{
        getline(file, line);
        cout<<line<<endl;
    }while(!file.eof());
}
void readLine(fstream &file){
    string line;
    int numLines;
    while(file){
        getline(file,line);
        numLines++;
        //cout<<numLines<<endl;
    }
    
    cout<<"\n\n----Now Reading Punchline!----\n\n";
    for(int i=0;i<=numLines;i++){
        getline(file,line);
        if(i==numLines-1){
            cout<<line<<endl;
        }
    }
}

