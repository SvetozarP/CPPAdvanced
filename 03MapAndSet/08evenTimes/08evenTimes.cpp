#include <iostream>
#include <sstream>
#include <unordered_map>

using namespace std;

int main()
{
	int numberOfEntries;
	cin >> numberOfEntries;
	cin.ignore();

	unordered_map<string, int> counts;
	
	while (numberOfEntries-- > 0) {
		string entry;
		getline(cin, entry);
		counts[entry]++;
	}

	for (const auto& [entry, count] : counts) {
		if (count % 2 == 0) {
			cout << entry << " ";
			break;
		}
	}
	return 0;
}
