#define _CRT_SECURE_NO_WARNINGS

#include <bits/stdc++.h>

using namespace std;

typedef unsigned long long data_t;

data_t dp[91] = { 0, 1, 1, 2 };

data_t fib(data_t n) {
	if (n == 0) return 0;
	if (dp[n]) return dp[n];

	return dp[n] = fib(n - 1) + fib(n - 2);
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	data_t n;
	cin >> n;

	cout << fib(n);
}