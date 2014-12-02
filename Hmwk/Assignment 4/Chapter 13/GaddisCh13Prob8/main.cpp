/*
	David Haro
	Gaddis 7th Edition Chapter 13 Problem 8
	Test Scores Class
*/

#include <iostream>
#include "TestScore.h"
using namespace std;

int main( int argc, const char* argv[] ){
	//declare variables
	float a,b,c;		//test score variables
	TestScore student;

	//prompt for user input
	cout<<"Please enter the score for test #1: ";
	cin>>a;
	cout<<"Please enter the score for test #2: ";
	cin>>b;
	cout<<"Please enter the score for test #3: ";
	cin>>c;

	//pass results into TestScores class for calculation
	student.setOne(a);
	student.setTwo(b);
	student.setThree(c);
	cout<<endl<<endl<<endl;
	cout<<"Test1: "<<student.getOne()<<endl;
	cout<<"Test2: "<<student.getTwo()<<endl;
	cout<<"Test3: "<<student.getThree()<<endl;
	//display average score
	cout<<"Average Test Score: "<<student.avgScore()<<endl;


	system("PAUSE");
}