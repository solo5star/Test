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

typedef struct {
	int to;
	int cost;
} edge;

bool priority_min_first = true;

bool operator<(const edge& a, const edge& b) {
	return priority_min_first ? (a.cost > b.cost) : (a.cost < b.cost);
}

vector<edge> nodes[1001];
bool visited[1001];
int nodeCount;
int edgeCount;

priority_queue<edge> pq;

int mst() {
	visited[0] = true;
	for (edge& e : nodes[0]) {
		pq.push(e);
	}

	int sum = 0;

	while (!pq.empty()) {
		edge e = pq.top();
		pq.pop();

		if (visited[e.to]) continue;
		visited[e.to] = true;

		sum += e.cost;

		for (edge& _e : nodes[e.to]) {
			if (visited[_e.to]) continue;

			pq.push(_e);
		}
	}

	return sum;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	cin >> nodeCount >> edgeCount;

	edgeCount++;

	int from, to, cost;
	for (int i = 0; i < edgeCount; i++) {
		cin >> from >> to >> cost;

		cost = cost == 0;

		nodes[from].push_back({ to, cost });
		nodes[to].push_back({ from, cost });
	}

	int minValue = mst();
	priority_min_first = false;
	for (int i = 0; i <= nodeCount; i++) {
		visited[i] = false;
	}
	int maxValue = mst();

	cout << pow(maxValue, 2) - pow(minValue, 2);
}