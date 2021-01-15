#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <utility>
#include <algorithm>
#include <string>
#include <vector>
#include <math.h>
#include <stack>
#include <sstream>

using namespace std;

typedef unsigned long long uint_64;

uint_64 dp[101][10];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	const uint_64 modBy = 1000000000;

	int n;
	cin >> n;

	for (int i = 1; i <= 9; i++) {
		dp[1][i] = 1;
	}

	for (int step = 2; step <= n; step++) {
		dp[step][0] = dp[step - 1][1];
		for (int i = 1; i < 9; i++) {
			dp[step][i] = (dp[step - 1][i - 1] + dp[step - 1][i + 1]) % modBy;
		}
		dp[step][9] = dp[step - 1][8];
	}

	uint_64 acc = 0;
	for (int i = 0; i <= 9; i++) {
		acc += dp[n][i];
		acc %= modBy;
	}
	cout << acc;
}