#include <iostream>
#include <sstream>
#include <queue>

using namespace std;

void checkQueue(queue<int> numbers, int X)
{
	if (numbers.empty())
	{
		cout << 0 << endl;
		return;
	}
	bool found = false;
	int minElement = numbers.front();
	while (!numbers.empty())
	{
		int current = numbers.front();
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

	queue<int> numbers;
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
	checkQueue(numbers, X);
	return 0;
}
