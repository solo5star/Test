#define _CRT_SECURE_NO_WARNINGS

#include <bits/stdc++.h>

using namespace std;

// dp[n][0] => End with 0
// dp[n][1] => End with 1
unsigned long long dp[91][2] = {
	{0, 0},
	{0, 1},
	{1, 0},
	{1, 1},
	{2, 1}
};

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	int n;
	cin >> n;

	for (int i = 5; i <= n; i++) {
		dp[i][0] = dp[i - 1][0] + dp[i - 1][1];
		dp[i][1] = dp[i - 1][0];
	}

	cout << dp[n][0] + dp[n][1];
}