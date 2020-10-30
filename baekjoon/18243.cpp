#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <utility>
#include <algorithm>
#include <math.h>
#include <unordered_map>
#include <string>

using namespace std;

int graph[100][100];

const int INF = 100000;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int n, r, from, to;
	cin >> n >> r;

	for (int i = 0; i < r; i++) {
		cin >> from >> to;
		from--; to--;
		graph[from][to] = 1;
		graph[to][from] = 1;
	}

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (i == j) continue;

			if (graph[i][j] == 0) graph[i][j] = INF;
		}
	}

	// k: 거쳐가는 노드
	for (int k = 0; k < n; k++) {
		// i: 출발 노드
		for (int i = 0; i < n; i++) {
			// j: 도착 노드
			for (int j = 0; j < n; j++) {
				if (i == j) continue;

				if (graph[i][j] > graph[i][k] + graph[k][j]) {
					graph[i][j] = graph[i][k] + graph[k][j];
				}
			}
		}
	}

	bool isBigWorld = false;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (i == j) continue;

			if (graph[i][j] > 6) {
				isBigWorld = true;
				break;
			}
		}

		if (isBigWorld) break;
	}

	cout << (isBigWorld ? "Big World!" : "Small World!");
}