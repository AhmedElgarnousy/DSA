#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

void selection_sort(vector<int> &nums)
{
    for (int i = 0; i < nums.size() - 1; i++)
    {
        int minIdx = i + 1;
        // find the min elemennt in unsorted array
        for (int j = i; j <= nums.size() - 1; j++)
        {
            if (nums[j] < nums[minIdx])
                minIdx = j;
        }

        // put the min its right place
        // if (nums[i] > nums[minIdx])
        swap(nums[i], nums[minIdx]);
    }
}

int main()
{
    vector<int> arr{9, 85, 10, 0, 5, 3, 90, 2};

    selection_sort(arr);

    for (int item : arr)
        cout << item << " ";
    cout << "\n";

    return 0;
}