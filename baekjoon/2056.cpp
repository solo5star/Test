#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <utility>
#include <algorithm>
#include <string>
#include <vector>
#include <math.h>
#include <queue>
#include <sstream>

using namespace std;

int costs[10001];


int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	string line;

	int n, node, cost;
	cin >> n;

	// clear buffer
	getline(cin, line);

	for (int i = 1; i <= n; i++) {
		getline(cin, line);

		istringstream iss(line);

		iss >> cost;

		int requiredCost = 0;

		while (!iss.eof()) {
			iss >> node;

			if (node == 0) continue;

			requiredCost = max(requiredCost, costs[node]);
		}

		costs[i] = cost + requiredCost;
	}

	cout << costs[n];
}