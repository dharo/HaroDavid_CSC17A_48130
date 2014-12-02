/*
 * Car.cpp
 *
 *  Created on: Nov 13, 2014
 *      Author: davidharo
 */

#include "Car.h"
#include <iostream>
#include <string>


Car::Car(){
	std::cout<<"Constructor: \n";
	yearModel=0;
	make="";
	speed=0;
}
//setters
void Car::setyrMod(int modelYr){
	yearModel=modelYr;
}
void Car::setMk(std::string vmake){
	make=vmake;
}
void Car::setSpd(int carSpd){
	speed=carSpd;
}
//getters
int Car::getMod() const{
	return yearModel;
}
std::string Car::getMk() const{
	return make;
}
int Car::getSpd() const{
	return speed;
}
//mutator
int Car::accel(){
	return speed+=5;
}
int Car::brake(){
	return speed-=5;
}
