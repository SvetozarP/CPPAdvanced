#include <iostream>
#include <stack>
#include <vector>
#include <sstream>

using namespace std;

int main()
{
	vector<int> numbers;
	string line;
	getline(cin, line);
	stringstream ss(line);
	int number;
	while (ss >> number)
	{
		numbers.push_back(number);
	}
}
