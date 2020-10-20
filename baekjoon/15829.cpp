#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <utility>
#include <algorithm>
#include <math.h>

using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int n;
	string s;

	cin >> n;
	cin >> s;

	int dp[51];
	dp[0] = 1;
	dp[1] = 31;
	for (int i = 2; i < n; i++) {
		dp[i] = dp[i - 1] * 31;
	}

	int sum = 0;
	for (int i = 0; i < n; i++) {
		sum += (s[i] - 'a' + 1) * dp[i];
	}
	sum %= 1234567891;

	cout << sum;
}