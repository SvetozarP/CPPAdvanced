#include <iostream>

using namespace std;

char toLowerChar(char c) {
    if (c >= 'A' && c <= 'Z') {
        return c + ('a' - 'A');
    }
    return c;
}

char toUpperChar(char c) {
    if (c >= 'a' && c <= 'z') {
        return c - ('a' - 'A');
    }
    return c;
}

void toLowerCase(char* inputString, char* outputString) {
    char* currentInput = inputString;
    char* currentOutput = outputString;
    while (*currentInput != '\0') {
        *currentOutput = toLowerChar(*currentInput);
        currentInput++;
        currentOutput++;
    }
    *currentOutput = '\0';
}

void toUpperCase(char* inputString, char* outputString) {
    char* currentInput = inputString;
    char* currentOutput = outputString;
    while (*currentInput != '\0') {
        *currentOutput = toUpperChar(*currentInput);
        currentInput++;
        currentOutput++;
    }
    *currentOutput = '\0';
}

int main() {
    const int MAX_LENGTH = 1000;
    char inputString[MAX_LENGTH];
    cin.getline(inputString, MAX_LENGTH);

    char lowerCaseString[MAX_LENGTH];
    char upperCaseString[MAX_LENGTH];

    void (*lowerFunc)(char*, char*) = &toLowerCase;
    lowerFunc(inputString, lowerCaseString);

    void (*upperFunc)(char*, char*) = &toUpperCase;
    upperFunc(inputString, upperCaseString);

    cout << lowerCaseString << endl;
    cout << upperCaseString << endl;

    return 0;
}