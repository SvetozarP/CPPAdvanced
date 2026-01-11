#include <iostream>
#include <sstream>
#include <stack>
#include <string>

using namespace std;

int main()
{
	string boxesLine;
	getline(cin, boxesLine);
	istringstream iss(boxesLine);
	stack<int> boxes;
	
	int box;
	
	while (iss >> box)
	{
		boxes.push(box);
	}

	int clothesCapacity;
	cin >> clothesCapacity;
	int currentClothes = 0;
	int racksUsed = 1;
	while (!boxes.empty())
	{
		if (currentClothes + boxes.top() <= clothesCapacity)
		{
			currentClothes += boxes.top();
			boxes.pop();
		}
		else
		{
			racksUsed++;
			currentClothes = 0;
		}
	}
	cout << racksUsed << '\n';
	return 0;
}
