#include <iostream>
#include <string>
#include <map>
#include <set>

using namespace std;

int main()
{
	int numberOfEntries;
	cin >> numberOfEntries;

    map<string,
		map<string, set<string>>> data;

	while (numberOfEntries-- > 0) {
		string continent, country, city;
		cin >> continent >> country >> city;
		data[continent][country].insert(city);
	}

	for (const auto& [continent, countries] : data) {
		cout << continent << ":" << endl;
	
		for (const auto& [country, cities] : countries) {
			cout << "  " << country << " -> ";
		
			bool first_city = true;
			for (const auto& city : cities) {
				if (!first_city) {
					cout << ", ";
				}
				cout << city;
				first_city = false;
			}
			cout << std::endl;
		}
	}
	return 0;
}
