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

int getDiameter(node& n) {
	visited[n.id] = true;

	if (n.edges.empty()) {
		return 0;
	}

	int maximum = 0;
	for (edge& e : n.edges) {
		if (visited[e.to]) continue;

		maximum = max(maximum, getDiameter(nodes[e.to]) + e.distance);
	}

	return maximum;
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

	cout << getDiameter(nodes[1]);
}