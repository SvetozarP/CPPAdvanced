#include <iostream>
#include <set>

using namespace std;

void readSet(set<int>& s, int n)
{
	for (int i = 0; i < n; ++i) {
		int element;
		cin >> element;
		s.insert(element);
	}
}

int main()
{
	set<int> setA;
	set<int> setB;

	int n, m;
	cin >> n >> m;

	readSet(setA, n);
	readSet(setB, m);

	for (const int& element : setA) {
		if (setB.find(element) != setB.end()) {
			cout << element << " ";
		}
	}

	cout << endl;

	return 0;
}
