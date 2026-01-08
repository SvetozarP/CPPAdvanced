#include <iostream>
#include <stack>
#include <string>
#include <vector>
#include <sstream>

using namespace std;

int main()
{
	stack<int> numbers;
	stack<char> operations;
	
	string input;
	getline(cin, input);
	
	istringstream iss(input);

	int operand;
	while (iss >> operand) {
		numbers.push(operand);
		char op;
		if (iss >> op) {
			operations.push(op);
		}
		else
			break;
	}
	
	int sum = 0;
	while (operations.size()) {
		char operation;
		int argument;

		operation = operations.top();
		operations.pop();
		argument = numbers.top();
		numbers.pop();
		
		switch (operation) {
			case '+':
				sum += argument;
				break;
			case '-':
				sum -= argument;
				break;
			default:
				cerr << "Unknown operation: " << operation << endl;
				return 1;
		}
	}
	if (!numbers.empty()) {
		sum += numbers.top();
		numbers.pop();
	}
	cout << sum << endl;
	return 0;
}
