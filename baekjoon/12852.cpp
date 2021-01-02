#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <utility>
#include <algorithm>
#include <math.h>

using namespace std;

typedef unsigned long long uint_64;

typedef struct {
	int count;
	int previous;
} data_t;

data_t dp[1000001] = {
	{ 0, 0 },
	{ 0, 0 },
	{ 1, 1 },
	{ 1, 1 }
};

int n;

void jump(int index, int newIndex) {
	if (newIndex <= n && (dp[newIndex].count == 0 || dp[newIndex].count > dp[index].count + 1)) {
		dp[newIndex].count = dp[index].count + 1;
		dp[newIndex].previous = index;
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> n;

	for (int i = 3; i < n; i++) {
		int count = dp[i].count + 1;

		jump(i, i + 1);
		jump(i, i * 2);
		jump(i, i * 3);
	}

	cout << dp[n].count << "\n";

	while (n >= 1) {
		cout << n << " ";
		n = dp[n].previous;
	}
}