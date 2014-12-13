/*
 * Prob1Random.h
 *
 *      Author: davidharo
 */

#ifndef PROB1RANDOM_H_
#define PROB1RANDOM_H_

class Prob1Random {
private:
	unsigned char *set;      //The set of numbers to draw random numbers from
	unsigned char  nset;     //The number of variables in the sequence
	int  *freq;              //Frequency of all the random numbers returned
	int   numRand;           //The total number of times the random number function is called
public:
	Prob1Random(unsigned char,unsigned char *);     //Constructor
	~Prob1Random(void);                             //Destructor
	unsigned char randFromSet(void);                //Returns a random number from the set
	int *getFreq(void) const;                       //Returns the frequency histogram
	unsigned char *getSet(void) const;              //Returns the set used
	int getNumRand(void) const;                     //Gets the number of times randFromSet has
                                                        //been called
};

#endif /* PROB1RANDOM_H_ */
