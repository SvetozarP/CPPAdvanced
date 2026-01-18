#include <iostream>
#include <sstream>
#include <map>

using namespace std;

int main()
{
	string input;
	getline(cin, input);
	istringstream iss(input);
	map<double, int> numberCount;
	double number;
	while (iss >> number)
	{
		numberCount[number]++;
	}

	for (const auto& [num, count] : numberCount)
	{
		cout << num << " -> " << count << endl;
	}

	return 0;
}
