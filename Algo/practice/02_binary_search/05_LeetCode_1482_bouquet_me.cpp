#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

bool possible(vector<int> &bloomday, int m, int k, int ith_day)
{
    int req_flowers = m * k;
    int cur_flowers = 0;
    vector<int> flows_of_day;
    for (int day = 1; day <= ith_day; day++)
    {
        for (int i = 0; i < bloomday.size(); i++)
        {
            if (bloomday[i] <= day)
                cur_flowers++;
        }
        flows_of_day.push_back(cur_flowers);
    }
    for (auto flower : flows_of_day)
        cout << flower << " ";
    cout << "\n";
    return cur_flowers >= req_flowers;
}

int main()
{
    vector<int> bloomDay{1, 10, 3, 10, 2};
    int day = 3;
    int m = 3;
    int k = 1;

    cout << possible(bloomDay, m, k, day) << "\n";

    return 0;
}