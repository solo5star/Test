#define _CRT_SECURE_NO_WARNINGS

#include <bits/stdc++.h>

using namespace std;

using data_t = unsigned int;

const data_t INF = ~0;

// first dimension: N-th work
// second dimension: works complete
data_t dp[2][1048576];

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	int n;
	cin >> n;

	data_t works[20];

	data_t end = 1 << n;

	int current = 0;
	int previous = 1;

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> works[j];

			int flag = 1 << j;

			if (i == 0) {
				dp[current][flag] = works[j];
			}
			else {
				for (int k = 0; k < end; k++) {
					// already finished by previous worker
					if (k & flag) continue;

					// previous state is not exists
					if (dp[previous][k] == 0) continue;

					// initialize current state
					if (dp[current][k | flag] == 0) dp[current][k | flag] = INF;

					// update current state by previous + current value
					dp[current][k | flag] = min(dp[current][k | flag], dp[previous][k] + works[j]);
				}
			}
		}

		// toggle bits
		current ^= 1;
		previous ^= 1;
	}

	cout << dp[previous][end - 1];
}