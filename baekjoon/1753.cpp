#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <utility>
#include <algorithm>
#include <string>
#include <vector>
#include <math.h>
#include <cstring>
#include <queue>

using namespace std;

const int INF = ~(1 << 31);

typedef struct {
	int id;
	int cost;
} node;

bool operator<(const node& a, const node& b) {
	// Small-first out
	return a.cost > b.cost;
}

vector<node> nodes[20001];
int costs[20001];
int nodesCount;
int edgesCount;

priority_queue<node> pq;

void dijkstra(int start) {
	for (node n : nodes[start]) {
		pq.push(n);
	}

	while (!pq.empty()) {
		node n = pq.top();
		pq.pop();

		if(n.cost < costs[n.id]) {
			costs[n.id] = n.cost;

			for (node _n : nodes[n.id]) {
				pq.push({ _n.id, n.cost + _n.cost });
			}
		}
	}

	for (int i = 1; i <= nodesCount; i++) {
		if (costs[i] == INF) cout << "INF";
		else cout << costs[i];
		cout << "\n";
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int startNode;
	cin >> nodesCount >> edgesCount >> startNode;

	int u, v, w;
	for (int i = 0; i < edgesCount; i++) {
		cin >> u >> v >> w;

		nodes[u].push_back({ v, w });
	}

	for (int i = 1; i <= nodesCount; i++) {
		costs[i] = startNode == i ? 0 : INF;
	}

	dijkstra(startNode);
}