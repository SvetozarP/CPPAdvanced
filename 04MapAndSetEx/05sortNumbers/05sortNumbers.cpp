#include <iostream>
#include <sstream>
#include <vector>
#include <algorithm>
#include <string>

using namespace std;

int main()
{

    string input_line;
    getline(cin, input_line);
    istringstream iss(input_line);

    vector<double> numbers;
    double number;

    while (iss >> number)
    {
        numbers.push_back(number);
    }

    sort(numbers.begin(), numbers.end());

    bool first_number = true;
    for (double num : numbers)
    {
        if (!first_number)
        {
            cout << " <= ";
        }
        cout << num;
        first_number = false;
    }
    cout << '\n';

    return 0;
}