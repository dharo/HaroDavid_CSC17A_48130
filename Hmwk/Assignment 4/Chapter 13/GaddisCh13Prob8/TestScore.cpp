#include "TestScore.h"


TestScore::TestScore(void)
{
}


TestScore::TestScore(float a, float b, float c){
	test1=a;
	test2=b;
	test3=c;
}

float TestScore::avgScore(){
	return (test1+test2+test3)/3;
}

float TestScore::getOne() const{
	return test1;
}
float TestScore::getTwo() const{
	return test2;
}

float TestScore::getThree() const{
	return test3;
}

void TestScore::setOne(float a){
	test1=a;
}

void TestScore::setTwo(float a){
	test2=a;
}
void TestScore::setThree(float a){
	test3=a;
}