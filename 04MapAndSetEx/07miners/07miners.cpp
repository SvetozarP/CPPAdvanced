#include <iostream>
#include <string>
#include <map>
#include <vector>

using namespace std;

int main()
{
    map<string, int> resource_quantities;
    vector<string> resource_order;

    string resource_name;
    string quantity_str;

    while (getline(cin, resource_name) && resource_name != "stop")
    {
        getline(cin, quantity_str);
        int quantity = stoi(quantity_str);

        if (resource_quantities.find(resource_name) == resource_quantities.end())
        {
            resource_order.push_back(resource_name);
        }

        resource_quantities[resource_name] += quantity;
    }

    for (const string& name : resource_order)
    {
        cout << name << " -> " << resource_quantities[name] << '\n';
    }

    return 0;
}