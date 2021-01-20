#define _CRT_SECURE_NO_WARNINGS
#include <bits/stdc++.h>

using namespace std;

const int INF = (1 << 29);

typedef struct { int to; int cost; } edge;

bool operator<(const edge& a, const edge& b) {
	return a.cost > b.cost;
}

int nodeCount;

int getShortestPath(vector<vector<edge>>& nodes, vector<vector<int>>& traces, int from, int to) {
	vector<int> costs(nodeCount, INF);
	priority_queue<edge> pq;

	pq.push({ from, 0 });
	costs[from] = 0;

	while (!pq.empty()) {
		edge e = pq.top();
		pq.pop();

		int mid = e.to;

		if (costs[mid] != e.cost) continue;

		for (edge& _e : nodes[mid]) {
			// removed
			if (_e.to == -1) continue;

			edge next = { _e.to, e.cost + _e.cost };

			if (costs[next.to] < next.cost) continue;

			if (costs[next.to] == next.cost) {
				traces[next.to].push_back(mid);
			}
			else {
				traces[next.to].clear();
				traces[next.to].push_back(mid);
			}

			costs[next.to] = next.cost;

			pq.push(next);
		}
	}

	return costs[to];
}

void removeShortestPath(vector<vector<edge>>& nodes, vector<vector<int>>& traces, int from, int to) {
	queue<int> q;
	q.push(to);

	while (!q.empty()) {
		int _to = q.front();
		q.pop();

		for (int mid : traces[_to]) {
			// remove path
			for (int i = 0; i < nodes[mid].size(); i++) {
				if (nodes[mid][i].to == _to) nodes[mid][i].to = -1;
			}

			if (mid != from) q.push(mid);
		}
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	//freopen("1.in", "r", stdin);

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

		cout << (cost == INF ? -1 : cost) << "\n";
	}
}