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

vector<edge> nodes[500];
int nodeCount;
int edgeCount;

bool banned[500][500];

struct {
	vector<int> mid;
	int cost;
} costs[500];

priority_queue<path> pq;

bool isBetterPath(path& p) {
	if (banned[p.mid][p.to]) return false;

	if (costs[p.to].cost < p.cost) return false;

	return true;
}

int calculateShortestPath(int from, int to) {
	for (int i = 0; i < nodeCount; i++) {
		costs[i].cost = INT_MAX;
		costs[i].mid.clear();
	}

	costs[from].cost = 0;

	for (edge& e : nodes[from]) {
		pq.push({ from, e.to, e.cost });
	}

	while (!pq.empty()) {
		path p = pq.top();
		pq.pop();

		if (!isBetterPath(p)) continue;

		if (costs[p.to].cost == p.cost) {
			costs[p.to].mid.push_back(p.mid);
		}
		else {
			costs[p.to].mid.clear();
			costs[p.to].mid.push_back(p.mid);
		}

		costs[p.to].cost = p.cost;

		for (edge& e : nodes[p.to]) {
			path _p = { p.to, e.to, p.cost + e.cost };

			if (!isBetterPath(_p)) continue;

			pq.push(_p);
		}
	}

	return costs[to].cost;
}

void _banShortestPath(int from, int to) {
	for (int mid : costs[to].mid) {
		banned[mid][to] = true;

		if (mid == from) continue;

		_banShortestPath(from, mid);
	}
}

void banShortestPath(int from, int to) {
	_banShortestPath(from, to);
}

void clear() {
	for (int i = 0; i < nodeCount; i++) {
		nodes[i].clear();
		costs[i].mid.clear();
	}

	memset(banned, 0, sizeof(banned));
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

		clear();
	}
}