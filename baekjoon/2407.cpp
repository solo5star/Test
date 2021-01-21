#define _CRT_SECURE_NO_WARNINGS

#include <bits/stdc++.h>

using namespace std;

typedef unsigned long long data_t;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	data_t n, m;
	cin >> n >> m;

	data_t result = 1;

	for (int i = 1; i <= m; i++) {
		result *= (n + 1 - i);
		result /= (i);
	}

	cout << result;
}