#include <iostream>
#include <string>
#include <map>
#include <cstring>

using namespace std;

#ifdef _MSC_VER
#define STRCPY(dest, size, src) strcpy_s(dest, size, src)
#else
#define STRCPY(dest, size, src) strncpy(dest, src, size); (dest)[(size)-1] = '\0';
#endif

int main() {
    char buffer[1000];
    char* nextString = buffer;
    size_t remainingBufferSize = sizeof(buffer);

    map<int, const char*> index;

    while (true) {
        string currentName;
        cin >> currentName;

        if (currentName == "end") {
            break;
        }

        int currentIndex;
        cin >> currentIndex;

        
        if (currentName.size() + 1 > remainingBufferSize) {
            cerr << "Error: Buffer overflow prevented. String '" << currentName << "' is too long." << endl;
            continue;
        }

        STRCPY(nextString, remainingBufferSize, currentName.c_str());

        index[currentIndex] = nextString;

        size_t bytesWritten = currentName.size() + 1;
        nextString += bytesWritten;
        remainingBufferSize -= bytesWritten;
    }

    int searchId;
    cin >> searchId;

    auto it = index.find(searchId);
    if (it == index.end()) {
        cout << "[not found]" << endl;
    }
    else {
        cout << it->second << ' ' << it->first << endl;
    }

    return 0;
}