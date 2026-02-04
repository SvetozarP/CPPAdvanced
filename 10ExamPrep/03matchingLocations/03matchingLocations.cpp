#include <iostream>
#include <string>
#include <vector>
#include <sstream>
#include <map>
#include <utility>

using namespace std;

int main() {
    vector<pair<string, pair<double, double>>> locationsData;
    map<string, string> locationsByName;
    map<pair<double, double>, vector<string>> locationsByCoords;

    string line;
    while (getline(cin, line) && line != ".") {
        stringstream ss(line);
        string name_part;
        string lat_str, lon_str;
        string full_name;

        getline(ss, full_name, ',');
        getline(ss, lat_str, ',');
        getline(ss, lon_str);

        double latitude = stod(lat_str);
        double longitude = stod(lon_str);

        string original_full_line = full_name + "," + lat_str + "," + lon_str;

        locationsData.push_back({ original_full_line, {latitude, longitude} });
        locationsByName[full_name] = original_full_line;
        locationsByCoords[{latitude, longitude}].push_back(original_full_line);
    }

    while (getline(cin, line) && line != ".") {
        stringstream ss(line);
        double lat_query, lon_query;

        if (ss >> lat_query >> lon_query) {
            pair<double, double> query_coords = { lat_query, lon_query };
            if (locationsByCoords.count(query_coords)) {
                for (const string& original_line : locationsByCoords[query_coords]) {
                    cout << original_line << endl;
                }
            }
        }
        else {
            string queryName = line;
            if (locationsByName.count(queryName)) {
                cout << locationsByName[queryName] << endl;
            }
        }
    }

    return 0;
}