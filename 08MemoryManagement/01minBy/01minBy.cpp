#include <iostream>
#include <string>
#include <vector>
#include <sstream>
#include <algorithm> // For std::min_element and std::max_element

using namespace std;

vector<string*>* splitIntoWords(const string& inputLine) {
    vector<string*>* words = new vector<string*>();
    stringstream ss(inputLine);
    string tempWord;

    while (ss >> tempWord) {
        words->push_back(new string(tempWord));
    }
    return words;
}

const string* findEarliestLexicographically(const vector<string*>& wordsRef) {
    if (wordsRef.empty()) {
        return nullptr;
    }

    const string* earliest = wordsRef[0];
    for (size_t i = 1; i < wordsRef.size(); ++i) {
        if (*(wordsRef[i]) < *earliest) {
            earliest = wordsRef[i];
        }
    }
    return earliest;
}

const string* findShortestString(const vector<string*>& wordsRef) {
    if (wordsRef.empty()) {
        return nullptr;
    }

    const string* shortest = wordsRef[0];
    for (size_t i = 1; i < wordsRef.size(); ++i) {
        if (wordsRef[i]->length() < shortest->length()) {
            shortest = wordsRef[i];
        }
    }
    return shortest;
}

const string* findLongestString(const vector<string*>& wordsRef) {
    if (wordsRef.empty()) {
        return nullptr;
    }

    const string* longest = wordsRef[0];
    for (size_t i = 1; i < wordsRef.size(); ++i) {
        if (wordsRef[i]->length() > longest->length()) {
            longest = wordsRef[i];
        }
    }
    return longest;
}

void cleanup(vector<string*>* wordsPtr) {
    if (wordsPtr != nullptr) {
        for (string* s_ptr : *wordsPtr) {
            delete s_ptr;
        }
        delete wordsPtr;
    }
}


int main() {
    string inputLine;
    getline(cin, inputLine);

    int choice;
    cin >> choice;

    vector<string*>* words = splitIntoWords(inputLine);

    if (words->empty()) {
        cout << "" << endl;
        cleanup(words);
        return 0;
    }

    const string* resultStringPtr = nullptr;

    switch (choice) {
    case 1: {
        resultStringPtr = findEarliestLexicographically(*words);
        break;
    }
    case 2: {
        resultStringPtr = findShortestString(*words);
        break;
    }
    case 3: {
        resultStringPtr = findLongestString(*words);
        break;
    }
    default: {
        cout << "Invalid choice." << endl;
        break;
    }
    }

    if (resultStringPtr != nullptr) {
        cout << *resultStringPtr << endl;
    }

    cleanup(words);

    return 0;
}