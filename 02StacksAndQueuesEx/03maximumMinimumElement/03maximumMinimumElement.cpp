#include <iostream>
#include <sstream>
#include <stack>
#include <string>

using namespace std;

int main()
{
	int commandsCount;
	cin >> commandsCount;
	cin.ignore(); // To ignore the newline character after the integer input

	stack<int> numbers;
	
	while (commandsCount--) {
		string command;
		getline(cin, command);
		istringstream iss(command);
		
		char operation;
		int value;
		iss >> operation;

		switch(operation) {
			case '1': // Push
				iss >> value;
				numbers.push(value);
				break;
			case '2': // Pop
				if (!numbers.empty()) {
					numbers.pop();
				}
				break;
			case '3': // Print max
				if (!numbers.empty()) {
					stack<int> tempStack = numbers;
					int maxElement = tempStack.top();
					while (!tempStack.empty()) {
						int current = tempStack.top();
						tempStack.pop();
						if (current > maxElement) {
							maxElement = current;
						}
					}
					cout << maxElement << endl;
				}
				break;
			case '4': // Print min
				if (!numbers.empty()) {
					stack<int> tempStack = numbers;
					int minElement = tempStack.top();
					while (!tempStack.empty()) {
						int current = tempStack.top();
						tempStack.pop();
						if (current < minElement) {
							minElement = current;
						}
					}
					cout << minElement << endl;
				}
				break;
			default:
				break;
		}
	}

	if (!numbers.empty()) {
		stack<int> tempStack = numbers;
		string output;
		while (!tempStack.empty()) {
			output += to_string(tempStack.top());
			tempStack.pop();
			if (!tempStack.empty()) {
				output += ", ";
			}
		}
		cout << output << endl;
	}

	return 0;


}
