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

bool operator<(const node& a, const node& b) { return a.cost > b.cost; }
bool operator>(const node& a, const node& b) { return a.cost < b.cost; }

vector<node> nodes_straight[1001];
vector<node> nodes_reverse[1001];
int costs_straight[1001];
int costs_reverse[1001];

int nodesCount;
int edgesCount;
int startNode;

priority_queue<node> pq;

void dijkstra(bool reverse) {
	vector<node> (&nodes)[1001] = reverse ? nodes_reverse : nodes_straight;
	int(&costs)[1001] = reverse ? costs_reverse : costs_straight;

	for (int i = 1; i <= nodesCount; i++) {
		costs[i] = INF;
	}

	pq.push({ startNode, 0 });

	while (!pq.empty()) {
		node n = pq.top();
		pq.pop();

		if (costs[n.id] > n.cost) {
			costs[n.id] = n.cost;

			for (node _n : nodes[n.id]) {
				pq.push({ _n.id, n.cost + _n.cost });
			}
		}
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> nodesCount >> edgesCount >> startNode;

	int from, to, cost;
	for (int i = 0; i < edgesCount; i++) {
		cin >> from >> to >> cost;

		nodes_straight[from].push_back({ to, cost });
		nodes_reverse[to].push_back({ from, cost });
	}

	dijkstra(false);
	dijkstra(true);

	int biggest = 0;
	for (int i = 1; i <= nodesCount; i++) {
		biggest = max(biggest, costs_straight[i] + costs_reverse[i]);
	}
	cout << biggest;
}