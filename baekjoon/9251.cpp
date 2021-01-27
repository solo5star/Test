#define _CRT_SECURE_NO_WARNINGS

#include <bits/stdc++.h>

using namespace std;

string str1, str2, str3;

int dp[1001][1001];

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	cin >> str1 >> str2;

	for (int i = 1; i <= str1.length(); i++) {
		for (int j = 1; j <= str2.length(); j++) {
			dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);

			if (str1[i - 1] == str2[j - 1]) {
				dp[i][j] = dp[i - 1][j - 1] + 1;
			}
		}
	}

	cout << dp[str1.length()][str2.length()];
}