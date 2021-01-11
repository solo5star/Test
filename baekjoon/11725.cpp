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

vector<int> nodes[100001];
int parents[100001];

queue<int> q;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int n, a, b;
	cin >> n;

	for (int i = 1; i < n; i++) {
		cin >> a >> b;

		nodes[a].push_back(b);
		nodes[b].push_back(a);
	}

	q.push(1);
	while (!q.empty()) {
		int parent = q.front();
		q.pop();

		for (int child : nodes[parent]) {
			if (parents[child]) continue;

			parents[child] = parent;

			q.push(child);
		}
	}

	for (int i = 2; i <= n; i++) {
		cout << parents[i] << "\n";
	}
}