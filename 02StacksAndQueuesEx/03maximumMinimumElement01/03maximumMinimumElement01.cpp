#include <iostream>
#include <sstream>
#include <stack>
#include <string>
#include <algorithm> 

using namespace std;

int main()
{
    int commandsCount;
    cin >> commandsCount;
    cin.ignore(); 

    stack<int> numbers;
    stack<int> max_stack;
    stack<int> min_stack;

    while (commandsCount--) {
        string command;
        getline(cin, command);
        istringstream iss(command);

        char operation;
        int value;
        iss >> operation;

        switch (operation) {
        case '1': // Push
            iss >> value;
            numbers.push(value);
            // Update max_stack
            if (max_stack.empty() || value >= max_stack.top()) {
                max_stack.push(value);
            }
            // Update min_stack
            if (min_stack.empty() || value <= min_stack.top()) {
                min_stack.push(value);
            }
            break;
        case '2': // Pop
            if (!numbers.empty()) {
                // If the element being popped is the current max, pop from max_stack as well
                if (numbers.top() == max_stack.top()) {
                    max_stack.pop();
                }
                // If the element being popped is the current min, pop from min_stack as well
                if (numbers.top() == min_stack.top()) {
                    min_stack.pop();
                }
                numbers.pop();
            }
            break;
        case '3': // Print max
            if (!max_stack.empty()) {
                cout << max_stack.top() << "\n"; // Use "\n" instead of endl for performance
            }
            break;
        case '4': // Print min
            if (!min_stack.empty()) {
                cout << min_stack.top() << "\n"; // Use "\n" instead of endl for performance
            }
            break;
        default:
            break;
        }
    }

    if (!numbers.empty()) {
        stack<int> tempStack = numbers;
        string output;
        while (!tempStack.empty()) {
            output += to_string(tempStack.top());
            tempStack.pop();
            if (!tempStack.empty()) {
                output += ", ";
            }
        }
        cout << output << endl;
    }

    return 0;
}