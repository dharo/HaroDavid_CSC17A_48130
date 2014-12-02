#include <iostream>
#include "Inventory.h"

using namespace std;


int main (int argc, const char * argv[]) {
	int itemNum;
	int qty;
	float cost;

    cout<<"Enter the item Number: ";
    cin>>itemNum;
    //grocery.setItemNumber(itemNum);
    cout<<"Enter the quantity: ";
    cin>>qty;
    //grocery.setQuantity(qty);
    cout<<"Enter the cost: ";
    cin>>cost;
    //grocery.setCost(cost);

    //declare object and pass in parameters
    Inventory grocery(itemNum,qty,cost);
    //display results
    cout<<"Item Number: "<<grocery.getItemNum()<<endl;
    cout<<"Quantity: "<<grocery.getQuantity()<<endl;
    cout<<"Item Cost: "<<grocery.getCost()<<endl;
    cout<<"Total cost: "<<grocery.getTotal()<<endl;
    return 0;
}
