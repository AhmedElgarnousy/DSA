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
void selection_sort(int *arr, int sz)
{
    int smIdx = 0; // small idx
    for (int i = 0; i < sz - 1; i++)
    {
        smIdx = i;
        for (int j = i; j < sz; j++)
        {
            // search for smallest number
            if (arr[smIdx] > arr[j + 1])
                smIdx = j + 1;
        }
        if (smIdx != i)
            std::swap(arr[smIdx], arr[i]);
    }
}
int main()
{
    const int sz = 7;
    int arr[sz]{9, 2, 10, 0, 5, 13, 90};

    print(arr, sz);

    // selection sort
    selection_sort(arr, sz);

    print(arr, sz);
    return 0;
}