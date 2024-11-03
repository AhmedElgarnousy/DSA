#include <iostream>
#include <algorithm>
#include <vector>
#include <climits>

using namespace std;

// utilites
bool cmp(int a, int b)
{
    return a < b;
}
void print(vector<int> nums)
{
    for (auto &item : nums)
        cout << item << " ";
    cout << "\n";
}
void print(vector<vector<int>> res)
{
    for (int row = 0; row < res.size(); row++)
    {
        for (int col = 0; col < res[row].size(); col++)
            cout << res[row][col] << " ";
        cout << "\n";
    }
}

vector<vector<int>> minimumAbsDifference(vector<int> &nums)
{
    vector<vector<int>> res;
    int minAbsDiff = INT_MAX;

    // sort given array
    sort(nums.begin(), nums.end(), cmp);

    // get min abs diff
    for (int i = 0; i < (int)nums.size(); i++)
    {
        minAbsDiff = min(minAbsDiff, abs(nums[i + 1] - nums[i]));
        // if (minAbsDiff > abs(nums[i + 1] - nums[i]))
        // minAbsDiff = nums[i + 1] - nums[i];
    }

    for (int i = 0; i < nums.size(); i++)
    {
        if (minAbsDiff == abs(nums[i] - nums[i + 1]))
            res.push_back({nums[i], nums[i + 1]});
    }

    return res;
}

int main()
{
    vector<int> v1{4, 2, 1, 3};
    vector<int> v2{1, 3, 6, 10, 15};
    vector<int> v3{3, 8, -10, 23, 19, -4, -14, 27};

    print(minimumAbsDifference(v1));
    std::cout << "\n";
    print(minimumAbsDifference(v2));
    std::cout << "\n";
    print(minimumAbsDifference(v3));
    std::cout << "\n";

    // print(v1);
    // print(v2);
    // print(v3);
    return 0;
}