/*
 * Inventory.h
 *
 *  Created on: Nov 14, 2014
 *      Author: davidharo
 */

#ifndef INVENTORY_H_
#define INVENTORY_H_

class Inventory {
public:
	Inventory();
	Inventory(int itNum, int qty, float price);
	void setItemNumber(int);
	void setQuantity(int);
	void setCost(float);
	void setTotal();
	int getItemNum() const;
	int getQuantity() const;
	float getCost() const;
	float getTotal() const;
private:
	int itemNumber;
	int quantity;
	float cost;
	float totalcost;
};

#endif /* INVENTORY_H_ */
