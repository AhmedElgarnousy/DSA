#include<iostream>
#include<vector>
#include<algorithm>
#include<climits>
#include<cmath>
using namespace std;

// Find value of X such that f(X) = 0
// It is guaranteed there is a solution for X in range [0, 3]

double f(double x) {
	return 4 * pow(x, 7) + 3 * pow(x, 5) - 1000;
}
double binary_search(double EPS = 1e-9) {
	double start = 0, end = 3;

	while (end - start > EPS) {
		double mid = start + (end - start) / 2;
		if (f(mid) < 0.0)
			start = mid;
		else
			end = mid;
	}
	return start;
}
int main() {

	for (double x = 0; x < 10; x += 0.5)
		cout << x << "\t" << f(x) << "\n";

	double x = binary_search();
	cout << x << " " << f(x) << "\n";
	// 2.15411 -1.29831e-06

	return 0;
}

