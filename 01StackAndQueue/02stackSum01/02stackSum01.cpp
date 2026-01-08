#include <iostream>
#include <stack>
#include <string>
#include <vector>
#include <sstream>

using namespace std;

void addNumbers(stack<int>& numbers, istringstream& commandStream)
{
	int first, second;
	commandStream >> first >> second;
	numbers.push(first);
	numbers.push(second);
}

void removeNumbers(stack<int>& numbers, istringstream& commandStream)
{
	int count;
	commandStream >> count;
	if (count <= numbers.size())
	{
		for (int i = 0; i < count; ++i)
		{
			numbers.pop();
		}
	}
}

void sumStack(stack<int>& numbers)
{
	int sum = 0;
	while (!numbers.empty())
	{
		sum += numbers.top();
		numbers.pop();
	}
	cout << sum << endl;
}

int main()
{
	stack<int> numbers;

	string buffer;
	getline(cin, buffer);
	istringstream iss(buffer);
	int number;

	while (iss >> number)
	{
		numbers.push(number);
	}

	getline(cin, buffer);
	while (buffer != "end")
	{
		istringstream commandStream(buffer);
		string command;
		commandStream >> command;
		if (command == "add")
		{
			addNumbers(numbers, commandStream);
		}
		else if (command == "remove")
		{
			removeNumbers(numbers, commandStream);

		}
		getline(cin, buffer);
	}

	int sum = 0;
	sumStack(numbers);
	return 0;

}
