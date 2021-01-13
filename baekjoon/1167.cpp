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
	int id;
	vector<edge> edges;
} node;

bool visited[100001];
node nodes[100001];

int maximumDepth = 0;
int maximumNode = 0;

void dfs(node& n, int depth = 0) {
	if (visited[n.id]) return;
	visited[n.id] = true;

	if (depth > maximumDepth) {
		maximumDepth = depth;
		maximumNode = n.id;
	}

	if (n.edges.empty()) return;

	for (edge& e : n.edges) {
		dfs(nodes[e.to], depth + e.distance);
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

		nodes[from].id = from;

		while (true) {
			cin >> to;

			if (to == -1) break;

			cin >> distance;

			nodes[from].edges.push_back({ to, distance });
		}
	}

	dfs(nodes[1]);

	for (int i = 0; i < n; i++) {
		visited[i] = false;
	}

	dfs(nodes[maximumNode]);

	cout << maximumDepth;
}