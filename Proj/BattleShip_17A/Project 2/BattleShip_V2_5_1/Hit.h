/* 
 * File:   Graphics.h
 * Author: davidharo
 *
 * Created on December 5, 2014, 11:48 PM
 */

#ifndef HIT_H
#define	HIT_H

#include <string>
#include <fstream>
#include <cstring>
#include <iostream>

using namespace std;



class Hit {
private:
    string err;
public:
    Hit();
    virtual ~Hit(){}
    void setErr();
    string getErr();
    virtual void getHit();
    
};

#endif	/* HIT_H */

