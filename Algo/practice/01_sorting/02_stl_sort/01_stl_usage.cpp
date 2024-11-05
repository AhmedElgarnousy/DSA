#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

bool compare_right(int a, int b)
{
    return a < b;
}

bool compare_wrong(int a, int b)
{
    return a <= b;
}

int main()
{

    // 10^7 elements of value 5
    vector<int> v(10000000, 5);
    // It will take much time, then RTE!
    sort(v.begin(), v.end(), compare_wrong);
    // It takes resonable time with compare_right
    // sort(v.begin(), v.end(), compare_right);
    cout << "bye\n"
         << flush; // 90% won't be printed

    return 0;
}