#define _CRT_SECURE_NO_WARNINGS

#include <bits/stdc++.h>

using namespace std;

using uint_64 = unsigned long long;

// first dimension: length of numbers
// second dimension: last seen number
// third dimension: bit flags of numbers seen
uint_64 dp[101][10][1024];

uint_64 flags[] = {
	1 << 0,
	1 << 1,
	1 << 2,
	1 << 3,
	1 << 4,
	1 << 5,
	1 << 6,
	1 << 7,
	1 << 8,
	1 << 9
};

const uint_64 MOB_BY = 1000000000;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	int n;
	cin >> n;

	for (int i = 1; i <= 9; i++) {
		dp[1][i][flags[i]] = 1;
	}

	for (int i = 2; i <= n; i++) {
		for (int j = 0; j <= 9; j++) {
			for (int k = 0; k < 1024; k++) {
				// increasing (i.e. 456)
				if (j > 0) dp[i][j][k | flags[j]] += dp[i - 1][j - 1][k] % MOB_BY;
				// decreasing (i.e. 654)
				if (j < 9) dp[i][j][k | flags[j]] += dp[i - 1][j + 1][k] % MOB_BY;
			}
		}
	}

	uint_64 sum = 0;
	for (int i = 0; i <= 9; i++) {
		sum = (sum + dp[n][i][0b1111111111]) % MOB_BY;
	}

	cout << sum;
}