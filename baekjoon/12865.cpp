#define _CRT_SECURE_NO_WARNINGS

#include <bits/stdc++.h>

using namespace std;

using thing = struct {
	int weight;
	int price;
};

thing things[101];
int dp[101][100001];

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	int n, k;
	cin >> n >> k;

	for (int i = 1; i <= n; i++) {
		cin >> things[i].weight >> things[i].price;
	}

	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= k; j++) {
			// inherit previous state:
			//   [i - 1][j]: previous thing
			//   [i][j - 1]: previous weight
			dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);

			if (things[i].weight <= j) {
				if (dp[i][j] < dp[i][j - things[i].weight] + things[i].price) {
					dp[i][j] = dp[i][j - things[i].weight] + things[i].price;
				}
			}
		}
	}

	cout << dp[n][k];
}