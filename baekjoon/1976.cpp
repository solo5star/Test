#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <utility>
#include <algorithm>
#include <string>
#include <math.h>
#include <queue>

using namespace std;

int parents[200];

int find(int n) {
	if (parents[n] == n) return n;

	return parents[n] = find(parents[n]);
}

void merge(int a, int b) {
	a = find(a);
	b = find(b);

	if (a == b) return;

	parents[b] = a;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int n, m, c;
	cin >> n >> m;

	for (int i = 1; i <= n; i++) {
		parents[i] = i;
	}

	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			cin >> c;

			if (c == 1) merge(i, j);
		}
	}

	bool canComplete = true;
	int prev = -1;
	for (int i = 0; i < m; i++) {
		cin >> c;
		if (prev != -1) {
			if (find(prev) != find(c)) {
				canComplete = false;
				break;
			}
		}
		prev = c;
	}

	cout << (canComplete ? "YES" : "NO");
}