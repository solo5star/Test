#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <utility>
#include <algorithm>
#include <math.h>
#include <unordered_set>

using namespace std;

int dp[12] = { 0, 1, 2, 4, 7 };

int solve(int n) {
	if (n <= 4) return dp[n];

	for (int i = 5; i <= n; i++) {
		if (dp[i]) continue;
		
		dp[i] = dp[i - 3] + dp[i - 2] + dp[i - 1];
	}
	return dp[n];
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int t, n;
	cin >> t;

	for (int i = 0; i < t; i++) {
		cin >> n;

		cout << solve(n) << "\n";
	}
}