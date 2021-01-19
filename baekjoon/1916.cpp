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

bool operator<(const edge& a, const edge& b) {
	return a.cost > b.cost;
}

vector<edge> nodes[1001];
int nodeCount;
int edgeCount;

int costs[1001];

int getShortestPath(int from, int to) {
	for (int i = 1; i <= nodeCount; i++) {
		costs[i] = i == from ? 0 : INF;
	}

	priority_queue<edge> pq;

	for (edge& e : nodes[from]) {
		pq.push(e);
	}

	while (!pq.empty()) {
		edge e = pq.top();
		pq.pop();

		if (costs[e.to] <= e.cost) continue;

		costs[e.to] = e.cost;

		for (edge& _e : nodes[e.to]) {
			pq.push({ _e.to, _e.cost + e.cost });
		}
	}

	return costs[to];
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

	cout << getShortestPath(from, to);
}