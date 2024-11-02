#include<iostream>
#include<vector>
#include<algorithm>
#include<climits>
#include<cmath>
using namespace std;

double f(double x) {
	return 4 * pow(x, 7) + 3 * pow(x, 5) - 1000;
}

// This code is NOT better than the previous code
// Just showing the other choices
double binary_search(double EPS = 1e-9) {
	double start = EPS, end = 3;
	//while (fabs(end - start) > EPS) {			// 2nd way
	for(int iter = 0;iter < 100; ++iter) {		// 3rd way
		double mid = sqrt(start * end);
		if (f(mid) < 0.0)
			start = mid;
		else
			end = mid;
	}
	return (start + end) / 2.0;
}

int main() {
	double x = binary_search();
	cout << x << " " << f(x) << "\n";
	// 2.15411 -1.29831e-06

	return 0;
}

