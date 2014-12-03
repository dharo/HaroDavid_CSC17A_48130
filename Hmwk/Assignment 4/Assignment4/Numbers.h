#ifndef NUMBERS_H
#define NUMBERS_H

#include <string>
using namespace std;
class Numbers
{
private:
	int number;
	static string lessThan20[20];
	static string tens[8];
	static string hundred;
	static string thousand;
public:
	Numbers(void);
	Numbers(int);
	void setNum(int);
	int getNum() const;
	void print();

};
#endif