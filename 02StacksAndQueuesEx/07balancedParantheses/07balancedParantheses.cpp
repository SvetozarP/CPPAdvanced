#include <iostream>
#include <string>
#include <stack>

using namespace std;

int main()
{
    
    string parentheses;
    getline(cin, parentheses);

    stack<char> s;
    bool isBalanced = true;

    for (char ch : parentheses)
    {
        if (ch == '(' || ch == '{' || ch == '[')
        {
            s.push(ch);
        }
        else if (ch == ')' || ch == '}' || ch == ']')
        {
            if (s.empty())
            {
                isBalanced = false;
                break;
            }
            char topChar = s.top();
            s.pop();

            if ((ch == ')' && topChar != '(') ||
                (ch == '}' && topChar != '{') ||
                (ch == ']' && topChar != '['))
            {
                isBalanced = false;
                break;
            }
        }
    }

    if (!s.empty())
    {
        isBalanced = false;
    }

    if (isBalanced)
    {
        cout << "YES\n";
    }
    else
    {
        cout << "NO\n";
    }

    return 0;
}