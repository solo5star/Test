#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <utility>
#include <algorithm>
#include <string>
#include <math.h>
#include <queue>

using namespace std;

typedef struct { int x; int y; } point;

// 1 = START
// 2 = END
// 3~ = CONVINIENT
const int NODE_START = 1;
const int NODE_END = 2;

int nodesCount = 0;
point nodes[103];
int distances[103][103];
bool visited[103];

queue<int> q;

int distance(point& from, point& to) {
	return abs(from.x - to.x) + abs(from.y - to.y);
}

bool bfs() {
	bool success = false;

	while (!q.empty()) {
		int nodeId = q.front();
		q.pop();

		visited[nodeId] = true;

		for (int i = 1; i <= nodesCount; i++) {
			if (visited[i] == true) continue;

			if (distances[nodeId][i] <= 1000) {
				if (i == NODE_END) {
					success = true;

					// CLEAR QUEUE
					while (!q.empty()) q.pop();

					break;
				}
				else {
					q.push(i);
				}
			}
		}
	}

	// CLEAR VISITED
	for (int i = 1; i <= nodesCount; i++) {
		visited[i] = false;
	}

	return success;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int t, n, x, y;
	cin >> t;

	while (t--) {
		cin >> n;
		nodesCount = n + 2;

		// INPUT: START
		cin >> x >> y;
		nodes[NODE_START] = { x, y };

		// INPUT: CONVINIENT
		for (int i = 3; i <= nodesCount; i++) {
			cin >> x >> y;
			nodes[i] = { x, y };
		}

		// INPUT: END
		cin >> x >> y;
		nodes[NODE_END] = { x, y };

		// INITIALIZE DISTANCES
		for (int i = 1; i <= nodesCount; i++) {
			for (int j = 1; j <= nodesCount; i++) {
				distances[i][j] = 0;
			}
		}

		// CALCULATE DISTANCES
		for (int via = 1; via <= nodesCount; via++) {
			for (int from = 1; from <= nodesCount; from++) {
				for (int to = 1; to <= nodesCount; to++) {
					if (distances[from][to] == 0) distances[from][to] = distance(nodes[from], nodes[to]);

					distances[from][to] = min(
						distances[from][to],
						distance(nodes[from], nodes[via]) + distance(nodes[via], nodes[to])
					);
				}
			}
		}

		// BFS
		q.push(NODE_START);
		cout << (bfs() ? "happy" : "sad") << "\n";
	}
}