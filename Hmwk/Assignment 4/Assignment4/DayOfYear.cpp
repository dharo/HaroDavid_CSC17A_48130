#include "DayOfYear.h"
#include <string>
#include <iostream>
using namespace std;

DayOfYear::DayOfYear(void){
}

void DayOfYear::setNum(int a){
	num = a;
}

int DayOfYear::getNum(){
	return num;
}

string DayOfYear::month[12] = {"January","February","March",
								"April","May","June","July",
								"August","September",
								"October","November","December"};

void DayOfYear::print(){
	int day = num;
	
	if (day>=1 && day <= 31){				//january
		cout<<month[0]<<" "<<day<<endl;
	}
	if(day>=32 && day <= 59){				//february
		cout<<month[1]<<" "<<(day-31)<<endl;
	}
	if(day>=60 && day <= 90){				//march
		cout<<month[2]<<" "<<(day-59)<<endl;
	}
	if(day>=91 && day <= 120){				//april
		cout<<month[3]<<" "<<(day-90)<<endl;		
	}
	if(day>=121 && day <= 151){				//may
		cout<<month[4]<<" "<<(day-120)<<endl;
	}
	if(day>=152 && day <= 181){				//june
		cout<<month[5]<<" "<<(day-151)<<endl;
	}
	if(day>=182 && day <= 212){				//july
		cout<<month[6]<<" "<<(day-181)<<endl;
	}
	if(day>=213 && day <= 243){				//august
		cout<<month[7]<<" "<<(day-212)<<endl;
	}
	if(day>=244 && day <= 273){				//september
		cout<<month[8]<<" "<<(day-243)<<endl;
	}
	if(day>=274 && day <= 304){				//october
		cout<<month[9]<<" "<<(day-273)<<endl;
	}
	if(day>=305 && day <= 334){				//november
		cout<<month[10]<<" "<<(day-304)<<endl;
	}
	if(day>=335 && day <= 365){				//december
		cout<<month[11]<<" "<<(day-334)<<endl;
	}



}