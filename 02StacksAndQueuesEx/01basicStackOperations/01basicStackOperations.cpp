#include <iostream>
#include <sstream>
#include <stack>

using namespace std;

void checkStack(stack<int> numbers, int X)
{
	if (numbers.empty())
	{
		cout << 0 << endl;
		return;
	}
	bool found = false;
	int minElement = numbers.top();
	while (!numbers.empty())
	{
		int current = numbers.top();
		numbers.pop();
		if (current == X)
		{
			found = true;
		}
		if (current < minElement)
		{
			minElement = current;
		}
	}
	if (found)
	{
		cout << "true" << endl;
	}
	else
	{
		cout << minElement << endl;
	}
}

int main()
{

	int N, S, X;
	cin >> N >> S >> X;

	stack<int> numbers;
	while (N--)
	{
		int number;
		cin >> number;
		numbers.push(number);
	}

	while (S-- && !numbers.empty())
	{
		numbers.pop();
	}
	checkStack(numbers, X);
	return 0;
}

