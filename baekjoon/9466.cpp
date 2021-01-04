#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <utility>
#include <algorithm>
#include <string.h>
#include <math.h>

using namespace std;

// fill 0 if cyclic check is finished
int students[100001];
int successfullyGrouped = 0;

bool visited[100001];

// Return student > 0 if cyclic is detected.
// Return 0 if out of cycle.
int dfs(int student) {
	// Already grouped
	if (students[student] == 0) {
		return 0;
	}
	// Cycle detected
	else if (visited[student]) {
		return student;
	}
	else {
		visited[student] = true;

		int detectedCycle = dfs(students[student]);

		if (detectedCycle > 0) {
			successfullyGrouped++;
		}

		students[student] = 0;
		visited[student] = false;

		if (detectedCycle == student) return 0;

		return detectedCycle;
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int t, n;
	cin >> t;

	while (t--) {
		successfullyGrouped = 0;

		cin >> n;
		for (int i = 1; i <= n; i++) {
			cin >> students[i];
		}

		for (int i = 1; i <= n; i++) {
			dfs(i);
		}

		cout << (n - successfullyGrouped) << "\n";
	}
}