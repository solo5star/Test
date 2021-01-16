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
	cin >> str2 >> str1;

	int maxValue = 0;

	for (int i = 0; i < str1.length(); i++) {
		for (int j = 0; j < str2.length(); j++) {
			dp[i + 1][j + 1] = max(max(
				// if character matches, previous +1
				dp[i][j] + (str1[i] == str2[j]),
				// previous (left)
				dp[i + 1][j]),
				// previous (above)
				dp[i][j + 1]);

			maxValue = max(maxValue, dp[i + 1][j + 1]);
		}
	}

	cout << maxValue;

	stack<char> ss;
	if (maxValue) {
		cout << "\n";
		int i = str1.length();

		for (int j = str2.length(); j > 0; j--) {
			if (dp[i][j] != dp[i][j - 1]) {
				ss.push(str2[j - 1]);
				i--;
			}
		}

		while (!ss.empty()) {
			cout << ss.top();
			ss.pop();
		}
	}
}