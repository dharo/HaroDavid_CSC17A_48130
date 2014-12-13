/* 
 * text:   Prob3Table.h
 * Author: davidharo
 *
 * Created on December 11, 2014, 11:14 PM
 */

#ifndef PROB3TABLE_H
#define	PROB3TABLE_H

#include <cstdlib>
#include <string>
#include <fstream>

using namespace std;

template<class T>
class Prob3Table{
    protected:
        int rows;                                 //Number of rows in the table
        int cols;                                 //Number of cols in the table
        T *rowSum;                                //RowSum array
        T *colSum;                                //ColSum array
        T *table;                                 //Table array
        T grandTotal;                             //Grand total
        void calcTable(void);                     //Calculate all the sums
    public:
        Prob3Table(char *,int,int);               //Constructor then Destructor
        ~Prob3Table(){delete [] table;delete [] rowSum;delete [] colSum;};
        const T *getTable(void){return table;};
        const T *getRowSum(void){return rowSum;};
        const T *getColSum(void){return colSum;};
        T getGrandTotal(void){return grandTotal;};
};
template<class T>
Prob3Table<T>::Prob3Table(char *file, int row, int col){
    //declare variables for reading text
    fstream text;
    string a;
    //Set variables
    rows = row;
    cols = col;
    //initialize pointer
    T* tbl = new T[rows*cols];

    //read from Problem3.txt
    text.open(file,ios::in);
    for(int i = 0; i < rows; i++){
        getline(text,a);
        //convert string to integer
        for(int j = 0; j < cols; j++){
            tbl[i*cols+j] = atoi(a.c_str());       //use of cstdlib and string
            a.erase(a.begin(),a.begin()+6);  
        }
    }
    //copy to table and close
    table = tbl;
    text.close();
    //sum columns and rows
    T* addRow = new T[cols];
    for(int i=0; i<cols; i++){
        int foo = 0;
        for(int j=0; j<rows; j++){
            foo += table[j*cols+i];
        }
        addRow[i]=foo;
    }
    rowSum = addRow;
    T* colAdd = new T[rows];
    for(int i=0; i<rows; i++){
        int foo = 0;
        for(int j=0; j<cols; j++){
            foo += table[i*cols+j];
        }
        colAdd[i]=foo;
    }
    colSum = colAdd; 
    //initialize grand total variable and sum amounts
    int total = 0;
    for(int i = 0; i<cols*rows; i++){
        total += table[i];
    }
    grandTotal = total;
}


#endif	/* PROB3TABLE_H */

