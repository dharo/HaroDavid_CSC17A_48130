#include "FBpoints.h"


FBpoints::FBpoints(void)
{
}


FBpoints::FBpoints(int tmp){
	temp=tmp;
}
bool FBpoints::isEthylFreezing(){
	int t=temp;

	if (t <= -173)
		return 1;
	else
		return 0;
}
bool FBpoints::isEthylBoiling(){
	int t = temp;
	if (t >= 172)
		return 1;
	else
		return 0;
}
bool FBpoints::isOxygenBoiling(){
	int t = temp;
	if (t >= -306)
		return 1;
	else
		return 0;
}
bool FBpoints::isOxygenFreezing(){
	int t = temp;
	if (t <= -362)
		return 1;
	else
		return 0;
}

bool FBpoints::isWaterBoiling(){
	int t = temp;
	if (t >= 212)
		return 1;
	else
		return 0;
}
bool FBpoints::isWaterFreezing(){
	int t = temp;
	if (t <= 32)
		return 1;
	else
		return 0;
}
void FBpoints::setTemp(int t){
	temp = t;
}
int FBpoints::getTemp() const {
	return temp;
}