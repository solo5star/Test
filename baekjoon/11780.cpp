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

int nodes[101][101];
int routes[101][101];

int nodesCount;
int edgesCount;

vector<int> routeTrace;

void calculateAllDistances() {
	for (int via = 1; via <= nodesCount; via++) {
		for (int from = 1; from <= nodesCount; from++) {
			for (int to = 1; to <= nodesCount; to++) {
				if (from == to || from == via || via == to) continue;

				bool canThrough = nodes[from][to] != 0;
				bool canBypass = nodes[from][via] != 0 && nodes[via][to] != 0;

				int through = nodes[from][to];
				int bypass = nodes[from][via] + nodes[via][to];

				if (canBypass && (!canThrough || bypass < through)) {
					nodes[from][to] = bypass;
					routes[from][to] = via;
				}
			}
		}
	}
}

void _printRouteTraceRecursive(int from, int to) {
	if (from == to) return;

	int via = routes[from][to];

	if (to != via)  {
		_printRouteTraceRecursive(from, via);

		routeTrace.push_back(via);

		_printRouteTraceRecursive(via, to);
	}
}

void printRouteTrace(int from, int to) {
	routeTrace.clear();

	routeTrace.push_back(from);
	_printRouteTraceRecursive(from, to);
	routeTrace.push_back(to);
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> nodesCount >> edgesCount;

	int from, to, cost;
	for (int i = 0; i < edgesCount; i++) {
		cin >> from >> to >> cost;

		if (nodes[from][to] != 0 && nodes[from][to] < cost) continue;

		nodes[from][to] = cost;
		routes[from][to] = to;
	}

	calculateAllDistances();

	for (int from = 1; from <= nodesCount; from++) {
		for (int to = 1; to <= nodesCount; to++) {
			cout << nodes[from][to] << " ";
		}
		cout << "\n";
	}

	for (int from = 1; from <= nodesCount; from++) {
		for (int to = 1; to <= nodesCount; to++) {
			if (nodes[from][to] == 0) {
				cout << 0 << "\n";
				continue;
			}

			printRouteTrace(from, to);

			cout << routeTrace.size() << " ";

			for (int node : routeTrace) {
				cout << node << " ";
			}
			cout << "\n";
		}
	}
}