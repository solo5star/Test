#define _CRT_SECURE_NO_WARNINGS

#include <bits/stdc++.h>

using namespace std;

bool nums[10001];

void filterSelfNum(int n) {
	int it = n;
	int sum = n;
	while (it) {
		sum += it % 10;
		it /= 10;
	}

	if (sum <= 10000) nums[sum] = true;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	for (int i = 0; i <= 10000; i++) {
		filterSelfNum(i);
	}

	for (int i = 0; i <= 10000; i++) {
		if (nums[i]) continue;

		cout << i << "\n";
	}
}