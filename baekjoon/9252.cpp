#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <utility>
#include <algorithm>
#include <string>
#include <vector>
#include <math.h>
#include <queue>

using namespace std;

// 1d: str1
// 2d: str2
int dp[1001][1001];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	string str1, str2;
	cin >> str2 >> str1;

	int maxValue = 0;

	for (int i = 0; i < str1.length(); i++) {
		for (int j = 0; j < str2.length(); j++) {
			if (str1[i] == str2[j]) {
				dp[i + 1][j + 1] = dp[i][j] + 1;
			}
			else {
				dp[i + 1][j + 1] = max(dp[i + 1][j], dp[i][j + 1]);
			}
			maxValue = max(maxValue, dp[i + 1][j + 1]);
		}
	}

	cout << maxValue;

	if (maxValue > 0) {
		cout << "\n";

		int current = 0;
		for (int i = 0; i < str2.length(); i++) {
			if (current != dp[str1.length()][i+1]) {
				current = dp[str1.length()][i+1];

				cout << str2[i];
			}
		}
	}
}