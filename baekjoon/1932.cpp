#define _CRT_SECURE_NO_WARNINGS

#include <bits/stdc++.h>

using namespace std;

int dp[500][500];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	int n;
	cin >> n;

	int num;
	int maxValue = 0;

	for (int i = 0; i < n; i++) {
		for (int j = 0; j <= i; j++) {
			cin >> num;

			if (i == 0) {
				dp[i][j] = num;
			}
			else if (j == 0) {
				dp[i][j] = dp[i - 1][j] + num;
			}
			else {
				dp[i][j] = max(dp[i - 1][j - 1], dp[i - 1][j]) + num;

				maxValue = max(maxValue, dp[i][j]);
			}
		}
	}

	cout << maxValue;
}