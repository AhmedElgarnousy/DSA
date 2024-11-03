#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>

using namespace std;

bool cmp(int a, int b)
{
    return a < b;
}

int largestPerimeter(vector<int> &arr)
{
    // sorted from small to large
    sort(arr.begin(), arr.end(), cmp);
    int idx = arr.size() - 1;

    // search for a valid rectangle
    if (idx == 2)
    {
        if (arr[idx] < arr[idx - 1] + arr[idx - 2])
            return arr[idx] + arr[idx - 1] + arr[idx - 2];
    }

    while (idx >= 2)
    {
        // large side < smaller sides
        if (arr[idx] < arr[idx - 1] + arr[idx - 2])
            return arr[idx] + arr[idx - 1] + arr[idx - 2]; // return largest perimeter
        else
            idx--; // shift for previous triangle sides
    }
    return 0; // non zero area triangle
}
int main()
{
    vector<int> v1{2, 1, 2};
    vector<int> v2{1, 2, 1};
    vector<int> v3{3, 2, 3, 4};
    vector<int> v4{3, 6, 2, 3};

    cout << largestPerimeter(v1) << "\n"; // 5
    cout << largestPerimeter(v2) << "\n"; // 0
    cout << largestPerimeter(v3) << "\n"; // 10
    cout << largestPerimeter(v4) << "\n"; // 8

    return 0;
}