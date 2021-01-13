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

int maximum = 0;

int dfs(node& n, int depth = 0) {
	visited[n.id] = true;

	if (n.edges.empty()) {
		return 0;
	}

	int maximumOfChild = 0;
	int m1 = 0;
	int m2 = 0;
	int distance;

	for (edge& e : n.edges) {
		if (visited[e.to]) continue;

		distance = dfs(nodes[e.to], depth + e.distance) + e.distance;

		maximumOfChild = max(maximumOfChild, distance);

		if (distance >= m1) {
			m2 = m1;
			m1 = distance;
		}
	}

	maximum = max(maximum, m1 + max(m2, depth));

	return maximumOfChild;
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

	cout << maximum;
}