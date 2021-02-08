#define _CRT_SECURE_NO_WARNINGS

#include <bits/stdc++.h>

using namespace std;

using app = struct {
	int memory;
	int cost;
};

app apps[101];
int dp[101][10001];

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	int n, requiredMemory, totalCost = 0;
	cin >> n >> requiredMemory;

	for (int i = 1; i <= n; i++) {
		cin >> apps[i].memory;
	}
	for (int i = 1; i <= n; i++) {
		cin >> apps[i].cost;

		totalCost += apps[i].cost;
	}

	int minCost = INT_MAX;

	// i: app id
	// j: cost (key point = maximum memory with minimum cost)
	for (int i = 1; i <= n; i++) {
		for (int j = 0; j <= totalCost; j++) {
			dp[i][j] = max(dp[i - 1][j], j == 0 ? 0 : dp[i][j - 1]);

			if (j >= apps[i].cost) {
				int includesThis = dp[i - 1][j - apps[i].cost] + apps[i].memory;

				// update maximum cost (if satisfy requiredMemory)
				if (includesThis >= requiredMemory) minCost = min(minCost, j);

				dp[i][j] = max(dp[i][j], includesThis);
			}
		}
	}

	cout << minCost;
}