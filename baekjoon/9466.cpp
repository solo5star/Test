#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <utility>
#include <algorithm>
#include <string>
#include <math.h>
#include <queue>
#include <unordered_map>
#include <set>

using namespace std;

unordered_map<int, int> students;
set<int> checked;
set<int> cyclics;

int cycles = 0;

bool DEBUG = false;

void dfs(int n) {
	int next = n;
	int cyclicN;
	bool detectCyclic = false;

	if(DEBUG) cout << "DFS: " << n;

	while (true) {
		// check cyclic !!!
		if (!detectCyclic && checked.count(next)) {
			detectCyclic = true;
			cyclicN = next;
			if (DEBUG) cout << " (Cyclic)";
		}

		checked.insert(next);
		next = students[next];

		// if next is already cyclic (checked once), no more search
		if (cyclics.count(next)) break;

		if (DEBUG) cout << " -> " << next;

		if (detectCyclic) {
			cyclics.insert(next);
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

	int t, n, s;
	cin >> t;
	for (int i = 0; i < t; i++) {
		cycles = 0;

		cin >> n;
		for (int j = 1; j <= n; j++) {
			cin >> s;
			students[j] = s;
		}

		for (int j = 1; j <= n; j++) {
			if (checked.count(j)) continue;

			dfs(j);
		}

		cout << n - cycles << "\n";

		checked.clear();
		cyclics.clear();

		if (DEBUG) for (int j = 1; j <= n; j++) {
			if (cyclics.count(j)) {
				cout << j << " ";
			}
		}
	}
}