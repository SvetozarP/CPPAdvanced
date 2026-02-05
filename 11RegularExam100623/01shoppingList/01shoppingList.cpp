#include <iostream>
#include <sstream>
#include <map>

using namespace std;

int main()
{
	int numberOfItems;
	cin >> numberOfItems;


	string itemName;
	double itemPrice;
	int itemQuantity;

	double totalPrice = 0.0;

	multimap<double, string, greater<double>> shoppingList;

	for (int i = 0; i < numberOfItems; ++i)
	{
		cin >> itemName >> itemPrice >> itemQuantity;
		double totalItemPrice = itemPrice * itemQuantity;
		totalPrice += totalItemPrice;
		shoppingList.insert({ totalItemPrice, itemName });
	}

	cout << "The total sum is: " << totalPrice << " lv." << endl;

	for (const auto& item : shoppingList)
	{
		cout << item.second << " " << item.first << endl;
	}

	return 0;
}	

