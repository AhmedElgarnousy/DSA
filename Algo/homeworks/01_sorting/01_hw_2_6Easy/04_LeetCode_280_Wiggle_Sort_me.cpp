#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

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

void wiggleSort(vector<int> &nums)
{
    // ascending order
    sort(nums.begin(), nums.end(), cmp);

    vector<int> ans; // wiggle sort arr

    int first = 0, last = nums.size() - 1;
    while (first <= last)
    {
        ans.push_back(nums[first]);
        if (first != last)
            ans.push_back(nums[last]);
        first++;
        last--;
    }
    nums = ans;
}

int main()
{
    vector<int> v1{3, 5, 2, 1, 6, 4};
    print(v1);
    wiggleSort(v1);
    print(v1);
    return 0;
}