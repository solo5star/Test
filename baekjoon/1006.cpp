#define _CRT_SECURE_NO_WARNINGS

#include <bits/stdc++.h>

using namespace std;

int area[10000][2];

const int ABOVE = 0;
const int BELOW = 1;
const int STRETCH = 2;
int dp[10000][3];

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	int t;
	cin >> t;
	while (t--) {
		unsigned int n, forces;
		cin >> n >> forces;

		for (int i = 0; i < n; i++) cin >> area[i][0];
		for (int i = 0; i < n; i++) cin >> area[i][1];

		int maxValue = 0;

		for (int allowsThrough = 0; allowsThrough <= 1; allowsThrough++) {
			dp[0][ABOVE] = 0;
			dp[0][BELOW] = 0;

			if (n >= 2 && allowsThrough) {
				if (area[0][ABOVE] + area[n - 1][ABOVE] <= forces) {
					dp[0][ABOVE] = 1;
					area[0][ABOVE] = area[n - 1][ABOVE] = forces + 1;
				}
				if (area[0][BELOW] + area[n - 1][BELOW] <= forces) {
					dp[0][BELOW] = 1;
					area[0][BELOW] = area[n - 1][BELOW] = forces + 1;
				}
			}

			dp[0][STRETCH] = max({
				dp[0][ABOVE],
				dp[0][BELOW],
				(int)(area[0][ABOVE] + area[0][BELOW] <= forces)
			});

			// ■: PREVIOUS
			// □: CURRENT
			// ＊: EMPTY
			for (int i = 1; i < n; i++) {
				dp[i][BELOW] = max(
					// ■■■
					// ■■□□
					dp[i - 1][ABOVE] + (area[i][BELOW] + area[i - 1][BELOW] <= forces),

					// ■■■
					// ■■■□
					dp[i - 1][STRETCH]
				);

				dp[i][ABOVE] = max(
					// ■■□□
					// ■■■
					dp[i - 1][BELOW] + (area[i][ABOVE] + area[i - 1][ABOVE] <= forces),

					// ■■■□
					// ■■■
					dp[i - 1][STRETCH]
				);

				dp[i][STRETCH] = max(
					// ■■■□
					// ■■■□
					dp[i - 1][STRETCH] + (area[i][BELOW] + area[i][ABOVE] <= forces),

					// ■■□□
					// ■■□□
					i > 1 ? dp[i - 2][STRETCH] + (area[i - 1][BELOW] + area[i][BELOW] <= forces) + (area[i - 1][ABOVE] + area[i][ABOVE] <= forces) : 0
				);
			}

			maxValue = max({
				maxValue,
				dp[n - 1][ABOVE],
				dp[n - 1][BELOW],
				dp[n - 1][STRETCH]
			});
		}

		cout << n * 2 - maxValue << "\n";
	}
}