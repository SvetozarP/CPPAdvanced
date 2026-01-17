#include <iostream>
#include <string>
#include <set>

using namespace std;

int main()
{
	int numberOfUsernames;
	cin >> numberOfUsernames;
	cin.ignore();
	set<string> uniqueUsernames;

	while (numberOfUsernames-- > 0) {
		string username;
		getline(cin, username);
		uniqueUsernames.insert(username);
	}

	for (const auto& username : uniqueUsernames) {
		cout << username << endl;
	}

	return 0;

}
