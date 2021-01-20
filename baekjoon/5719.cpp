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

vector<vector<edge>> nodes(500);
int nodeCount;
int edgeCount;

int trueVal = 1;
int banned[500][500];

vector<vector<int>> trace(500);
vector<int> costs(500);

bool isBetterPath(path& p) {
	if (banned[p.mid][p.to] == trueVal) return false;

	if (costs[p.to] < p.cost) return false;

	return true;
}

int calculateShortestPath(int from, int to) {
	fill(costs.begin(), costs.end(), INT_MAX);

	costs[from] = 0;

	priority_queue<path> pq;

	for (edge& e : nodes[from]) {
		pq.push({ from, e.to, e.cost });
	}

	while (!pq.empty()) {
		path p = pq.top();
		pq.pop();

		if (!isBetterPath(p)) continue;

		if (costs[p.to] == p.cost) {
			trace[p.to].push_back(p.mid);
		}
		else {
			trace[p.to].clear();
			trace[p.to].push_back(p.mid);
		}

		costs[p.to] = p.cost;

		for (edge& e : nodes[p.to]) {
			path _p = { p.to, e.to, p.cost + e.cost };

			if (!isBetterPath(_p)) continue;

			pq.push(_p);
		}
	}

	return costs[to];
}

void _banShortestPath(int from, int to) {
	queue<int> midpoints;

	midpoints.push(to);

	while (!midpoints.empty()) {
		int _to = midpoints.front();
		midpoints.pop();

		for (int mid : trace[_to]) {
			if (banned[mid][_to] == trueVal) continue;

			banned[mid][_to] = trueVal;

			if (mid != from) midpoints.push(mid);
		}
	}
}

void banShortestPath(int from, int to) {
	_banShortestPath(from, to);
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	int from, to;
	int _from, _to, cost;

	while (true) {
		cin >> nodeCount >> edgeCount;

		if (nodeCount == 0 && edgeCount == 0) break;

		cin >> from >> to;

		for (int i = 0; i < edgeCount; i++) {
			cin >> _from >> _to >> cost;

			nodes[_from].push_back({ _to, cost });
		}

		calculateShortestPath(from, to);

		banShortestPath(from, to);

		cost = calculateShortestPath(from, to);

		cout << (cost == INT_MAX ? -1 : cost) << "\n";

		for (int i = 0; i < nodeCount; i++) {
			nodes[i].clear();
			trace[i].clear();
		}

		trueVal++;
	}
}