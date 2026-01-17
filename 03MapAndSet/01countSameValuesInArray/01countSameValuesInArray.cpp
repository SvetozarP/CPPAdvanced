#include <iostream>
#include <sstream>
#include <vector>
#include <map>

using namespace std;

int main()
{
    string input;
	getline(cin, input);
	istringstream iss(input);
	
	vector<double> numbers;
	double number;
	map<double, int> counts;

	while (iss >> number) {
		if (counts.insert({ number, 1 }).second == false) {
			counts[number]++;
		}
		else {
			numbers.push_back(number);
		}
	}

	for (double num : numbers) {
		cout << num << " - " << counts[num] << " times" << endl;
	}
	return 0;
}
