#include <iostream>
#include <sstream>
#include <vector>
#include <unordered_map>

using namespace std;

int main()
{
	string input;
	getline(cin, input);
	istringstream iss(input);

	vector<double> numbers;
	double number;
	unordered_map<double, int> counts;

	while (iss >> number) {
		if (counts.find(number) == counts.end()) {
			numbers.push_back(number);
		}
		counts[number]++;
	}

	for (double num : numbers) {
		cout << num << " - " << counts[num] << " times" << endl;
	}
	return 0;
}
