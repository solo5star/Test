#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <utility>
#include <algorithm>
#include <string.h>
#include <math.h>

using namespace std;


// fill 0 if student is successfully grouped
int students[100001];
int successfullyGrouped = 0;

bool visited[100001];

// Return given students are successfully grouped
bool dfs(int startStudent, int student = -1) {
	if (student == -1) student = startStudent;

	bool grouped = false;

	// Already grouped
	if (students[student] == 0) {
		grouped = false;
	}
	else if (visited[student]) {
		// Cyclic. Sr == S1
		if (student == startStudent) {
			grouped = true;
		}
		// Cyclic but not Sr == S1
		else {
			grouped = false;
		}
	}
	else {
		visited[student] = true;

		grouped = dfs(startStudent, students[student]);

		if (grouped) {
			students[student] = 0;
			successfullyGrouped++;
		}

		visited[student] = false;
	}

	return grouped;
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