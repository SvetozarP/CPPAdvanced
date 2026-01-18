#include <iostream>
#include <sstream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <string>

using namespace std;

int main()
{
    string input_line;
    getline(cin, input_line);
    istringstream iss(input_line);

    vector<int> square_numbers;
    int number;

    while (iss >> number)
    {
        int root = static_cast<int>(sqrt(number));
        if (root * root == number)
        {
            square_numbers.push_back(number);
        }
    }

    sort(square_numbers.begin(), square_numbers.end(), greater<int>());

    bool first_number = true;
    for (int sq_num : square_numbers)
    {
        if (!first_number)
        {
            cout << " ";
        }
        cout << sq_num;
        first_number = false;
    }
    cout << '\n';

    return 0;
}