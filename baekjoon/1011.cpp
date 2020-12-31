#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <utility>
#include <algorithm>
#include <math.h>

using namespace std;

long sol(long diff) {
	int acc = 0;
	while (diff > 3) {
		acc += (diff % 2) + 2;
		diff = (diff - 2) / 2;
	}
	acc += diff;
	return acc;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int t;
	long x, y, diff;

	cin >> t;

	for (int i = 0; i < t; i++) {
		cin >> x >> y;

		diff = y - x;
		cout << sol(diff) << "\n";
	}
}