#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <iomanip>
#include <utility>
#include <algorithm>
#include <string>
#include <vector>
#include <math.h>
#include <queue>
#include <stack>
#include <limits.h>

using namespace std;

vector<int> nodes[101];
int nodeCount;
int edgeCount;

bool visited[101];

int floodfill(int node) {
	queue<int> q;

	q.push(node);

	int count = 0;
	while (!q.empty()) {
		int n = q.front();
		q.pop();

		if (visited[n]) continue;
		visited[n] = true;
		count++;

		for (int _n : nodes[n]) {
			if (visited[_n]) continue;

			q.push(_n);
		}
	}

	return count;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	cin >> nodeCount >> edgeCount;

	int from, to;
	for (int i = 0; i < edgeCount; i++) {
		cin >> from >> to;

		nodes[from].push_back(to);
		nodes[to].push_back(from);
	}

	cout << floodfill(1) - 1;
}