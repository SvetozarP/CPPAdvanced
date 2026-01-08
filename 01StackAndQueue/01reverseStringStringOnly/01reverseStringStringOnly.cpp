#include <iostream>
#include <string>
#include <sstream>

using namespace std;

int main()
{
	string input;
	getline(cin, input);

	string::reverse_iterator rit = input.rbegin();
	for (; rit != input.rend(); ++rit)
	{
		cout << *rit;
	}
	cout << endl;
	return 0;
}
