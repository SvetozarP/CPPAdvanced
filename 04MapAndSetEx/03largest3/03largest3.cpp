#include <iostream>
#include <sstream>
#include <vector>
#include <algorithm> 
#include <functional>

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

    sort(numbers.begin(), numbers.end(), std::greater<double>());

    int count_to_print = min(3, static_cast<int>(numbers.size()));

    bool first = true;
    for (int i = 0; i < count_to_print; ++i)
    {
        if (!first)
        {
            cout << " ";
        }
        cout << numbers[i];
        first = false;
    }
    cout << '\n';

    return 0;
}