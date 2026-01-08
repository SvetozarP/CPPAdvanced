#include <iostream>
#include <stack>
#include <string>
#include <vector>
#include <sstream>

using namespace std;

int main()
{
	string input;
	getline(cin, input);

	stack<size_t> OpenBraketPositions;
	for (size_t i = 0; i < input.length(); ++i) {
		
		char ch = input[i];
		switch (ch) {
			case '(':
			{
				OpenBraketPositions.push(i);
				break;
			}
			case ')':
			{
				size_t matchingOpenPosition = OpenBraketPositions.top();
				OpenBraketPositions.pop();
				string insideBrakets = input.substr(matchingOpenPosition, i - matchingOpenPosition + 1);
				cout << insideBrakets << endl;
			}
			break;
		}
	}
	return 0;
}
