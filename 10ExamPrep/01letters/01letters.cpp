#include <iostream>
#include <string>
#include <set>
#include <algorithm>
#include <cctype>
#include <vector>

using namespace std;

int main() {
    string text;
    getline(cin, text);

    vector<string> allWords;
    string currentWord;
    for (char c : text) {
        if (isalpha(c)) {
            currentWord += c;
        }
        else {
            if (!currentWord.empty()) {
                allWords.push_back(currentWord);
                currentWord.clear();
            }
        }
    }
    if (!currentWord.empty()) {
        allWords.push_back(currentWord);
    }

    string line;
    while (getline(cin, line) && line != ".") {
        char targetLetter = tolower(line[0]);
        set<string> resultWords;

        for (const string& word : allWords) {
            bool found = false;
            for (char c : word) {
                if (tolower(c) == targetLetter) {
                    found = true;
                    break;
                }
            }
            if (found) {
                resultWords.insert(word);
            }
        }

        if (resultWords.empty()) {
            cout << "---" << endl;
        }
        else {
            bool first = true;
            for (const string& word : resultWords) {
                if (!first) {
                    cout << " ";
                }
                cout << word;
                first = false;
            }
            cout << endl;
        }
    }

    return 0;
}