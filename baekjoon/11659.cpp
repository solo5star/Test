#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <utility>
#include <algorithm>
#include <string>
#include <vector>
#include <math.h>
#include <queue>

using namespace std;

int sums[100001];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	int n, m;
	cin >> n >> m;

	for (int i = 1; i <= n; i++) {
		cin >> sums[i];
		sums[i] += sums[i - 1];
	}

	int from, to;
	for (int i = 0; i < m; i++) {
		cin >> from >> to;

		cout << sums[to] - sums[from - 1] << "\n";
	}
}