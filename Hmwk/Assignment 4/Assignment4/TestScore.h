#ifndef TESTSCORE_H
#define TESTSCORE_H

class TestScore{
private:
	float test1;
	float test2;
	float test3;
public:
	TestScore(void);
	TestScore(float,float,float);  //set variables
	float getOne() const;		   //get score for test 1
	float getTwo() const;		   //get score for test 2
	float getThree() const;		   //get score for test 3
	void setOne(float);			   //mutator for test 1
	void setTwo(float);			   //mutator for test 2
	void setThree(float);		   //mutator for test 3
	float avgScore();			   //sum of tests/3 return average score
};

#endif