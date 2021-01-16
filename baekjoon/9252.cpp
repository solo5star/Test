#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <utility>
#include <algorithm>
#include <string>
#include <vector>
#include <math.h>
#include <queue>
#include <stack>

using namespace std;

int dp[1001][1001];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	string str1, str2;
	cin >> str1 >> str2;

	int maxValue = 0;

	for (int i = 0; i < str1.length(); i++) {
		for (int j = 0; j < str2.length(); j++) {
			// if character matches, previous +1
			if (str1[i] == str2[j]) {
				dp[i + 1][j + 1] = dp[i][j] + 1;
			}
			else {
				dp[i + 1][j + 1] = max(
					// previous (above)
					dp[i][j + 1],
					// previous (left)
					dp[i + 1][j]
				);
			}

			maxValue = max(maxValue, dp[i + 1][j + 1]);
		}
	}

	cout << maxValue;

	stack<char> ss;
	if (maxValue) {
		cout << "\n";

		int i = str1.length(), j = str2.length();

		while (i > 0 && j > 0) {
			while (dp[i][j] == dp[i][j - 1]) j--;
			while (dp[i][j] == dp[i - 1][j]) i--;

			ss.push(str1[i - 1]);

			i--;
			j--;
		}

		while (!ss.empty()) {
			cout << ss.top();
			ss.pop();
		}
	}
}