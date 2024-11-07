#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int main()
{
    vector<int> v{4, 2, 3, 2, 9, 2, 17, 17, 17, 20};

    // Finds the first element >= a given value
    vector<int>::iterator it = lower_bound(v.begin(), v.end(), 17);

    if (it != v.end())
    {
        cout << "First element >= 17 " << *it << " \n";
        cout << "\tIndex: " << it - v.begin() << " \n";
    }

    // Finds the first element > a given value
    it = upper_bound(v.begin(), v.end(), 20); // it == v.end() == true

    auto p = equal_range(v.begin(), v.end(), 17);
    cout << p.first - v.begin() << " " << p.second - v.begin() << "\n";

    return 0;
}