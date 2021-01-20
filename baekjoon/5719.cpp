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

int nodeCount;

int getShortestPath(vector<vector<edge>>& nodes, vector<vector<int>>& traces, int from, int to) {
	vector<int> costs(nodeCount, INT_MAX);
	priority_queue<path> pq;

	costs[from] = 0;
	pq.push({ from, from, 0 });

	while (!pq.empty()) {
		path p = pq.top();
		pq.pop();

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
			// removed
			if (e.to == -1) continue;

			path _p = { p.to, e.to, p.cost + e.cost };

			pq.push(_p);
		}
	}

	return costs[to];
}

void removeShortestPath(vector<vector<edge>>& nodes, vector<vector<int>>& traces, int from, int to) {
	queue<int> midpoints;

	midpoints.push(to);

	while (!midpoints.empty()) {
		int _to = midpoints.front();
		midpoints.pop();

		for (int mid : traces[_to]) {
			// remove path
			for (int i = 0; i < nodes[mid].size(); i++) {
				if (nodes[mid][i].to == _to) nodes[mid][i].to = -1;
			}

			if (mid != from) midpoints.push(mid);
		}
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

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

		getShortestPath(nodes, traces, from, to);

		removeShortestPath(nodes, traces, from, to);

		cost = getShortestPath(nodes, traces, from, to);

		cout << (cost == INT_MAX ? -1 : cost) << "\n";
	}
}