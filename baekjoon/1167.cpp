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

typedef struct {
	int to;
	int distance;
} edge;

typedef struct {
	bool visited;
	vector<edge> edges;
} node;

node nodes[100001];

int maximumDepth = 0;
int maximumNode = 0;

void dfs(int id, int depth = 0) {
	if (nodes[id].visited) return;
	nodes[id].visited = true;

	if (depth > maximumDepth) {
		maximumDepth = depth;
		maximumNode = id;
	}

	for (edge& e : nodes[id].edges) {
		dfs(e.to, depth + e.distance);
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int n, from, to, distance;
	cin >> n;

	for (int i = 0; i < n; i++) {
		cin >> from;

		while (true) {
			cin >> to;

			if (to == -1) break;

			cin >> distance;

			nodes[from].edges.push_back({ to, distance });
		}
	}

	dfs(1);

	for (int i = 1; i <= n; i++) {
		nodes[i].visited = false;
	}

	dfs(maximumNode);

	cout << maximumDepth;
}