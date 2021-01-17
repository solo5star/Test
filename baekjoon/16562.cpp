#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <utility>
#include <algorithm>
#include <string>
#include <vector>
#include <math.h>
#include <queue>
#include <stack>
#include <limits.h>

using namespace std;

int parents[10001];
int costs[10001];

int parent(int a) {
	if (parents[a] == a) return a;

	return parents[a] = parent(parents[a]);
}

void join(int a, int b) {
	int _a = parent(a);
	int _b = parent(b);

	parents[_b] = _a;

	costs[_a] = min(min(costs[_a], costs[_b]), min(costs[a], costs[b]));
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	int n, m, k;
	cin >> n >> m >> k;

	for (int i = 1; i <= n; i++) {
		parents[i] = i;

		cin >> costs[i];
	}

	int a, b;
	for (int i = 0; i < m; i++) {
		cin >> a >> b;

		join(a, b);
	}

	int sum = 0;
	int p;
	for (int i = 1; i <= n; i++) {
		p = parent(i);
		//cout << i << " parent is " << p << ": " << costs[p] << "\n";

		sum += costs[p];
		costs[p] = 0;
	}

	if (sum > k) cout << "Oh no";
	else cout << sum;
}