#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
/*
// try recursize solution
bool binary_search(int val, vector<int> &arr)
{
    static int cur_size = arr.size();
    static int midIdx = cur_size / 2;

    if (val == arr[midIdx])
        return 1;

    // because arr is sorted
    if (val < arr[0] || val > arr[arr.size() - 1])
        return 0;

    if (cur_size == 0)
        return val == arr[0] || val == arr[arr.size() - 1];

    if (cur_size % 2 == 0)
    {
        cur_size /= 2;
        // cur_size--;
    }
    else
    {
        cur_size /= 2;
        cur_size++;
    }

    if (val > arr[midIdx])
    {
        midIdx += cur_size;
    }
    else if (val < arr[midIdx])
    {
        midIdx -= cur_size; // search the next half of the arr
    }

    return binary_search(val, arr);
}
*/

// return index if not exist return -1
int binary_search(int val, vector<int> &arr)
{
    int start = 0, end = arr.size() - 1;
    while (start <= end)
    {
        int mid = (start + end) / 2;

        if (val == arr[mid])
            return mid;

        if (val > arr[mid])
            start = mid + 1;
        else if (val < arr[mid])
            end = mid - 1;
    }
    return -1;
}

int main()
{
    vector<int> v1{2, 4, 6, 8, 10, 12};
    cout << binary_search(11, v1) << "\n";
    cout << binary_search(2, v1) << "\n";
    cout << binary_search(10, v1) << "\n";
    cout << binary_search(12, v1) << "\n";

    return 0;
}