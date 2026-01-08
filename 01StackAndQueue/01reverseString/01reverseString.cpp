#include <iostream>
#include <string>
#include <stack>
#include <sstream>

using namespace std;

int main()
{
	string input;
	getline(cin, input);
	stack<char> charStack;
	for (char c : input)
	{
		charStack.push(c);
	}
	stringstream reversedStream;
	while (!charStack.empty())
	{
		reversedStream << charStack.top();
		charStack.pop();
	}
	cout << reversedStream.str() << endl;
	return 0;
}
