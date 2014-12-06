
/* 
 * File:   main.cpp
 * Author: David Haro
 * Battle Ship / Salvo Game
 * Last Update for BattleShip_V2: Dec 8th, 2013 12:10am
 * Current Version: BattleShip V2_5: Oct 26th, 2014 9:05pm
 * 
 * Updates Since version (BattleShip_V2):
 * - Added Comments to function declarations
 * - Expanded battlefield board from 6x6 to 10x10 2D array
 * - Added player 2D Grids to be carried throughout the program
 * - Fixed issue where last row will error when checking for cross
 * - Added Legend to be displayed with player grid
 * - Structure added to hold Legend diagram
 * - Delete allocated memory before ending game
 * - Fixed issue where CPU would only deploy to a 6x6 playing field
 * - Squished other bugs!
 * 
 * -----> ADDED ABILITY TO READ RULES FROM BINARY FILE
 * -----> 
 * 
 * 
 */
//Libraries
#include <iostream>
#include <cstdlib>
#include <iomanip>
#include <ctime>
#include <cstring>
#include <fstream>

#include "Hit.h"
using namespace std;
//Structures
struct Legend{
    string lgnd;
    int hitMrk;
    int ship;
};
//Global Constants:
const int ROW = 11, COL = 11;
int HITGRID[ROW][COL] = {
    {0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
    {0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
    {0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
    {0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
    {0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
    {0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
    {0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
    {0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
    {0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
    {0, 0, 0, 0, 0, 0, 0, 0, 0, 0}}; //Grid for Hits
//Function Prototypes
void strtMu(); //Start menu
void bsBoard(int **); //Print playing board
void dploySh(int **, int **); //User chooses ship configuration
void cpuGrid(int **); //Print CPU grid
void cpuDply(int **, int **); //Auto-generate ships for CPU
int rules(); //Displays Rules for game
int hitMu(int **, int **); //Displays menu for player to strike
//Receives info from dploySh to verify ship size is correct
bool ckGrid(int **, int, int, int, int, int);
//Checks if ship deployment is valid
bool noCros(int **, int, int, int, int);
//Fills ship between coordinates
void filShp(int **, int, int, int, int, int);
//Checks if ship has been hit
bool hitZne(int **, int, int, int, int);
//Displays a Grid where the User has hit the computer's ships
void hitGrd();
//Destroy allocated memory
void destroy(int **,int);


//Execute

int main(int argc, char** argv) {
    cout<<"\n\n\n\t\t\tFor Best results, make window full screen.\n\n";




    strtMu();
    return 0;
}
//////////////Start Menu: Game Intro and Menu Options///////////////////////////

void strtMu() {
    //Declare Variables
    //Create player 2D array (Dynamically allocate memory)
    int** SQUARE = new int*[ROW];
    for (int i = 0; i < ROW; i++) {
        SQUARE[i] = new int[COL];
    }
    for(int row=0;row<ROW;row++){
        for(int col=0;col<COL;col++){
             SQUARE[row][col]=0;
        }
    }
    //Declare Variables
    //Create CPU Player 2D array (Dynamically allocate memory)
    int** CPUGRD = new int*[ROW];
    for (int i = 0; i < ROW; ++i) {
        CPUGRD[i] = new int[COL];
    }
    for(int row=0;row<ROW;row++){
        for(int col=0;col<COL;col++){
             CPUGRD[row][col]=0;
        }
    }

    //Grid for user
    int choice, again;
    //Display Name in a Cool fashion
    do {
        cout << "\t\t\t   ___       __  __  __    ______   _ \n"
                "\t\t\t  / _ )___ _/ /_/ /_/ /__ / __/ /  (_)__ \n"
                "\t\t\t / _  / _ `/ __/ __/ / -_)\\ \\/ _ \\/ / _ \\ \n"
                "\t\t\t/____/\\_,_/\\__/\\__/_/\\__/___/_//_/_/ .__/ \n"
                "\t\t\t                                  /_/    "<<endl;
        cout<<"\t\t\tProgrammed by David Haro"<< endl << endl;

        cout << "\t\t\t1* Play Game\n\n"
                << "\t\t\t2* See Rules\n\n"
                << "\t\t\t3* Quit\n" << endl;
        cout << "\t\t\tMake a Selection and Press \'Enter\'" << endl;
        cin>>choice;
        cout << "\n\n";
        switch (choice) {
            case 1: dploySh(SQUARE, CPUGRD); //cpuDply();
                break;
            case 2: again = rules();
                break;
            default: exit(0);
        }
    } while (choice > 3 || choice < 1 || again == 1);
}
//////////////2D Array that Prints out Board for User///////////////////////////

void bsBoard(int **SQUARE) {
    //Declare and Initialize Board 
    Legend diagram;
    diagram.hitMrk=3;
    diagram.lgnd="Legend";
    diagram.ship=1;
    cout<<endl<<endl;
    cout << diagram.lgnd<<" \t\t\t      B    A    T    T    L    E    S    H    I    P\n";
    cout << "-------\t\t\t      1    2    3    4    5    6    7    8    9   10 \n";
    cout << "Hit Marker: "<<diagram.hitMrk<<"\t\t    --------------------------------------------------\n";
    cout << "Ship Part: "<<diagram.ship<<"\t\t1   |  " << SQUARE[0][0] << " |  " << SQUARE[0][1] << " |  " << SQUARE[0][2] << " |  " << SQUARE[0][3] << " |  " << SQUARE[0][4] << " |  " << SQUARE[0][5] << " | "
            << SQUARE[0][6] << " |  " << SQUARE[0][7] << " |  " << SQUARE[0][8] << " |  " << SQUARE[0][9] << " |  " << endl;
    cout << "\t\t\t    --------------------------------------------------\n";
    cout << "\t\t\t2   |  " << SQUARE[1][0] << " |  " << SQUARE[1][1] << " |  " << SQUARE[1][2] << " |  " << SQUARE[1][3] << " |  " << SQUARE[1][4] << " |  " << SQUARE[1][5] << " | "
            << SQUARE[1][6] << " |  " << SQUARE[1][7] << " |  " << SQUARE[1][8] << " |  " << SQUARE[1][9] << " |  " << endl;
    cout << "\t\t\t    --------------------------------------------------\n";
    cout << "\t\t\t3   |  " << SQUARE[2][0] << " |  " << SQUARE[2][1] << " |  " << SQUARE[2][2] << " |  " << SQUARE[2][3] << " |  " << SQUARE[2][4] << " |  " << SQUARE[2][5] << " | "
            << SQUARE[2][6] << " |  " << SQUARE[2][7] << " |  " << SQUARE[2][8] << " |  " << SQUARE[2][9] << " |  " << endl;
    cout << "\t\t\t    --------------------------------------------------\n";
    cout << "\t\t\t4   |  " << SQUARE[3][0] << " |  " << SQUARE[3][1] << " |  " << SQUARE[3][2] << " |  " << SQUARE[3][3] << " |  " << SQUARE[3][4] << " |  " << SQUARE[3][5] << " | "
            << SQUARE[3][6] << " |  " << SQUARE[3][7] << " |  " << SQUARE[3][8] << " |  " << SQUARE[3][9] << " |  " << endl;
    cout << "\t\t\t    --------------------------------------------------\n";
    cout << "\t\t\t5   |  " << SQUARE[4][0] << " |  " << SQUARE[4][1] << " |  " << SQUARE[4][2] << " |  " << SQUARE[4][3] << " |  " << SQUARE[4][4] << " |  " << SQUARE[4][5] << " | "
            << SQUARE[4][6] << " |  " << SQUARE[4][7] << " |  " << SQUARE[4][8] << " |  " << SQUARE[4][9] << " |  " << endl;
    cout << "\t\t\t    --------------------------------------------------\n";
    cout << "\t\t\t6   |  " << SQUARE[5][0] << " |  " << SQUARE[5][1] << " |  " << SQUARE[5][2] << " |  " << SQUARE[5][3] << " |  " << SQUARE[5][4] << " |  " << SQUARE[5][5] << " | "
            << SQUARE[5][6] << " |  " << SQUARE[5][7] << " |  " << SQUARE[5][8] << " |  " << SQUARE[5][9] << " |  " << endl;
    cout << "\t\t\t    --------------------------------------------------\n";
    cout << "\t\t\t7   |  " << SQUARE[6][0] << " |  " << SQUARE[6][1] << " |  " << SQUARE[6][2] << " |  " << SQUARE[6][3] << " |  " << SQUARE[6][4] << " |  " << SQUARE[6][5] << " | "
            << SQUARE[6][6] << " |  " << SQUARE[6][7] << " |  " << SQUARE[6][8] << " |  " << SQUARE[6][9] << " |  " << endl;
    cout << "\t\t\t    --------------------------------------------------\n";
    cout << "\t\t\t8   |  " << SQUARE[7][0] << " |  " << SQUARE[7][1] << " |  " << SQUARE[7][2] << " |  " << SQUARE[7][3] << " |  " << SQUARE[7][4] << " |  " << SQUARE[7][5] << " | "
            << SQUARE[7][6] << " |  " << SQUARE[7][7] << " |  " << SQUARE[7][8] << " |  " << SQUARE[7][9] << " |  " << endl;
    cout << "\t\t\t    --------------------------------------------------\n";
    cout << "\t\t\t9   |  " << SQUARE[8][0] << " |  " << SQUARE[8][1] << " |  " << SQUARE[8][2] << " |  " << SQUARE[8][3] << " |  " << SQUARE[8][4] << " |  " << SQUARE[8][5] << " | "
            << SQUARE[8][6] << " |  " << SQUARE[8][7] << " |  " << SQUARE[8][8] << " |  " << SQUARE[8][9] << " |  " << endl;
    cout << "\t\t\t    --------------------------------------------------\n";
    cout << "\t\t\t10  |  " << SQUARE[9][0] << " |  " << SQUARE[9][1] << " |  " << SQUARE[9][2] << " |  " << SQUARE[9][3] << " |  " << SQUARE[9][4] << " |  " << SQUARE[9][5] << " | "
            << SQUARE[9][6] << " |  " << SQUARE[9][7] << " |  " << SQUARE[9][8] << " |  " << SQUARE[9][9] << " |  " << endl;
    cout << "\t\t\t    --------------------------------------------------\n";
}
//////////////Function that Deploys ships///////////////////////////////////////

void cpuGrid(int **CPUGRD) {
     //Declare and Initialize Board 
    Legend diagram;
    diagram.hitMrk=3;
    diagram.lgnd="Legend";
    diagram.ship=1; 

    cout<<endl<<endl;
    cout << diagram.lgnd<<" \t\t\t      B    A    T    T    L    E    S    H    I    P\n";
    cout << "-------\t\t\t      1    2    3    4    5    6    7    8    9   10 \n";
    cout << "Hit Marker: "<<diagram.hitMrk<<"\t\t    --------------------------------------------------\n";
    cout << "Ship Part: "<<diagram.ship<<"\t\t1   |  " << CPUGRD[0][0] << " |  " << CPUGRD[0][1] << " |  " << CPUGRD[0][2] << " |  " << CPUGRD[0][3] << " |  " << CPUGRD[0][4] << " |  " << CPUGRD[0][5] << " | "
            << CPUGRD[0][6] << " |  " << CPUGRD[0][7] << " |  " << CPUGRD[0][8] << " |  " << CPUGRD[0][9] << " |  " << endl;
    cout << "\t\t\t    --------------------------------------------------\n";
    cout << "\t\t\t2   |  " << CPUGRD[1][0] << " |  " << CPUGRD[1][1] << " |  " << CPUGRD[1][2] << " |  " << CPUGRD[1][3] << " |  " << CPUGRD[1][4] << " |  " << CPUGRD[1][5] << " | "
            << CPUGRD[1][6] << " |  " << CPUGRD[1][7] << " |  " << CPUGRD[1][8] << " |  " << CPUGRD[1][9] << " |  " << endl;
    cout << "\t\t\t    --------------------------------------------------\n";
    cout << "\t\t\t3   |  " << CPUGRD[2][0] << " |  " << CPUGRD[2][1] << " |  " << CPUGRD[2][2] << " |  " << CPUGRD[2][3] << " |  " << CPUGRD[2][4] << " |  " << CPUGRD[2][5] << " | "
            << CPUGRD[2][6] << " |  " << CPUGRD[2][7] << " |  " << CPUGRD[2][8] << " |  " << CPUGRD[2][9] << " |  " << endl;
    cout << "\t\t\t    --------------------------------------------------\n";
    cout << "\t\t\t4   |  " << CPUGRD[3][0] << " |  " << CPUGRD[3][1] << " |  " << CPUGRD[3][2] << " |  " << CPUGRD[3][3] << " |  " << CPUGRD[3][4] << " |  " << CPUGRD[3][5] << " | "
            << CPUGRD[3][6] << " |  " << CPUGRD[3][7] << " |  " << CPUGRD[3][8] << " |  " << CPUGRD[3][9] << " |  " << endl;
    cout << "\t\t\t    --------------------------------------------------\n";
    cout << "\t\t\t5   |  " << CPUGRD[4][0] << " |  " << CPUGRD[4][1] << " |  " << CPUGRD[4][2] << " |  " << CPUGRD[4][3] << " |  " << CPUGRD[4][4] << " |  " << CPUGRD[4][5] << " | "
            << CPUGRD[4][6] << " |  " << CPUGRD[4][7] << " |  " << CPUGRD[4][8] << " |  " << CPUGRD[4][9] << " |  " << endl;
    cout << "\t\t\t    --------------------------------------------------\n";
    cout << "\t\t\t6   |  " << CPUGRD[5][0] << " |  " << CPUGRD[5][1] << " |  " << CPUGRD[5][2] << " |  " << CPUGRD[5][3] << " |  " << CPUGRD[5][4] << " |  " << CPUGRD[5][5] << " | "
            << CPUGRD[5][6] << " |  " << CPUGRD[5][7] << " |  " << CPUGRD[5][8] << " |  " << CPUGRD[5][9] << " |  " << endl;
    cout << "\t\t\t    --------------------------------------------------\n";
    cout << "\t\t\t7   |  " << CPUGRD[6][0] << " |  " << CPUGRD[6][1] << " |  " << CPUGRD[6][2] << " |  " << CPUGRD[6][3] << " |  " << CPUGRD[6][4] << " |  " << CPUGRD[6][5] << " | "
            << CPUGRD[6][6] << " |  " << CPUGRD[6][7] << " |  " << CPUGRD[6][8] << " |  " << CPUGRD[6][9] << " |  " << endl;
    cout << "\t\t\t    --------------------------------------------------\n";
    cout << "\t\t\t8   |  " << CPUGRD[7][0] << " |  " << CPUGRD[7][1] << " |  " << CPUGRD[7][2] << " |  " << CPUGRD[7][3] << " |  " << CPUGRD[7][4] << " |  " << CPUGRD[7][5] << " | "
            << CPUGRD[7][6] << " |  " << CPUGRD[7][7] << " |  " << CPUGRD[7][8] << " |  " << CPUGRD[7][9] << " |  " << endl;
    cout << "\t\t\t    --------------------------------------------------\n";
    cout << "\t\t\t9   |  " << CPUGRD[8][0] << " |  " << CPUGRD[8][1] << " |  " << CPUGRD[8][2] << " |  " << CPUGRD[8][3] << " |  " << CPUGRD[8][4] << " |  " << CPUGRD[8][5] << " | "
            << CPUGRD[8][6] << " |  " << CPUGRD[8][7] << " |  " << CPUGRD[8][8] << " |  " << CPUGRD[8][9] << " |  " << endl;
    cout << "\t\t\t    --------------------------------------------------\n";
    cout << "\t\t\t10  |  " << CPUGRD[9][0] << " |  " << CPUGRD[9][1] << " |  " << CPUGRD[9][2] << " |  " << CPUGRD[9][3] << " |  " << CPUGRD[9][4] << " |  " << CPUGRD[9][5] << " | "
            << CPUGRD[9][6] << " |  " << CPUGRD[9][7] << " |  " << CPUGRD[9][8] << " |  " << CPUGRD[9][9] << " |  " << endl;
    cout << "\t\t\t    --------------------------------------------------\n";
}
//////////////Function that Deploys ships///////////////////////////////////////

void dploySh(int **SQUARE, int **CPUGRD) {
    //declare variables
    int ship, valid, cross, deny, i, j, k, l; //i,j,k,l are grid holders for carrier ship
    int a, b, c, d; //abcd grid holders for tugboat
    int m, n, o, p, r, s, t, u; //mnop grid holders for gunship
    //rstu grid holders for submarine

    //This Function is used to allow user to select ship deployment
    cout << "\nDeploy your ships!\n\n";
    for (int menu = 0; menu < 5; menu++) {
        //ship=menu;
        switch (menu) {
            case 1:
            {
                do { //Ship 1
                    ship = 5; //ship size
                    cout << "Deploy Carrier. Size is: " << ship << endl;
                    do {
                        //Input front of ship
                        bsBoard(SQUARE);
                        cout << "Deploy Carrier. Size is: " << ship << endl;
                        cout << "Type the coordinate for the front of the ship. ex. For(1,4) type 1 4 [Enter]\n";
                        cin >> i>>j;
                        
                        if (i <= ROW && i >= 1 && j <= COL && j >= 1) {
                            if (SQUARE[i - 1][j - 1] != 1) {
                                deny = 0;
                                SQUARE[i - 1][j - 1] = 1;
                            } else
                                deny = 1;
                        } else if (i > ROW || j > COL || i < 1 || j < 1) {
                            SQUARE[i - 1][j - 1] = 0;
                        }
                    } while (i < 1 || i > ROW || j < 1 || j > COL || deny == 1);
                    do {

                        //Input rear of ship
                        cout << "Deploy Carrier. Size is: " << ship << endl;
                        cout << "Type the coordinate for the rear of the ship. ex. For(1,4) type 1 4 [Enter]\n";
                        cin >> k>>l;
                        
                        if (k <= ROW && k >= 1 && l <= COL && l >= 1) {
                            if (SQUARE[k - 1][l - 1] != 1) {
                                deny = 0;
                                SQUARE[k - 1][l - 1] = 1;
                            } 
                            else deny = 1;
                        } else if (k > ROW || l > COL || k < 1 || l < 1) {
                            SQUARE[k - 1][l - 1] = 0;
                        }
                    } while (k < 1 || k > ROW || l < 1 || l > COL || deny == 1);
                    valid = ckGrid(SQUARE, i, j, k, l, ship);
                    cross = noCros(SQUARE, i, j, k, l);
                    if (valid == 0 || cross == 1) {
                        SQUARE[i - 1][j - 1] = 0;
                        SQUARE[k - 1][l - 1] = 0;
                        cout << "Check your ship size! Remember no Diagonals or Criss Cross!\n";
                    } else {
                        //This will fill gap for spaces between ship.                      
                        filShp(SQUARE, i, j, k, l, ship);
                        cout << endl;
                    }
                } while (valid == 0 || cross == 1); //valid is returned from ckGrid, if invalid 0 is returned
            }
                break;
            case 2:
            {
                do { //Ship 2
                    ship = 4;
                    cout << "Deploy GunShip. Size is: " << ship << endl;
                    do {
                        //Input front of ship
                        bsBoard(SQUARE);
                        cout << "Deploy GunShip. Size is: " << ship << endl;
                        cout << "Type the coordinate for the front of the ship. ex. For(1,4) type 1 4 [Enter]\n";
                        cin >> m>>n;
                        if (m <= ROW && m >= 1 && n <= COL && n >= 1) {
                            if (SQUARE[m - 1][n - 1] != 1) {
                                deny = 0;
                                SQUARE[m - 1][n - 1] = 1;
                            } else
                                deny = 1;
                        } else if (m > ROW || n > COL || m < 1 || n < 1) {
                            SQUARE[m - 1][n - 1] = 0;
                        }
                    } while (m < 1 || m > ROW || n < 1 || n > COL || deny == 1);
                    do {

                        //Input rear of ship
                        cout << "Deploy GunShip. Size is: " << ship << endl;
                        cout << "Type the coordinate for the rear of the ship. ex. For(1,4) type 1 4 [Enter]\n";
                        cin >> o>>p;
                        if (o <= ROW && o >= 1 && p <= COL && p >= 1) {
                            if (SQUARE[o - 1][p - 1] != 1) {
                                deny = 0;
                                SQUARE[o - 1][p - 1] = 1;
                            } else
                                deny = 1;
                        } else if (o > ROW || p > COL || o < 1 || p < 1) {
                            SQUARE[o - 1][p - 1] = 0;
                        }
                    } while (o < 1 || o > ROW || p < 1 || p > COL || deny == 1);
                    valid = ckGrid(SQUARE, m, n, o, p, ship);
                    cross = noCros(SQUARE, m, n, o, p);
                    if (valid == 0 || cross == 1) {
                        SQUARE[m - 1][n - 1] = 0;
                        SQUARE[o - 1][p - 1] = 0;
                        cout << "Check your ship size! Remember no Diagonals or CrissCross!\n";
                    } else {
                        //This will fill gap for spaces between ship.
                        filShp(SQUARE, m, n, o, p, ship);
                        cout << endl;
                    }
                } while (valid == 0 || cross == 1); //valid is returned from ckGrid, if invalid 0 is returned
            }
                break;
            case 3:
            {
                do {
                    ship = 3;
                    cout << "Deploy Submarine. Size is: " << ship << endl;
                    do {
                        //Input front of ship
                        bsBoard(SQUARE);
                        cout << "Deploy Submarine. Size is: " << ship << endl;
                        cout << "Type the coordinate for the front of the sub. ex. For(1,4) type 1 4 [Enter]\n";
                        cin >> r>>s;
                        if (r <= ROW && r >= 1 && s <= COL && s >= 1) {
                            if (SQUARE[r - 1][s - 1] != 1) {
                                deny = 0;
                                SQUARE[r - 1][s - 1] = 1;
                            } else
                                deny = 1;
                        } else if (r > ROW || s > COL || r < 1 || s < 1) {
                            SQUARE[r - 1][s - 1] = 0;
                        }
                    } while (r < 1 || r > ROW || s < 1 || s > COL || deny == 1);
                    do {

                        //Input rear of ship
                        cout << "Deploy Submarine. Size is: " << ship << endl;
                        cout << "Type the coordinate for the rear of the sub. ex. For(1,4) type 1 4 [Enter]\n";
                        cin >> t>>u;
                        if (t <= ROW && t >= 1 && u <= COL && u >= 1) {
                            if (SQUARE[t - 1][u - 1] != 1) {
                                deny = 0;
                                SQUARE[t - 1][u - 1] = 1;
                            } else
                                deny = 1;
                        } else if (t > ROW || u > COL || t < 1 || u < 1) {
                            SQUARE[t - 1][u - 1] = 0;
                        }
                    } while (t < 1 || t > ROW || u < 1 || u > COL || deny == 1);
                    valid = ckGrid(SQUARE, r, s, t, u, ship);
                    cross = noCros(SQUARE, r, s, t, u);
                    if (valid == 0 || cross == 1) {
                        SQUARE[r - 1][s - 1] = 0;
                        SQUARE[t - 1][u - 1] = 0;
                        cout << "Check your ship size! Remember no Diagonals or CrissCross!\n";
                    } else {
                        //Function call is used to determine if ship crosses with another.
                        //This will fill gap for spaces between ship.
                        filShp(SQUARE, r, s, t, u, ship);
                        cout << endl;
                    }
                } while (valid == 0 || cross == 1); //valid is returned from ckGrid, if invalid 0 is returned
            }
                break;
            case 4:
            {
                ship = 3;

                do {
                    ship = 3;
                    cout << "Deploy TugBoat. Size is: " << ship << endl;
                    do {
                        //Input front of ship
                        bsBoard(SQUARE);
                        cout << "Deploy TugBoat. Size is: " << ship << endl;
                        cout << "Type the coordinate for the front of the boat. ex. For(1,4) type 1 4 [Enter]\n";
                        cin >> a>>b;
                        if (a <= ROW && a >= 1 && b <= COL && b >= 1) {
                            if (SQUARE[a - 1][b - 1] != 1) {
                                deny = 0;
                                SQUARE[a - 1][b - 1] = 1;
                            } else
                                deny = 1;
                        } else if (a > ROW || b > COL || a < 1 || b < 1) {
                            SQUARE[a - 1][b - 1] = 0;
                        }
                    } while (a < 1 || a > ROW || b < 1 || b > COL || deny == 1);
                    do {

                        //Input rear of ship
                        cout << "Deploy TugBoat. Size is: " << ship << endl;
                        cout << "Type the coordinate for the rear of the boat. ex. For(1,4) type 1 4 [Enter]\n";
                        cin >> c>>d;
                        if (c <= ROW && c >= 1 && d <= COL && d >= 1) {
                            if (SQUARE[c - 1][d - 1] != 1) {
                                deny = 0;
                                SQUARE[c - 1][d - 1] = 1;
                            } else
                                deny = 1;
                        } else if (c > ROW || d > COL || c < 1 || d < 1) {
                            SQUARE[c - 1][d - 1] = 0;
                        }
                    } while (c < 1 || c > ROW || d < 1 || d > COL || deny == 1);
                    valid = ckGrid(SQUARE, a, b, c, d, ship);
                    cross = noCros(SQUARE, a, b, c, d);
                    if (valid == 0 || cross == 1) {
                        SQUARE[a - 1][b - 1] = 0;
                        SQUARE[c - 1][d - 1] = 0;
                        cout << "Check your ship size! Remember no Diagonals or CrissCross!\n";
                    } else {
                        //Function call is used to determine if ship crosses with another.
                        //This will fill gap for spaces between ship.
                        filShp(SQUARE, a, b, c, d, ship);
                        cout << endl;
                    }
                } while (valid == 0 || cross == 1); //valid is returned from ckGrid, if invalid 0 is returned
            }
                break;
            default:
                break;
        }
    }

    cpuDply(CPUGRD, SQUARE); //auto-generate CPU's ship deployment  
}
//////////////Function for Game Rules///////////////////////////////////////////

int rules() {
    int back; //hold variable that returns to start menu
    
    //Display Rules and Directions
    do {
        //cout << "\nRules for BattleShip\n\n";
        //cout << "Each player selects an area to place their ships, whether in horizontal or\n"
        //        "vertical. \n"
        //        "If a player strikes a spot in the grid that contains a part of the ship, \n"
        //        "an '3' will be displayed in order to mark the hit zone\n"
        //        "If a player misses, the spot will be left untouched.\n"
        //        "Inputs are taken by ROW first followed by COLUMN\n"
        //        "Press 1 to return to Main Menu\n";
        
        //Read from binary file
        fstream file("rules.bin",ios::binary | ios::in);
        if(!file.is_open()){
            cout<<"Error opening File!\n";
        }
        file.seekg(0);
        char ch;
        while(file.good()){
            file.get(ch);
            cout<<ch;
        }
        //leave rules?
        cin>>back;
    } while (back != 1);
    return back;//return to main menu
}
//////////////Checks to make sure coordinates are in range//////////////////////

bool ckGrid(int **ckAry, int x, int y, int a, int b, int shipSz) {
    //Check ship size an verify
    if (x != a && y != b)
        return 0;
    else {
        if (x == a && y == b)
            return 0;
        else {
            if (shipSz == 3) {
                if (a == x || a == (x - shipSz + 1) || a == (x + shipSz - 1)) {
                    if (b == y || b == (y - shipSz + 1) || b == (y + shipSz - 1)) {
                        return 1;
                    } else
                        return 0;
                } else
                    return 0;
            } else if (shipSz == 4) {
                if (a == x || a == (x - shipSz + 1) || a == (x + shipSz - 1)) {
                    if (b == y || b == (y - shipSz + 1) || b == (y + shipSz - 1)) {
                        return 1;
                    } else
                        return 0;
                } else
                    return 0;
            }
            else if (shipSz == 5) {
                if (a == x || a == (x - shipSz + 1) || a == (x + shipSz - 1)) {
                    if (b == y || b == (y - shipSz + 1) || b == (y + shipSz - 1)) {
                        return 1;
                    } else
                        return 0;
                } else
                    return 0;
            } else
                return 0;
        }
    }
}
//////////////Fills a series of elements for respective ships///////////////////

void filShp(int **fillsh, int x, int y, int a, int b, int shipSz) {
    if (a == x) { //if on the same row
        if (y < b) { //if front of ship is closest to 1
            for (int len = y; len < b; len++) {
                fillsh[x - 1][len] = 1;
            }
        } else if (y > b) {
            for (int len = b; len < y; len++) {
                fillsh[x - 1][len] = 1;
            }
        }
    } else if (b == y) { //if on the same column
        if (x < a) { //if rear of ship is closes to 1  
            for (int len = x; len < a; len++) {
                fillsh[len][y - 1] = 1;
            }
        } else if (x > a) {
            for (int len = a; len < x; len++) {
                fillsh[len][y - 1] = 1;
            }
        }
    }
}
/////////////Check criss crossing ships/////////////////////////////////////////

bool noCros(int **plyG, int x, int y, int a, int b) {
    //Declare Variables
    int lowX = x < a ? x : a; //Place holders for lowest/highest X axis value
    int hiX = x > a ? x : a;
    int lowY = y < b ? y : b; //Place holders for lowest/highest Y axis 
    int hiY = y > b ? y : b;

    if (x == a) {
        for (int t = lowY; t < hiY; t++) {
            if (plyG[x][t] != 0) {
                return 1;
            }
        }
    } else if (y == b) {
        for (int u = lowX; u < hiX; u++) {
            if (plyG[u][y] != 0) {
                return 1;
            }
        }
    }
    return 0;
}
/////////////Generate CPU ship grid/////////////////////////////////////////////

void cpuDply(int **CPUGRD, int **SQUARE) {
    //declare variables
    int ship, valid, cross, deny, i, j, k, l; //i,j,k,l are grid holders for carrier ship
    int a, b, c, d; //abcd grid holders for tugboat
    int m, n, o, p, r, s, t, u; //mnop grid holders for gunship
    //rstu grid holders for submarine                                                       
    //This Function is used to allow user to select ship deployment
    //Computer self deploys ships
    cout << "\nCPU will now Deploy Fleet!\n";
    for (int menu = 0; menu < 5; menu++) {
        //ship=i;
        switch (menu) {
            case 1:
            {
                do { //Ship 1
                    ship = 5; //ship size

                    do {
                        //Input front of ship
                        i = rand() % 10 + 1;
                        j = rand() % 10 + 1;
                        if (i <= ROW && i >= 1 && j <= COL && j >= 1) {
                            if (CPUGRD[i - 1][j - 1] != 1) {
                                deny = 0;
                                CPUGRD[i - 1][j - 1] = 1;
                            } else deny = 1;
                        } else if (i > ROW || j > COL || i < 1 || j < 1) {
                            CPUGRD[i - 1][j - 1] = 0;
                        }
                    } while (i < 1 || i > ROW || j < 1 || j > COL || deny == 1);
                    do {
                        //Input rear of ship                        
                        k = rand() % 10 + 1;
                        l = rand() % 10 + 1;
                        if (k <= ROW && k >= 1 && l <= COL && l >= 1) {
                            if (CPUGRD[k - 1][l - 1] != 1) {
                                deny = 0;
                                CPUGRD[k - 1][l - 1] = 1;
                            } else deny = 1;
                        } else if (k > ROW || l > COL || k < 1 || l < 1) {
                            CPUGRD[k - 1][l - 1] = 0;
                        }
                    } while (k < 1 || k > ROW || l < 1 || l > COL || deny == 1);
                    valid = ckGrid(CPUGRD, i, j, k, l, ship);
                    cross = noCros(CPUGRD, i, j, k, l);
                    if (valid == 0 || cross == 1) {
                        CPUGRD[i - 1][j - 1] = 0;
                        CPUGRD[k - 1][l - 1] = 0;
                    } else {
                        //This will fill gap for spaces between ship.                      
                        filShp(CPUGRD, i, j, k, l, ship);
                        cout << endl;
                    }
                } while (valid == 0 || cross == 1); //valid is returned from ckGrid, if invalid 0 is returned
            }
                break;
            case 2:
            {
                do { //Ship 2
                    ship = 4;
                    do {
                        //Input front of ship
                        m = rand() % 10 + 1;
                        n = rand() % 10 + 1;
                        if (m <= ROW && m >= 1 && n <= COL && n >= 1) {
                            if (CPUGRD[m - 1][n - 1] != 1) {
                                deny = 0;
                                CPUGRD[m - 1][n - 1] = 1;
                            }
                            else deny = 1;
                        } else if (m > ROW || n > COL || m < 1 || n < 1) {
                            CPUGRD[m - 1][n - 1] = 0;
                        }
                    } while (m < 1 || m > ROW || n < 1 || n > COL || deny == 1);
                    do {
                        //Input rear of ship            
                        o = rand() % 10 + 1;
                        p = rand() % 10 + 1;
                        if (o <= ROW && o >= 1 && p <= COL && p >= 1) {
                            if (CPUGRD[o - 1][p - 1] != 1) {
                                deny = 0;
                                CPUGRD[o - 1][p - 1] = 1;
                            } else deny = 1;
                        } else if (o > ROW || p > COL || o < 1 || p < 1) {
                            CPUGRD[o - 1][p - 1] = 0;
                        }
                    } while (o < 1 || o > ROW || p < 1 || p > COL || deny == 1);
                    valid = ckGrid(CPUGRD, m, n, o, p, ship);
                    cross = noCros(CPUGRD, m, n, o, p);
                    if (valid == 0 || cross == 1) {
                        CPUGRD[m - 1][n - 1] = 0;
                        CPUGRD[o - 1][p - 1] = 0;
                    } else {
                        //This will fill gap for spaces between ship.
                        filShp(CPUGRD, m, n, o, p, ship);
                        cout << endl;
                    }
                } while (valid == 0 || cross == 1); //valid is returned from ckGrid, if invalid 0 is returned
            }
                break;
            case 3:
            {
                do {
                    ship = 3;
                    do {
                        //Input front of ship
                        r = rand() % 10 + 1;
                        s = rand() % 10 + 1;
                        if (r <= ROW && r >= 1 && s <= COL && s >= 1) {
                            if (CPUGRD[r - 1][s - 1] != 1) {
                                deny = 0;
                                CPUGRD[r - 1][s - 1] = 1;
                            } else deny = 1;
                        } else if (r > ROW || s > COL || r < 1 || s < 1) {
                            CPUGRD[r - 1][s - 1] = 0;
                        }
                    } while (r < 1 || r > ROW || s < 1 || s > COL || deny == 1);
                    do {
                        //Input rear of ship
                        t = rand() % 10 + 1;
                        u = rand() % 10 + 1;
                        if (t <= ROW && t >= 1 && u <= COL && u >= 1) {
                            if (CPUGRD[t - 1][u - 1] != 1) {
                                deny = 0;
                                CPUGRD[t - 1][u - 1] = 1;
                            } else deny = 1;
                        } else if (t > ROW || u > COL || t < 1 || u < 1) {
                            CPUGRD[t - 1][u - 1] = 0;
                        }
                    } while (t < 1 || t > ROW || u < 1 || u > COL || deny == 1);
                    valid = ckGrid(CPUGRD, r, s, t, u, ship);
                    cross = noCros(CPUGRD, r, s, t, u);
                    if (valid == 0 || cross == 1) {
                        CPUGRD[r - 1][s - 1] = 0;
                        CPUGRD[t - 1][u - 1] = 0;
                    } else {
                        //Function call is used to determine if ship crosses with another.
                        //This will fill gap for spaces between ship.
                        filShp(CPUGRD, r, s, t, u, ship);
                        cout << endl;
                    }
                } while (valid == 0 || cross == 1); //valid is returned from ckGrid, if invalid 0 is returned
            }
                break;
            case 4:
            {
                ship = 3;

                do {
                    ship = 3;

                    do {
                        //Input front of ship

                        a = rand() % 10 + 1;
                        b = rand() % 10 + 1;
                        if (a <= ROW && a >= 1 && b <= COL && b >= 1) {
                            if (CPUGRD[a - 1][b - 1] != 1) {
                                deny = 0;
                                CPUGRD[a - 1][b - 1] = 1;
                            } else deny = 1;
                        } else if (a > ROW || b > COL || a < 1 || b < 1) {
                            CPUGRD[a - 1][b - 1] = 0;
                        }
                    } while (a < 1 || a > ROW || b < 1 || b > COL || deny == 1);
                    do {
                        //Input rear of ship
                        c = rand() % 10 + 1;
                        d = rand() % 10 + 1;
                        if (c <= ROW && c >= 1 && d <= COL && d >= 1) {
                            if (CPUGRD[c - 1][d - 1] != 1) {
                                deny = 0;
                                CPUGRD[c - 1][d - 1] = 1;
                            } else deny = 1;
                        } else if (c > ROW || d > COL || c < 1 || d < 1) {
                            CPUGRD[c - 1][d - 1] = 0;
                        }
                    } while (c < 1 || c > ROW || d < 1 || d > COL || deny == 1);
                    valid = ckGrid(CPUGRD, a, b, c, d, ship);
                    cross = noCros(CPUGRD, a, b, c, d);
                    if (valid == 0 || cross == 1) {
                        CPUGRD[a - 1][b - 1] = 0;
                        CPUGRD[c - 1][d - 1] = 0;
                    } else {
                        //Function call is used to determine if ship crosses with another.
                        //This will fill gap for spaces between ship.
                        filShp(CPUGRD, a, b, c, d, ship);
                        cout << endl;
                    }
                } while (valid == 0 || cross == 1); //valid is returned from ckGrid, if invalid 0 is returned
            }
                break;
            default:
                break;
        }
    }
    cout << "\n\nComputer has Deployed a Fleet\n\n";
    hitMu(SQUARE, CPUGRD);
}
/////////////Toggle player turn/Hit Menu////////////////////////////////////////

int hitMu(int **SQUARE, int **CPUGRD) {
    int player = 1; //variable that holds player turn, will change between 1 and 2
    int x, y;
    bool win;

    //Set player toggle
    do {
        //Initialize variables
        win = false;
        x = -1;
        y = -1;
        player = (player % 2) ? 1 : 2;
        if (player == 1) {
            do {
                cout << "Your Turn!\n";
                cout << "Enter The Coordinate where you would like to strike!\n";
                cin >> x>>y;
            } while (x < 1 || x > ROW || y < 1 || y > COL);
        } else if (player == 2) {
            cout << "Computer's Turn\n";
            do {
                x = rand() % 10 + 1;
                y = rand() % 10 + 1;
            } while (x < 1 || x > ROW || y < 1 || y > COL);
        }
        if (player == 1) {
            win = hitZne(CPUGRD, ROW, x, y, player);
            if (win == true) {
                cout << "Player 1 Wins!\n";
                //free up allocated memory
                destroy(SQUARE, ROW);
                destroy(CPUGRD, ROW);
                return 0;
            }
        } else if (player == 2) {
            win = hitZne(SQUARE, ROW, x, y, player);
            if (win == true) {
                cout << "Computer Wins!\n";
                //free up allocated memory
                destroy(SQUARE, ROW);
                destroy(CPUGRD, ROW);
                return 0;
            }
        }
        player++;
    } while (win == false);
    return 0;
}
/////////////Checks if coordinate is a valid strike zone////////////////////////

bool hitZne(int **htAry, int ROW, int x, int y, int playr) {
    static int count = 15;
    static int countA = 15;
    Hit a;
    bool win = false; //Flag to indicate value was found
    //Check if Selection was a hit or miss
    if (htAry[x - 1][y - 1] == 1) {
        if (playr == 1) {
            HITGRID[x - 1][y - 1] = 3;
            htAry[x - 1][y - 1] = 3;
    /*            cout<<    "\t\t\t\t\t     __  ____________\n"<<
             "\t\t\t\t\t    / / / /  _/_  __/\n"<<
            "\t\t\t\t\t   / /_/ // /  / /   \n"<<
           "\t\t\t\t\t  / __  // /  / /    \n"<<
          "\t\t\t\t\t /_/ /_/___/ /_/     \n"<<
                   "\n";*/
            a.getHit();                         //read from file for HIT graphic
            cout<<endl;
            count--;
            cout << "Ships parts remaining: " << count << endl;
            hitGrd();
            if (count == 0) {
                return true;
            }
        } else if (playr == 2) {
            htAry[x - 1][y - 1] = 3;
            
          cout<<"       _       ________   __  _____ _    ________   ____  _____________   __   __  ______________\n"<<
          "      | |     / / ____/  / / / /   | |  / / ____/  / __ )/ ____/ ____/ | / /  / / / /  _/_  __/ /\n"<<
          "      | | /| / / __/    / /_/ / /| | | / / __/    / __  / __/ / __/ /  |/ /  / /_/ // /  / / / / \n"<<
          "      | |/ |/ / /___   / __  / ___ | |/ / /___   / /_/ / /___/ /___/ /|  /  / __  // /  / / /_/  \n"<<
          "      |__/|__/_____/  /_/ /_/_/  |_|___/_____/  /_____/_____/_____/_/ |_/  /_/ /_/___/ /_/ (_)  \n";
            countA--;
            bsBoard(htAry);
            if (count == 0) {
                return true;
            }
        }
    } else if (htAry[x - 1][y - 1] != 1) {
        if (playr == 1 || playr == 2) {
            cout << "Miss!\n";
        }
    }
    return win;
}
////////////Blank Grid to mark Hit Spots for Player to view/////////////////////

void hitGrd() {
    //Declare and Initialize Board 
    Legend diagram;
    diagram.hitMrk=3;
    diagram.lgnd="Legend";
    diagram.ship=1;
    cout<<endl<<endl;
    cout << diagram.lgnd<<" \t\t\t      B    A    T    T    L    E    S    H    I    P\n";
    cout << "-------\t\t\t      1    2    3    4    5    6    7    8    9   10 \n";
    cout << "Hit Marker: "<<diagram.hitMrk<<"\t\t    --------------------------------------------------\n";
    cout << "Ship Part: "<<diagram.ship<<"\t\t1   |  " << HITGRID[0][0] << " |  " << HITGRID[0][1] << " |  " << HITGRID[0][2] << " |  " << HITGRID[0][3] << " |  " << HITGRID[0][4] << " |  " << HITGRID[0][5] << " | "
            << HITGRID[0][6] << " |  " << HITGRID[0][7] << " |  " << HITGRID[0][8] << " |  " << HITGRID[0][9] << " |  " << endl;
    cout << "\t\t\t    --------------------------------------------------\n";
    cout << "\t\t\t2   |  " << HITGRID[1][0] << " |  " << HITGRID[1][1] << " |  " << HITGRID[1][2] << " |  " << HITGRID[1][3] << " |  " << HITGRID[1][4] << " |  " << HITGRID[1][5] << " | "
            << HITGRID[1][6] << " |  " << HITGRID[1][7] << " |  " << HITGRID[1][8] << " |  " << HITGRID[1][9] << " |  " << endl;
    cout << "\t\t\t    --------------------------------------------------\n";
    cout << "\t\t\t3   |  " << HITGRID[2][0] << " |  " << HITGRID[2][1] << " |  " << HITGRID[2][2] << " |  " << HITGRID[2][3] << " |  " << HITGRID[2][4] << " |  " << HITGRID[2][5] << " | "
            << HITGRID[2][6] << " |  " << HITGRID[2][7] << " |  " << HITGRID[2][8] << " |  " << HITGRID[2][9] << " |  " << endl;
    cout << "\t\t\t    --------------------------------------------------\n";
    cout << "\t\t\t4   |  " << HITGRID[3][0] << " |  " << HITGRID[3][1] << " |  " << HITGRID[3][2] << " |  " << HITGRID[3][3] << " |  " << HITGRID[3][4] << " |  " << HITGRID[3][5] << " | "
            << HITGRID[3][6] << " |  " << HITGRID[3][7] << " |  " << HITGRID[3][8] << " |  " << HITGRID[3][9] << " |  " << endl;
    cout << "\t\t\t    --------------------------------------------------\n";
    cout << "\t\t\t5   |  " << HITGRID[4][0] << " |  " << HITGRID[4][1] << " |  " << HITGRID[4][2] << " |  " << HITGRID[4][3] << " |  " << HITGRID[4][4] << " |  " << HITGRID[4][5] << " | "
            << HITGRID[4][6] << " |  " << HITGRID[4][7] << " |  " << HITGRID[4][8] << " |  " << HITGRID[4][9] << " |  " << endl;
    cout << "\t\t\t    --------------------------------------------------\n";
    cout << "\t\t\t6   |  " << HITGRID[5][0] << " |  " << HITGRID[5][1] << " |  " << HITGRID[5][2] << " |  " << HITGRID[5][3] << " |  " << HITGRID[5][4] << " |  " << HITGRID[5][5] << " | "
            << HITGRID[5][6] << " |  " << HITGRID[5][7] << " |  " << HITGRID[5][8] << " |  " << HITGRID[5][9] << " |  " << endl;
    cout << "\t\t\t    --------------------------------------------------\n";
    cout << "\t\t\t7   |  " << HITGRID[6][0] << " |  " << HITGRID[6][1] << " |  " << HITGRID[6][2] << " |  " << HITGRID[6][3] << " |  " << HITGRID[6][4] << " |  " << HITGRID[6][5] << " | "
            << HITGRID[6][6] << " |  " << HITGRID[6][7] << " |  " << HITGRID[6][8] << " |  " << HITGRID[6][9] << " |  " << endl;
    cout << "\t\t\t    --------------------------------------------------\n";
    cout << "\t\t\t8   |  " << HITGRID[7][0] << " |  " << HITGRID[7][1] << " |  " << HITGRID[7][2] << " |  " << HITGRID[7][3] << " |  " << HITGRID[7][4] << " |  " << HITGRID[7][5] << " | "
            << HITGRID[7][6] << " |  " << HITGRID[7][7] << " |  " << HITGRID[7][8] << " |  " << HITGRID[7][9] << " |  " << endl;
    cout << "\t\t\t    --------------------------------------------------\n";
    cout << "\t\t\t9   |  " << HITGRID[8][0] << " |  " << HITGRID[8][1] << " |  " << HITGRID[8][2] << " |  " << HITGRID[8][3] << " |  " << HITGRID[8][4] << " |  " << HITGRID[8][5] << " | "
            << HITGRID[8][6] << " |  " << HITGRID[8][7] << " |  " << HITGRID[8][8] << " |  " << HITGRID[8][9] << " |  " << endl;
    cout << "\t\t\t    --------------------------------------------------\n";
    cout << "\t\t\t10  |  " << HITGRID[9][0] << " |  " << HITGRID[9][1] << " |  " << HITGRID[9][2] << " |  " << HITGRID[9][3] << " |  " << HITGRID[9][4] << " |  " << HITGRID[9][5] << " | "
            << HITGRID[9][6] << " |  " << HITGRID[9][7] << " |  " << HITGRID[9][8] << " |  " << HITGRID[9][9] << " |  " << endl;
    cout << "\t\t\t    --------------------------------------------------\n";
}
//Destroy allocated memory
void destroy(int **array,int rows){
    //Destroy in reverse order of creation
    for(int i=0;i<rows;i++){
        delete []array[i];
    }
    delete []array;
    cout<<"Memory CLeared!\nGame Will now exit...\n";
}