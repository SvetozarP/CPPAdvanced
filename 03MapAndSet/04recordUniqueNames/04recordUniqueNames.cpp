#include <iostream>
#include <string>
#include <set>
#include <vector>

using namespace std;

int main()
{
	int numberOfNames;
	cin >> numberOfNames;
	set<string> uniqueNames;
	vector<string> namesInOrder;
	
	while (numberOfNames-- > 0) {
		string name;
		cin >> name;
		if (uniqueNames.insert(name).second) {
			namesInOrder.push_back(name);
		}
	}
	
	for (const auto& name : namesInOrder) {
		cout << name << endl;
	}
	
	return 0;
}
