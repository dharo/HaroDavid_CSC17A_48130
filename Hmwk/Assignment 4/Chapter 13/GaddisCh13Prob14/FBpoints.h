#ifndef FBPOINTS_H_
#define FBPOINTS_H_
class FBpoints
{
public:
	FBpoints(void);
	FBpoints(int tmp);
	void setTemp(int);
	int getTemp() const;
	bool isEthylFreezing();
	bool isEthylBoiling();
	bool isOxygenFreezing();
	bool isOxygenBoiling();
	bool isWaterFreezing();
	bool isWaterBoiling();
private:
	int temp;
};

#endif