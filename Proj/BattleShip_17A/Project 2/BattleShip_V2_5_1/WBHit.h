/* 
 * File:   WBHit.h
 * Author: davidharo
 *
 * Created on December 8, 2014, 6:51 AM
 */

#ifndef WBHIT_H
#define	WBHIT_H

#include <iostream>
#include <string>
#include <fstream>
#include <cstring>
#include "Hit.h"
using namespace std;


class WBHit : public Hit{
private:
    int err;
    
public:
    WBHit();
    bool isRead();
    void getHit();
};

#endif	/* WBHIT_H */

