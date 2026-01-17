#include <iostream>
#include <string>
#include <set>

using namespace std;

int main()
{

	set<string> parkingLot;
    while (true) {

		string command;
		cin >> command;

        if (command == "END") {
            break;
		}
        
        string numberplate;
		cin >> numberplate;

        if (command == "IN,") {
            parkingLot.insert(numberplate);
        }
        else {
            parkingLot.erase(numberplate);
        }
    }

    if (parkingLot.empty()) {
        cout << "Parking Lot is Empty" << endl;
    }
    else {
        for (const auto& plate : parkingLot) {
            cout << plate << endl;
        }
	}
}
