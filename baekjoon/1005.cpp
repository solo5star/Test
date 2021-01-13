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
	int cost;
	int requiredCost;
	int inDegree;
	vector<int> children;
} node;

node nodes[1001];

int nodesCount;
int edgesCount;

queue<int> q;

void calculateCosts() {
	for (int i = 1; i <= nodesCount; i++) {
		if (nodes[i].inDegree == 0) {
			q.push(i);
		}
	}

	while (!q.empty()) {
		node& n = nodes[q.front()];
		q.pop();

		n.cost += n.requiredCost;

		for (int id : n.children) {
			node& children = nodes[id];
			children.requiredCost = max(n.cost, children.requiredCost);
			children.inDegree--;

			if (children.inDegree == 0) q.push(id);
		}
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	int t, from, to, destination;
	cin >> t;
	while (t--) {
		cin >> nodesCount >> edgesCount;

		for (int i = 1; i <= nodesCount; i++) {
			nodes[i].children.clear();
			nodes[i].requiredCost = 0;
			nodes[i].inDegree = 0;

			cin >> nodes[i].cost;
		}

		for (int i = 0; i < edgesCount; i++) {
			cin >> from >> to;

			nodes[from].children.push_back(to);
			nodes[to].inDegree++;
		}

		cin >> destination;

		calculateCosts();

		cout << nodes[destination].cost << "\n";
	}
}