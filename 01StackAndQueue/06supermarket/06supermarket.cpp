#include <iostream>
#include <queue>
#include <string>
#include <sstream>

using namespace std;

int main()
{
	string input;
	getline(cin, input);

	queue<string> customers;
	queue<string> servedCustomers;

	while (input != "End") {
		customers.push(input);
		getline(cin, input);
	}

	bool paidCommandReceived = false;

	while (!customers.empty()) {
		
		string currentCustomer = customers.front();
		customers.pop();
		
		if (currentCustomer == "Paid") {
		
			while (!servedCustomers.empty()) {
				cout << servedCustomers.front() << endl;
				servedCustomers.pop();
			}
			paidCommandReceived = true;
			cout << customers.size() << " people remaining." << endl;
		
		} else {
			
			servedCustomers.push(currentCustomer);
		
		}

	}

	if (!paidCommandReceived) {
		cout << servedCustomers.size() << " people remaining." << endl;
	}

	return 0;
	
}
