#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <utility>
#include <algorithm>
#include <string.h>
#include <math.h>

using namespace std;

int prices[3][1000];
int dp[3][1000];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int n;
	cin >> n;

	for (int x = 0; x < n; x++) {
		for (int y = 0; y < 3; y++) {
			cin >> prices[y][x];
		}

		if (x == 0) for (int y = 0; y < 3; y++) {
			dp[y][x] = prices[y][x];
		}
		else for (int y = 0; y < 3; y++) {
			dp[y][x] = min(
				dp[(y + 1) % 3][x - 1],
				dp[(y + 2) % 3][x - 1]
			) + prices[y][x];
		}
	}

	int minimum = dp[0][n - 1];
	minimum = min(minimum, dp[1][n - 1]);
	minimum = min(minimum, dp[2][n - 1]);

	cout << minimum;
}