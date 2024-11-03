#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

bool cmp(int a, int b)
{
    return a < b;
}
int arrayPairSum(vector<int> &nums)
{
    // ascending order
    sort(nums.begin(), nums.end(), cmp);

    int sum_pair_mins = 0;
    for (int i = 0; i < (int)nums.size(); i += 2)
    {
        // sum_pair_mins += min(nums[i], nums[i + 1]); // you don't need to get the min so they sorted
        sum_pair_mins += nums[i];
    }
    return sum_pair_mins;
}
int main()
{
    vector<int> v1{1, 4, 3, 2};
    vector<int> v2{6, 2, 6, 5, 1, 2};

    cout << arrayPairSum(v1) << "\n"; // 4
    cout << arrayPairSum(v2) << "\n"; // 9

    return 0;
}