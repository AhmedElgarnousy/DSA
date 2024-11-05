#include <iostream>
#include <vector>
using namespace std;

void selection_sort(vector<int> &nums)
{
    int n = nums.size();

    for (int i = 0; i < n - 1; i++)
    {
        // Find the minimum element in unsorted array
        int mn_idx = i;
        for (int j = i + 1; j < n; j++)
            if (nums[j] < nums[mn_idx])
                mn_idx = j;

        // Put the min in its right place
        swap(nums[mn_idx], nums[i]);
    }
}

vector<int> read_vector()
{
    int n;
    cin >> n;

    vector<int> v(n);
    for (int i = 0; i < n; ++i)
        cin >> v[i];

    return v;
}

int main()
{
    vector<int> v = read_vector();
    selection_sort(v);

    for (int i = 0; i < (int)v.size(); ++i)
    {
        cout << v[i] << " ";
    }

    return 0;
}
