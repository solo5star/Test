#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <utility>
#include <algorithm>
#include <math.h>

using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int t;
	long x, y, diff, diff_sqrt;

	cin >> t;

	for (int i = 0; i < t; i++) {
		cin >> x >> y;

		diff = y - x;
		diff_sqrt = sqrt(diff);

		if (diff < 4) {
			cout << diff;
		}
		else if (diff == diff_sqrt * diff_sqrt) {
			cout << 2 * diff_sqrt - 1;
		}
		else if (diff <= diff_sqrt * diff_sqrt + diff_sqrt) {
			cout << 2 * diff_sqrt;
		}
		else {
			cout << 2 * diff_sqrt + 1;
		}

		cout << "\n";
	}
}