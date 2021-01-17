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

typedef unsigned long long uint_64;

typedef struct {
	int to;
	int cost;
} edge;

vector<edge> nodes[100001];
int nodeCount;
int edgeCount;

bool operator<(const edge& a, const edge& b) {
	return a.cost > b.cost;
}

bool visited[100001];
priority_queue<edge> pq;

uint_64 mst() {
	uint_64 sum = 0;
	int maxEdgeCost = 0;

	for (edge& e : nodes[1]) {
		pq.push(e);
	}
	visited[1] = true;

	while (!pq.empty()) {
		edge e = pq.top();
		pq.pop();

		if (visited[e.to]) continue;
		visited[e.to] = true;

		sum += e.cost;
		maxEdgeCost = max(maxEdgeCost, e.cost);

		for (edge& _e : nodes[e.to]) {
			if (visited[_e.to]) continue;

			pq.push(_e);
		}
	}

	return sum - maxEdgeCost;
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
		nodes[to].push_back({ from, cost });
	}

	cout << mst();
}