/*
 * Car.h
 *
 *  Created on: Nov 13, 2014
 *      Author: davidharo
 */

#ifndef CAR_H_
#define CAR_H_

#include <string>

class Car{
	private:
		int yearModel;
		std::string make;
		int speed;
	public:
		Car();	//constructor
		void setyrMod(int);
		void setMk(std::string);
		void setSpd(int) const;
		int getMod() const;
		std::string getMk() const;
		int getSpd();
		int accel();
		int brake();
};


#endif /* CAR_H_ */
