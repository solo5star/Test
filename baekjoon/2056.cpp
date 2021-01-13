#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <utility>
#include <algorithm>
#include <string>
#include <vector>
#include <math.h>
#include <queue>

using namespace std;

int costs[10001];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	int n, k, node, cost;
	cin >> n;

	for (int i = 1; i <= n; i++) {
		int requiredCost = 0;

		cin >> cost;
		cin >> k;

		while (k--) {
			cin >> node;

			requiredCost = max(requiredCost, costs[node]);
		}

		costs[i] = cost + requiredCost;
	}

	cout << costs[n];
}