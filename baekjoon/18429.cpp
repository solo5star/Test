#define _CRT_SECURE_NO_WARNINGS

#include <bits/stdc++.h>

using namespace std;

int decreasingAmount;

vector<int> weights;

bool visited[8];

int cases = 0;

void dfs(int i = 0, int currentAmount = 0, int depth = 0) {
	if (depth == 0) {
		for (int j = 0; j < weights.size(); j++) {
			dfs(j, 0, depth + 1);
		}
		return;
	}

	if (depth == weights.size()) {
		cases++;
		return;
	}

	currentAmount += weights[i] - decreasingAmount;
	if (currentAmount < 0) return;

	visited[i] = true;

	for (int j = 0; j < weights.size(); j++) {
		if (visited[j]) continue;

		dfs(j, currentAmount, depth + 1);
	}

	visited[i] = false;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	int n, weight;
	cin >> n >> decreasingAmount;

	for (int i = 0; i < n; i++) {
		cin >> weight;

		weights.push_back(weight);
	}

	dfs();

	cout << cases;
}