#ifndef DAYOFYEAR_H
#define DAYOFYEAR_H

#include <string>
using namespace std;

class DayOfYear{
private:
	int num;
	static string month[12];

public:
	DayOfYear(void);
	DayOfYear(int a){ num = a;};
	void setNum(int);
	int getNum();
	void print();
};

#endif