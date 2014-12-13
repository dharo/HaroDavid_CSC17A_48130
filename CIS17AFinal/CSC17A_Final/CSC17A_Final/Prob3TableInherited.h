/* 
 * File:   Prob3TableInherited.h
 * Author: davidharo
 *
 * Created on December 11, 2014, 11:15 PM
 */

#ifndef PROB3TABLEINHERITED_H
#define	PROB3TABLEINHERITED_H

#include "Prob3Table.h"

template<class T>
class Prob3TableInherited : public Prob3Table<T>
{
	protected:
            T *augTable; 
	public:
          //Constructor
            Prob3TableInherited<T>(char *file,int row, int col) : Prob3Table<T>(file,row,col){ 
                T* sumTable = new T[(Prob3Table<T>::rows+1)*(Prob3Table<T>::cols+1)];
                //set table inputs
                for(int i=0; i < Prob3Table<T>::rows; i++){
                    for(int j=0; j < Prob3Table<T>::cols; j++){
                        sumTable[i*(Prob3Table<T>::cols+1)+j] = Prob3Table<T>::table[i*Prob3Table<T>::cols+j];
                    }
                }
                //set summed amounts
                for(int i=0; i<Prob3Table<T>::cols; i++){
                    sumTable[((Prob3Table<T>::cols+1)*Prob3Table<T>::rows)+ i] = Prob3Table<T>::rowSum[i];
                }
                for(int i=0; i<Prob3Table<T>::rows; i++){
                    sumTable[(Prob3Table<T>::cols+1)*(i+1)-1] = Prob3Table<T>::colSum[i];
                }
                //set table total
                sumTable[(Prob3Table<T>::rows+1)*(Prob3Table<T>::cols+1)-1] = Prob3Table<T>::grandTotal;
                augTable = sumTable;
            }
            ~Prob3TableInherited<T>(){
                delete [] augTable;         //destroy!
            }  
            //return pointer to table
            const T *getAugTable(void){return augTable;}; 
};


#endif	/* PROB3TABLEINHERITED_H */

