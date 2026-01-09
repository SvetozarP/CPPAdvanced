#include <iostream>
#include <queue>
#include <string>
#include <sstream>

using namespace std;

int main()
{
    string names;
	getline(cin, names);
	queue<string> players;
	istringstream iss(names);
	string name;
	while (iss >> name) {
		players.push(name);
	}

	int toss;
	cin >> toss;

	while (players.size() > 1) {
		for (int i = 1; i < toss; ++i) {
			string currentPlayer = players.front();
			players.pop();
			players.push(currentPlayer);
		}
		cout << "Removed " << players.front() << endl;
		players.pop();
	}
	cout << "Last is " << players.front() << endl;
	
}
