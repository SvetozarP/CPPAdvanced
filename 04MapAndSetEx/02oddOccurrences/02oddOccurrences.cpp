#include <iostream>
#include <sstream>
#include <unordered_map>
#include <algorithm>
#include <cctype>
#include <string>
#include <vector>

using namespace std;

int main()
{
	string input;
	getline(cin, input);

	istringstream iss(input);
	unordered_map<string, int> fraction_counts;
	string current_fraction;
	vector<string> appearance_order;

    while (iss >> current_fraction)
    {
        transform(current_fraction.begin(), current_fraction.end(), current_fraction.begin(),
            [](unsigned char c) { return tolower(c); });

        if (fraction_counts.find(current_fraction) == fraction_counts.end()) {
            appearance_order.push_back(current_fraction);
        }
        fraction_counts[current_fraction]++;
    }

    bool first_odd_fraction = true;

    for (const string& fraction : appearance_order) {
        int count = fraction_counts[fraction];

        if (count % 2 != 0) {
            if (!first_odd_fraction) {
                cout << ", ";
            }
            cout << fraction;

            first_odd_fraction = false;
        }
    }
    cout << '\n';

    return 0;
}
