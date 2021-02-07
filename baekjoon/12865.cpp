#define _CRT_SECURE_NO_WARNINGS

#include <bits/stdc++.h>

using namespace std;

using thing = struct {
	int weight;
	int price;
};

thing things[101];
int dp[2][100001];

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	int n, k;
	cin >> n >> k;

	for (int i = 1; i <= n; i++) {
		cin >> things[i].weight >> things[i].price;
	}

	int previous = 0;
	int current = 1;

	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= k; j++) {
			// inherit previous state:
			//   [i - 1][j]: previous thing
			//   [i][j - 1]: previous weight
			dp[current][j] = max(dp[previous][j], dp[current][j - 1]);

			if (things[i].weight <= j) {
				// previous thing with backpack weight=(j - weight)
				if (dp[current][j] < dp[previous][j - things[i].weight] + things[i].price) {
					dp[current][j] = dp[previous][j - things[i].weight] + things[i].price;
				}
			}
		}

		previous ^= 1;
		current ^= 1;
	}

	cout << dp[previous][k];
}