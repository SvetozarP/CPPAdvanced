#include <iostream>
#include <vector>
#include <string>
#include <sstream>
#include <algorithm>

using namespace std;

void filterAndReverse(vector<int>* numbers_ptr) {
    vector<int>& numbers = *numbers_ptr;

    numbers.erase(remove_if(numbers.begin(), numbers.end(), [](int n) { return n < 0; }), numbers.end());

    reverse(numbers.begin(), numbers.end());
}

void printNumbers(const vector<int>& numbers) {
    if (numbers.empty()) {
        cout << "empty" << endl;
    }
    else {
        for (size_t i = 0; i < numbers.size(); ++i) {
            cout << numbers[i] << (i == numbers.size() - 1 ? "" : " ");
        }
        cout << endl;
    }
}

int main() {
    string line;
    getline(cin, line);

    stringstream ss(line);
    int num;
    vector<int> numbers;
    while (ss >> num) {
        numbers.push_back(num);
    }

    void (*filter_func)(vector<int>*) = &filterAndReverse;
    filter_func(&numbers);

    void (*print_func)(const vector<int>&) = &printNumbers;
    print_func(numbers);

    return 0;
}