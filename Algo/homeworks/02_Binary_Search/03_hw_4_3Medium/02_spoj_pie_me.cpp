#include <iostream>
#include <vector>
#include <algorithm>
#include <math.h>
#include <cmath>
// #include <cmath>

using namespace std;

#define pi 3.1416

double circle_area(double radius)
{
    return pi * (radius * radius);
}

bool possible(double pie_radius, int N = 8)
{
}

int binary_search(vector<double> &pies_radius, int N, int EPS = 1e-9)
{
    int left = 0, right = pies_radius.size();
    int ans = 0;
    while (fabs(left - right) > EPS)
    {
        int mid = left + (left - right) / 2;
        if (possible(mid))
            left = mid, ans = mid;
        else
            right = mid, ans = mid;
    }
    // return
}

int main()
{
    return 0;
}