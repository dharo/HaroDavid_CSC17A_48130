#include "Numbers.h"
#include <string>
#include <iostream>
using namespace std;
Numbers::Numbers(void){
}

string Numbers::lessThan20[20] = {"one","two","three","four","five","six","seven","eight","nine","ten","eleven","twelve","thirteen","fourteen","fifteen","sixteen","seventeen","eighteen","nineteen"};
string Numbers::tens[8]={"twenty","thirthy","forty","fifty","sixty","seventy","eighty","ninety"};
string Numbers::hundred = "hundred";
string Numbers::thousand = "thousand";


void Numbers::print(){
	int a = number;
	int b;
	int temp;
	//if 1000 or more, get its value and convert
	if(a>999){
		//hundreds and thousands
		b=a%1000;
		temp=a-b;
		b=temp/1000;
		cout<<lessThan20[b-1]<<" "<<thousand<<" ";
		a=a%1000;
		b=a%100;
		temp=a-b;
		b=temp/100;
		cout<<lessThan20[b-1]<<" "<<hundred<<" ";
		//tens and ones
		a=a%100;
		b=a%10;
		temp=a-b;
		b=temp/10;
		cout<<tens[b-2]<<" ";
		b=a%10;
		cout<<lessThan20[b-1]<<" ";

	}
	else if(a<=999 && a > 99){
		//hundreds
		b=a%100;
		temp=a-b;
		b=temp/100;
		cout<<lessThan20[b-1]<<" "<<hundred<<" ";
		//tens
		a=a%100;
		b=a%10;
		temp=a-b;
		b=temp/10;
		cout<<tens[b-2]<<" ";
		b=a%10;
		cout<<lessThan20[b-1]<<" ";
	}
	else if(a <= 99 && a > 19){
		//20 or more but less than 100
		b=a%10;
		temp=a-b;
		b=temp/10;
		cout<<tens[b-2]<<" ";
		b=a%10;
		cout<<lessThan20[b-1]<<" ";
	}
	else if (a<20){
		//less than 20
		cout<<lessThan20[a-1];
	}
}

void Numbers::setNum(int a){
	number = a;
}
int Numbers::getNum() const{
	return number;
}