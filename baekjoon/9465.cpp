#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <utility>
#include <algorithm>
#include <string.h>
#include <math.h>

using namespace std;

int scores[2][100000];
int dp[2][100000];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int t, n, maximum = 0;
	cin >> t;

	while (t--) {
		cin >> n;

		for (int y = 0; y < 2; y++) {
			for (int x = 0; x < n; x++) {
				cin >> scores[y][x];
			}
		}

		for (int x = 0; x < n; x++) {
			for (int y = 0; y < 2; y++) {
				dp[y][x] = scores[y][x];

				if (x >= 1) dp[y][x] = max(dp[y][x], scores[y][x] + dp[(y + 1) % 2][x - 1]);
				if (x >= 2) dp[y][x] = max(dp[y][x], scores[y][x] + dp[(y + 1) % 2][x - 2]);

				maximum = max(maximum, dp[y][x]);
			}
		}

		cout << maximum << "\n";
	}
}