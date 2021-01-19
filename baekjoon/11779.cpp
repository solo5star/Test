#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <iomanip>
#include <utility>
#include <algorithm>
#include <string>
#include <vector>
#include <math.h>
#include <queue>
#include <stack>
#include <limits.h>

using namespace std;

const int INF = ~(1 << 31);

typedef struct {
	int to;
	int cost;
} edge;

typedef struct {
	int to;
	int mid;
	int cost;
} path;

bool operator<(const path& a, const path& b) {
	return a.cost > b.cost;
}

vector<edge> nodes[1001];
bool visited[1001];
path paths[1001];

int nodeCount;
int edgeCount;

void getShortestPath(int start, int end) {
	priority_queue<path> pq;

	for (int i = 1; i <= nodeCount; i++) {
		paths[i].cost = INF;
	}

	for (edge& e : nodes[start]) {
		pq.push({ e.to, 0, e.cost });
	}

	while (!pq.empty()) {
		path p = pq.top();
		pq.pop();

		if (visited[p.to]) continue;
		visited[p.to] = true;

		if (paths[p.to].cost <= p.cost) continue;
		paths[p.to].mid = p.mid;
		paths[p.to].cost = p.cost;

		for (edge& _e : nodes[p.to]) {
			if (visited[_e.to]) continue;

			pq.push({ _e.to, p.to, p.cost + _e.cost });
		}
	}

	// PRINT MINIMAL COST
	cout << paths[end].cost << "\n";

	stack<int> trace;
	trace.push(end);

	path current = paths[end];
	while (current.mid) {
		trace.push(current.mid);

		current = paths[current.mid];
	}
	trace.push(start);

	// PRINT PATH COUNT
	cout << trace.size() << "\n";

	// PRINT PATH
	while (!trace.empty()) {
		cout << trace.top() << " ";
		trace.pop();
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	cin >> nodeCount >> edgeCount;

	int from, to, cost;
	for (int i = 0; i < edgeCount; i++) {
		cin >> from >> to >> cost;

		nodes[from].push_back({ to, cost });
	}

	cin >> from >> to;

	getShortestPath(from, to);
}