#include <iostream>
#include <vector>
#include <string>
#include <utility> // For std::pair

using namespace std;

void processCompany(vector<pair<string, int>>* companies, const string& name, int id) {
    if (id >= 0) {
        companies->push_back(make_pair(name, id));
    }
}

void printCompanies(const vector<pair<string, int>>& companies) {
    for (const auto& pair : companies) {
        cout << pair.second << " " << pair.first << endl;
    }
}

int main() {
    vector<pair<string, int>> validCompanies;
    string name;
    int id;
    string command;

    while (true) {
        cin >> command;
        if (command == "end") {
            break;
        }
        id = stoi(command);
        cin >> name;

        void (*processor)(vector<pair<string, int>>*, const string&, int) = &processCompany;
        processor(&validCompanies, name, id);
    }

    void (*printer)(const vector<pair<string, int>>&) = &printCompanies;
    printer(validCompanies);

    return 0;
}