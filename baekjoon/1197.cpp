#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <utility>
#include <algorithm>
#include <string>
#include <vector>
#include <math.h>
#include <queue>

using namespace std;

typedef struct {
	int node;
	int cost;
} edge;

typedef struct {
	vector<edge> edges;
} node;

bool operator<(const edge& a, const edge& b) {
	return a.cost > b.cost;
}

node nodes[10001];
int nodesCount = 0;
int edgesCount = 0;

bool visited[10001];

typedef struct {
	int id;
	int accumulatedCost;
} node_next;

priority_queue<edge> pq;

int prim() {
	int accumulatedCost = 0;

	for (edge& e : nodes[1].edges) {
		pq.push(e);
	}
	visited[1] = true;

	while (!pq.empty()) {
		edge e = pq.top();
		pq.pop();

		if (visited[e.node]) continue;
		visited[e.node] = true;
		accumulatedCost += e.cost;

		for (edge& _e : nodes[e.node].edges) {
			if(!visited[_e.node]) pq.push(_e);
		}
	}

	return accumulatedCost;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	int n, from, to, cost;
	cin >> nodesCount >> edgesCount;

	for (int i = 0; i < edgesCount; i++) {
		cin >> from >> to >> cost;

		nodes[from].edges.push_back({ to, cost });
		nodes[to].edges.push_back({ from, cost });
	}

	cout << prim();
}