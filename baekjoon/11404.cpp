#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <utility>
#include <algorithm>
#include <math.h>

using namespace std;

int costs[101][101];
int cities = 0;

void floydWarshall() {
	for (int mid = 1; mid <= cities; mid++) {
		for (int from = 1; from <= cities; from++) {
			for (int to = 1; to <= cities; to++) {
				if (from == to) continue;

				if (costs[from][mid] && costs[mid][to]) {
					if (costs[from][to] == 0) costs[from][to] = costs[from][mid] + costs[mid][to];

					else costs[from][to] = min(costs[from][to], costs[from][mid] + costs[mid][to]);
				}
			}
		}
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int n, m;
	cin >> cities >> m;

	int from, to, cost;

	for (int i = 0; i < m; i++) {
		cin >> from >> to >> cost;

		if (costs[from][to] == 0) costs[from][to] = cost;

		else costs[from][to] = min(costs[from][to], cost);
	}

	floydWarshall();

	for (int from = 1; from <= cities; from++) {
		for (int to = 1; to <= cities; to++) {
			cout << costs[from][to] << (to == cities ? "" : " ");
		}
		cout << "\n";
	}
}