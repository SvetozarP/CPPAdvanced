#include <iostream>
#include <string>
#include <sstream>
#include <stack>

using namespace std;

int main()
{
	string input;
	getline(cin, input);

	stack<char> charStack;
	for (char ch : input)
	{
		charStack.push(ch);
	}

	while (!charStack.empty())
	{
		cout << charStack.top();
		charStack.pop();
	}

	return 0;
}
