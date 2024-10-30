#include <iostream>

// using namespace std;
void print(int *arr, int sz)
{
    for (int i = 0; i < sz; i++)
    {
        std::cout << arr[i] << " ";
    }
    std::cout << "\n";
}
void count_sort(int *arr, int sz)
{
    // find the max
    int mxValue = 0;
    for (int i = 0; i < sz; i++)
        if (mxValue < arr[i])
            mxValue = arr[i];

    // freq array of max array value created with zero values
    int freqArr[mxValue + 1]{0};
    for (int i = 0; i < sz; i++)
        freqArr[arr[i]] += 1;

    // set the sorted array

    int idx = 0;
    for (int i = 0; i <= mxValue; ++i)
    {
        for (int j = 0; j < freqArr[i]; ++j, ++idx)
        {
            arr[idx] = i;
        }
    }
}
int main()
{
    const int sz = 7;
    int arr[sz]{2, 5, 2, 0, 1, 2, 2};

    print(arr, sz);

    // count sort
    count_sort(arr, sz);

    print(arr, sz);
    return 0;
}