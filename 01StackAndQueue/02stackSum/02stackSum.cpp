#include <iostream>
#include <stack>
#include <string>
#include <vector>
#include <sstream>

using namespace std;

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
			int first, second;
			commandStream >> first >> second;
			numbers.push(first);
			numbers.push(second);
		}
		else if (command == "remove")
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
		getline(cin, buffer);
	}

	int sum = 0;
	while (!numbers.empty())
	{
		sum += numbers.top();
		numbers.pop();
	}
	cout << sum << endl;
	return 0;

}
