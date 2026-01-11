#include <iostream>
#include <sstream>
#include <queue>
#include <string>

using namespace std;

int main()
{
	int numberPetrolPumps;
	cin >> numberPetrolPumps;
	queue<pair<int, int>> petrolPumps; // pair<petrol, distance>
	for (int i = 0; i < numberPetrolPumps; i++)
	{
		int petrol, distance;
		cin >> petrol >> distance;
		petrolPumps.push({ petrol, distance });
	}
	int startingPumpIndex = 0;

	while (true)
	{
		int totalPetrol = 0;
		bool canCompleteTour = true;
		for (int i = 0; i < numberPetrolPumps; i++)
		{
			pair<int, int> currentPump = petrolPumps.front();
			petrolPumps.pop();
			totalPetrol += currentPump.first;
			if (totalPetrol < currentPump.second)
			{
				canCompleteTour = false;
			}
			else
			{
				totalPetrol -= currentPump.second;
			}
			petrolPumps.push(currentPump);
		}
		if (canCompleteTour)
		{
			cout << startingPumpIndex << endl;
			break;
		}
		else
		{
			petrolPumps.push(petrolPumps.front());
			petrolPumps.pop();
			startingPumpIndex++;
		}
	}
	return 0;
}
