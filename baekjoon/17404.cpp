#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <utility>
#include <algorithm>
#include <string>
#include <vector>
#include <math.h>
#include <queue>
#include <stack>
#include <limits.h>

using namespace std;

int dp[1000][3];
int colors[1000][3];
int first;

int min(int a, int b, int c, int d) {
	return min(min(a, b), min(c, d));
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	const int R = 0, G = 1, B = 2;

	int n;
	cin >> n;

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < 3; j++) {
			cin >> colors[i][j];
		}
	}

	int minValue = INT_MAX;

	for (int k = 0; k < 3; k++) {
		first = k;
		dp[0][0] = dp[0][1] = dp[0][2] = colors[0][k];

		int i = 1;
		for (; i < n; i++) {
			dp[i][0] = colors[i][0] + min(dp[i - 1][1], dp[i - 1][2]);
			dp[i][1] = colors[i][1] + min(dp[i - 1][0], dp[i - 1][2]);
			dp[i][2] = colors[i][2] + min(dp[i - 1][0], dp[i - 1][1]);
		}

		dp[n - 1][first] = INT_MAX;

		minValue = min(minValue, dp[n-1][0], dp[n-1][1], dp[n-1][2]);
	}

	cout << minValue;
}