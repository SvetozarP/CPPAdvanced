#include <iostream>
#include <queue>
#include <string>

using namespace std;

int main()
{
    queue<string> allInputs;
    string inputLine;

    while (getline(cin, inputLine) && inputLine != "End") {
        allInputs.push(inputLine);
    }

    queue<string> customersToServe;

    while (!allInputs.empty()) {
        string currentEntry = allInputs.front();
        allInputs.pop();

        if (currentEntry == "Paid") {
            while (!customersToServe.empty()) {
                cout << customersToServe.front() << endl;
                customersToServe.pop();
            }
            cout << allInputs.size() << " people remaining." << endl;
			return 0;
        }
        else {
            customersToServe.push(currentEntry);
        }
    }

    if (!customersToServe.empty()) {
        cout << customersToServe.size() << " people remaining." << endl;
    }

    return 0;
}