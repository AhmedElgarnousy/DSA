#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// brute force
int arrange_coins(int n)
{
    int com = -1;
    int step = 1;
    while (n >= 0)
    {
        n -= step;
        com++;
        step++;
    }
    return com;
}
int main()
{

    cout << arrange_coins(15) << "\n";
    cout << arrange_coins(16) << "\n";
    cout << arrange_coins(12) << "\n";

    return 0;
}