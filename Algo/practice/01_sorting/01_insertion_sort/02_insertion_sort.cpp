#include <iostream>
#include <vector>

using namespace std;

void insertion_sort(vector<int> &nums)
{
    // for each number: add it in the previous sorted subarray
    for (int i = 0; i < (int)nums.size(); i++)
    {
        int key = nums[i];
        int j = i - 1;
        // shift and add in the right location
        while (j >= 0 && nums[j] > key)
        {
            nums[j + 1] = nums[j];
            j--;
        }
        nums[j + 1] = key; // the first right element
    }
}
int main()
{
    vector<int> vec{9, 2, 10, 0, 5, 3, 90};
    insertion_sort(vec);
    for (auto &item : vec)
        cout << item << " ";
    cout << "\n";

    return 0;
}