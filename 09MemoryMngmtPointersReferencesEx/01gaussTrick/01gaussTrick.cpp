#include <iostream>
#include <vector>
#include <string>
#include <sstream>
#include <numeric>

using namespace std;

void sumPairs(const vector<int>* numbers_ptr, vector<int>* sums_ptr) {
    const vector<int>& numbers = *numbers_ptr;
    vector<int>& sums = *sums_ptr;

    int* left_ptr = new int(0);
    int* right_ptr = new int(numbers.size() - 1);

    while (*left_ptr <= *right_ptr) {
        if (*left_ptr == *right_ptr) {
            sums.push_back(numbers[*left_ptr]);
        }
        else {
            sums.push_back(numbers[*left_ptr] + numbers[*right_ptr]);
        }
        (*left_ptr)++;
        (*right_ptr)--;
    }

    delete left_ptr;
    delete right_ptr;
}

void printSums(const vector<int>& sums) {
    for (size_t i = 0; i < sums.size(); ++i) {
        cout << sums[i] << (i == sums.size() - 1 ? "" : " ");
    }
    cout << endl;
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

    vector<int> sums;

    void (*calculator)(const vector<int>*, vector<int>*) = &sumPairs;
    calculator(&numbers, &sums);

    void (*printer)(const vector<int>&) = &printSums;
    printer(sums);

    return 0;
}