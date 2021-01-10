#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <utility>
#include <algorithm>
#include <string>
#include <vector>
#include <math.h>

using namespace std;

// 2d index:
//   - 0: PREVIOUS
//   - 1: CURRENT
const int PREVIOUS = 0;
const int CURRENT = 1;

int maximum[2][3];
int minimum[2][3];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int n, a, b, c;
	cin >> n;

	for (int i = 0; i < n; i++) {
		cin >> a >> b >> c;

		maximum[CURRENT][0] = a + max(maximum[PREVIOUS][0], maximum[PREVIOUS][1]);
		maximum[CURRENT][1] = b + max(max(maximum[PREVIOUS][0], maximum[PREVIOUS][1]), maximum[PREVIOUS][2]);
		maximum[CURRENT][2] = c + max(maximum[PREVIOUS][1], maximum[PREVIOUS][2]);

		minimum[CURRENT][0] = a + min(minimum[PREVIOUS][0], minimum[PREVIOUS][1]);
		minimum[CURRENT][1] = b + min(min(minimum[PREVIOUS][0], minimum[PREVIOUS][1]), minimum[PREVIOUS][2]);
		minimum[CURRENT][2] = c + min(minimum[PREVIOUS][1], minimum[PREVIOUS][2]);

		for (int i = 0; i < 3; i++) {
			maximum[PREVIOUS][i] = maximum[CURRENT][i];
			minimum[PREVIOUS][i] = minimum[CURRENT][i];
		}
	}

	cout
		<< max(max(maximum[CURRENT][0], maximum[CURRENT][1]), maximum[CURRENT][2])
		<< " "
		<< min(min(minimum[CURRENT][0], minimum[CURRENT][1]), minimum[CURRENT][2]);
}