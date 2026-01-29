#include <iostream>
#include <string>

using namespace std;

bool parseInt(char const* str, int& outValue) {

	outValue = 0;
	while (*str) {
		char currentChar = *str;
		if (currentChar >= '0' && currentChar <= '9') {
			outValue *= 10;
			outValue += (currentChar - '0');
		}
		else {
			return false;
		}

		str++;
	}
	return true;
}

int main()
{
	string a, b;
	cin >> a >> b;

	int valueA, valueB;
	bool okA = parseInt(a.c_str(), valueA);
	bool okB = parseInt(b.c_str(), valueB);

	if (okA && okB) {
		cout << (valueA + valueB) << endl;
	}
	else {
		if (!okA)
			cout << "[error] ";
		cout << a << endl;
		 
		if (!okB) 
			cout << "[error]";
		cout << b << endl;
		
	}

	return 0;
}
