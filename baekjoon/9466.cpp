#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <utility>
#include <algorithm>
#include <string>
#include <math.h>
#include <queue>
#include <unordered_map>

using namespace std;

int stu[100001];
bool checked[100001];
bool cyclics[100001];

int cycles = 0;

bool DEBUG = false;

void dfs(int n) {
	int next = n;
	int cyclicN;
	bool detectCyclic = false;

	if(DEBUG) cout << "DFS: " << n;

	while (true) {
		// check cyclic !!!
		if (!detectCyclic && checked[next]) {
			detectCyclic = true;
			cyclicN = next;
			if (DEBUG) cout << " (Cyclic)";
		}

		checked[next] = true;
		next = stu[next];

		// if next is already cyclic (checked once), no more search
		if (cyclics[next]) break;

		if (DEBUG) cout << " -> " << next;

		if (detectCyclic) {
			cyclics[next] = true;
			cycles++;

			// end cycle!
			if (next == cyclicN) {
				if (DEBUG) cout << " -> " << next << " END\n";
				break;
			}
		}
	}
	if (DEBUG) cout << "\n";
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int t, n;
	cin >> t;
	for (int i = 0; i < t; i++) {
		cycles = 0;

		cin >> n;
		for (int j = 1; j <= n; j++) {
			cin >> stu[j];
			checked[j] = false;
			cyclics[j] = false;
		}

		for (int j = 1; j <= n; j++) {
			if (checked[j]) continue;

			dfs(j);
		}

		cout << n - cycles << "\n";

		for (int j = 1; j <= n; j++) {
			if (cyclics[j]) {
				if (DEBUG) cout << j << " ";
			}
		}
	}
}