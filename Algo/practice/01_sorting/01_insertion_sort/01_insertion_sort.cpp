#include <iostream>

// using namespace std;

void swap_ptr(int *num1, int *num2)
{
    int swapEle = *num1;
    *num1 = *num2;
    *num2 = swapEle;
}
void swap_ref(int &num1, int &num2)
{
    int swapEle = num1;
    num1 = num2;
    num2 = swapEle;
}
void swap_cpy(int num1, int num2)
{
    int swapEle = num1;
    num1 = num2;
    num2 = swapEle;
}

void insertion_sort(int arr[], int sz)
{
    int swapEle;
    // insertion
    for (int i = 0; i < sz - 1; i++)
    {
        for (int j = i; j >= 0; j--)
        {
            if (arr[j] > arr[j + 1])
            {
                // swap_ptr(&arr[j], &arr[j + 1]);
                swap_ref(arr[j], arr[j + 1]);
                // std::swap(arr[j], arr[j + 1]);
            }
            else
            {
                break; // or make j = -1;
            }
        }
    }
}

void print(int *arr, int sz)
{
    for (int i = 0; i < sz; i++)
    {
        std::cout << arr[i] << " ";
    }
    std::cout << "\n";
}
int main()
{
    const int sz = 7;
    int arr[sz]{9, 2, 10, 0, 5, 3, 90};

    // print arr in
    print(arr, sz);

    insertion_sort(arr, sz);

    // print arr out
    print(arr, sz);

    return 0;
}
