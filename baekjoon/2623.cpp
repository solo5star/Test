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

vector<int> nodes[1001];
int indegrees[1001];
bool visited[1001];
int nodeCount;

queue<int> order;
queue<int> q;

bool topologySort() {
	for (int i = 1; i <= nodeCount; i++) {
		if (indegrees[i] == 0) q.push(i);
	}

	if (q.empty()) return false;

	while (!q.empty()) {
		int n = q.front();
		q.pop();

		if (visited[n]) return false;
		visited[n] = true;

		order.push(n);

		for (int _n : nodes[n]) {
			indegrees[_n]--;

			if (indegrees[_n] == 0) q.push(_n);
		}

		nodes[n].clear();
	}

	for (int i = 1; i <= nodeCount; i++) {
		if (nodes[i].size() > 0) return false;

		if (!visited[i]) order.push(i);
	}

	return true;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	
	int cases;
	cin >> nodeCount >> cases;

	int edgeCount;
	for (int i = 0; i < cases; i++) {
		cin >> edgeCount;

		int previous = 0;
		int current = 0;

		for (int j = 0; j < edgeCount; j++) {
			if (previous == 0) {
				cin >> previous;
			}
			else {
				cin >> current;

				nodes[previous].push_back(current);
				indegrees[current]++;

				previous = current;
			}
		}
	}

	if (topologySort()) {
		while (!order.empty()) {
			cout << order.front() << "\n";
			order.pop();
		}
	}
	else {
		cout << 0;
	}
}