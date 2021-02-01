#define _CRT_SECURE_NO_WARNINGS

#include <bits/stdc++.h>

using namespace std;

typedef unsigned long long uint_64;

uint_64 dp[1001][1001];

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	int height, width;
	cin >> height >> width;

	dp[0][0] = 1;

	for (int y = 1; y <= height; y++) {
		for (int x = 1; x <= width; x++) {
			dp[y][x] =
				(dp[y - 1][x - 1] // Source: ↘
				+ dp[y - 1][x] // Source: ↓
				+ dp[y][x - 1]) // Source: →

				% 1000000007; // Mod
		}
	}

	cout << dp[height][width];
}