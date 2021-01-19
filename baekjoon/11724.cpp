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

vector<int> nodes[1001];
int nodeCount;
int edgeCount;

bool visited[1001];

void floodfill(int n) {
	queue<int> q;

	q.push(n);

	while (!q.empty()) {
		int _n = q.front();
		q.pop();

		if (visited[_n]) continue;
		visited[_n] = true;

		for (int __n : nodes[_n]) {
			if (visited[__n]) continue;

			q.push(__n);
		}
	}
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

	int component = 0;
	for (int i = 1; i <= nodeCount; i++) {
		if (visited[i]) continue;

		floodfill(i);
		component++;
	}

	cout << component;
}