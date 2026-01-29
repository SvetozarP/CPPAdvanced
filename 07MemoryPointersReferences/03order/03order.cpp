#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <cstring>

using namespace std;

#ifdef _MSC_VER
#define STRCPY(dest, size, src) strcpy_s(dest, size, src)
#else
#define STRCPY(dest, size, src) strncpy(dest, src, size); (dest)[(size)-1] = '\0';
#endif

bool compVector(const pair<int*, const char*>& a, const pair<int*, const char*>& b) {
	return (*a.first) < (*b.first);
}

int main() {
	{
		char buffer[1000] = {};
		int* nextInt = (int*)buffer;
		char* nextName = (char*)(nextInt + 1);

		vector<pair<int*, const char*>> entries;

		while (true) {
			string currentName;
			cin >> currentName;
			if (currentName == "end") {
				break;
			}
			int currentValue;
			cin >> currentValue;

			if ((char*)(nextName + currentName.size() + 1) > (char*)(buffer + sizeof(buffer))) {
				cerr << "Error: Buffer overflow prevented. String '" << currentName << "' is too long." << endl;
				continue;
			}

			*nextInt = currentValue;
			STRCPY(nextName, sizeof(buffer) - (nextName - buffer), currentName.c_str());
			entries.push_back(pair<int*, const char*>(nextInt, nextName));
			nextInt = (int*)((char*)nextInt + sizeof(int) + currentName.length() + 1);
			nextName = (char*)(nextInt + 1);
		}

		sort(entries.begin(), entries.end(), compVector);

		for (const pair<int*, const char*>& entry : entries) {
			cout << entry.second << ' ' << *entry.first << endl;
		}

		return 0;
	}
}
