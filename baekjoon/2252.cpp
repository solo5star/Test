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
	int inDegree;
	vector<int> children;
} node;

node nodes[32001];

int nodesCount;
int edgesCount;

queue<int> q;

void topologySort() {
	for (int i = 1; i <= nodesCount; i++) {
		if (nodes[i].inDegree == 0) q.push(i);
	}

	while (!q.empty()) {
		cout << q.front() << " ";

		node& n = nodes[q.front()];
		q.pop();

		for (int id : n.children) {
			node& child = nodes[id];

			child.inDegree--;
			if (child.inDegree == 0) q.push(id);
		}
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	int a, b;
	cin >> nodesCount >> edgesCount;

	for (int i = 0; i < edgesCount; i++) {
		cin >> a >> b;

		nodes[a].children.push_back(b);
		nodes[b].inDegree++;
	}

	topologySort();
}