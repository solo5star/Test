#include <bits/stdc++.h>

using namespace std;

typedef struct {
	int to;
	int cost;
} edge;

typedef struct {
	int mid;
	int to;
	int cost;
} path;

bool operator<(const path& a, const path& b) {
	return a.cost > b.cost;
}

int trueVal = 1;
int banned[500][500];

int calculateShortestPath(vector<vector<edge>>& nodes, vector<vector<int>>& traces, int from, int to) {
	vector<int> costs(500, INT_MAX);

	costs[from] = 0;

	priority_queue<path> pq;

	for (edge& e : nodes[from]) {
		pq.push({ from, e.to, e.cost });
	}

	while (!pq.empty()) {
		path p = pq.top();
		pq.pop();

		if (banned[p.mid][p.to] == trueVal) continue;

		if (costs[p.to] < p.cost) continue;

		if (costs[p.to] == p.cost) {
			traces[p.to].push_back(p.mid);
		}
		else {
			traces[p.to].clear();
			traces[p.to].push_back(p.mid);
		}

		costs[p.to] = p.cost;

		for (edge& e : nodes[p.to]) {
			path _p = { p.to, e.to, p.cost + e.cost };

			if (banned[_p.mid][_p.to] == trueVal) continue;

			pq.push(_p);
		}
	}

	return costs[to];
}

void banShortestPath(vector<vector<int>>& traces, int from, int to) {
	queue<int> midpoints;

	midpoints.push(to);

	while (!midpoints.empty()) {
		int _to = midpoints.front();
		midpoints.pop();

		for (int mid : traces[_to]) {
			if (banned[mid][_to] == trueVal) continue;

			banned[mid][_to] = trueVal;

			if (mid != from) midpoints.push(mid);
		}
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	int nodeCount;
	int edgeCount;

	int from, to;
	int _from, _to, cost;

	while (true) {
		cin >> nodeCount >> edgeCount;

		if (nodeCount == 0 && edgeCount == 0) break;

		vector<vector<edge>> nodes(nodeCount);
		vector<vector<int>> traces(nodeCount);

		cin >> from >> to;

		for (int i = 0; i < edgeCount; i++) {
			cin >> _from >> _to >> cost;

			nodes[_from].push_back({ _to, cost });
		}

		calculateShortestPath(nodes, traces, from, to);

		banShortestPath(traces, from, to);

		cost = calculateShortestPath(nodes, traces, from, to);

		cout << (cost == INT_MAX ? -1 : cost) << "\n";

		for (int i = 0; i < nodeCount; i++) {
			nodes[i].clear();
			traces[i].clear();
		}

		trueVal++;
	}
}