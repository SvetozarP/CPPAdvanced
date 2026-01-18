#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <set>
#include <algorithm>
#include <cctype>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    string input_line;
    getline(cin, input_line);
    istringstream iss(input_line);

    set<string> short_words;
    string word;

    while (iss >> word)
    {
        transform(word.begin(), word.end(), word.begin(),
            [](unsigned char c) { return tolower(c); });

        if (word.length() < 5)
        {
            short_words.insert(word);
        }
    }

    bool first_word = true;
    for (const string& sw : short_words)
    {
        if (!first_word)
        {
            cout << ", ";
        }
        cout << sw;
        first_word = false;
    }
    cout << '\n';

    return 0;
}