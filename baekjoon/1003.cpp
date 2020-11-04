#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <utility>
#include <algorithm>
#include <math.h>
#include <unordered_map>
#include <string>
#include <math.h>

using namespace std;

bool searched[41];
pair<int, int> dp[41];

pair<int, int> fibonacci(int n) {
	if (n == 0) return make_pair<int, int>(1, 0);
	if (n == 1) return make_pair<int, int>(0, 1);

	if (searched[n]) {
		return dp[n];
	}

	pair<int, int> a = fibonacci(n - 1);
	pair<int, int> b = fibonacci(n - 2);

	pair<int, int> y = make_pair<int, int>(a.first + b.first, a.second + b.second);

	searched[n] = true;
	dp[n] = y;

	return y;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int t, n;
	pair<int, int> result;
	cin >> t;

	for (int i = 0; i < t; i++) {
		cin >> n;
		result = fibonacci(n);

		cout << result.first << " " << result.second << "\n";
	}
}