/*Inventory.cpp
 Created on: Nov 14, 2014
     Author: davidharo
*/

#include "Inventory.h"
#include <iostream>


Inventory::Inventory(){
	itemNumber=0;
	quantity=0;
	cost=0;
	totalcost=0;
}
Inventory::Inventory(int itNum, int qty, float price){
	//std::cout<<"test\n";
	itemNumber=itNum;
	quantity=qty;
	cost=price;
	Inventory::setTotal();
}
void Inventory::setItemNumber(int inum){
	itemNumber=inum;
}
void Inventory::setQuantity(int num){
	quantity=num;
}
void Inventory::setCost(float itPrice){
	cost=itPrice;
}
void Inventory::setTotal(){
	totalcost=cost*quantity;
}

int Inventory::getItemNum(){
	return itemNumber;
}
int Inventory::getQuantity(){
	return quantity;
}
float Inventory::getCost(){
	return cost;
}
float Inventory::getTotal(){
	return totalcost;
}
