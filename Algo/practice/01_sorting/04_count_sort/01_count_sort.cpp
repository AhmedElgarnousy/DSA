#include <iostream>
#include <vector>
using namespace std;

void countSort(vector<int> &array)
{
    // Find the largest element of the array
    int size = array.size(), mxValue = array[0];
    for (int i = 1; i < size; ++i)
        if (array[i] > mxValue)
            mxValue = array[i];

    // Compute Frequency
    vector<int> count(mxValue + 1); // zeros
    for (int i = 0; i < size; ++i)
        count[array[i]] += 1;

    // Put the values back to the array
    int idx = 0;
    for (int i = 0; i <= mxValue; ++i)
    {
        for (int j = 0; j < count[i]; ++j, ++idx)
            array[idx] = i;
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
    // vector<int> v = read_vector();
    vector<int> v{5, 30, 333, 4, 10, 11, 10};
    countSort(v);

    for (int i = 0; i < (int)v.size(); ++i)
    {
        cout << v[i] << " ";
    }

    return 0;
}
