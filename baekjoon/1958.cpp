#define _CRT_SECURE_NO_WARNINGS

#include <bits/stdc++.h>

using namespace std;

string str1, str2, str3;

int dp[101][101][101];

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	cin >> str1 >> str2 >> str3;

	for (int i = 1; i <= str1.length(); i++) {
		for (int j = 1; j <= str2.length(); j++) {
			for (int k = 1; k <= str3.length(); k++) {
				// Longest subsequence with previous str1, str2, str3
				dp[i][j][k] = max({ dp[i - 1][j][k], dp[i][j - 1][k], dp[i][j][k - 1] });

				// +1 if current characters are match
				if (str1[i - 1] == str2[j - 1] && str2[j - 1] == str3[k - 1]) {
					dp[i][j][k] = dp[i - 1][j - 1][k - 1] + 1;
				}
			}
		}
	}

	cout << dp[str1.length()][str2.length()][str3.length()];
}