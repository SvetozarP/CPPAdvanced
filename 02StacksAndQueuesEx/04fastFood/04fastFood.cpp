#include <iostream>
#include <sstream>
#include <queue>
#include <algorithm>

using namespace std;

int main()
{
    int foodQuantity;
    cin >> foodQuantity;

    queue<int> orders;
    int order;
    int biggestOrder = 0;

    string ordersLine;
    cin.ignore();
    getline(cin, ordersLine);
    istringstream iss(ordersLine);

    while (iss >> order)
    {
        orders.push(order);
        if (order > biggestOrder) {
            biggestOrder = order;
        }
    }

    cout << biggestOrder << "\n";

    while (!orders.empty() && foodQuantity >= orders.front())
    {
        foodQuantity -= orders.front();
        orders.pop();
    }

    if (orders.empty())
    {
        cout << "Orders complete\n";
    }
    else
    {
        cout << "Orders left: ";
        while (!orders.empty())
        {
            cout << orders.front();
            orders.pop();
            if (!orders.empty())
            {
                cout << " ";
            }
        }
        cout << "\n";
    }

    return 0;
}