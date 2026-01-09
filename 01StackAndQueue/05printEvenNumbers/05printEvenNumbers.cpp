#include <iostream>
#include <queue>
#include <string>
#include <sstream>

using namespace std;

int main()
{
	string input;
	getline(cin, input);
	
	istringstream iss(input);
	
	queue<int> numbers;
	int number;
	
	while (iss >> number) {
		numbers.push(number);
	}

	bool firstEven = true; 
	
	while (!numbers.empty()) {
		int currentNumber = numbers.front();
		numbers.pop();
		if (currentNumber % 2 == 0) {
			if (!firstEven) {
				cout << ", "; 
			}
			cout << currentNumber;
			firstEven = false; 
		}
	}
	cout << endl;
	return 0;
}
