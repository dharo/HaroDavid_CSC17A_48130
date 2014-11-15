#include <iostream>


using namespace std;


int main (int argc, const char * argv[]) {
    // insert code here...
    cout << "Hello, World!\n";
    return 0;
}

class CashRegister{
	private:
		int amount;
		float cost;
		const float profit=3.0e-1;
		const float sales_tax=6.0e-2;
	public:
		void setCost();		//getCost(); from InventoryItem class
		void setAmount();	//getQuantity(); from Inventory Item class
		float addTax(float);	//get subtotal and add 6% sales tax
		float addProfit(float);	//get item cost and add 30% profit
		void displayRegister(); //display purchase subtotal, tax, and total		
};