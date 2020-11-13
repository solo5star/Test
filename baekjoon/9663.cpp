#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <utility>
#include <algorithm>
#include <math.h>

using namespace std;

int n;
int ans = 0;
int rows[15];

bool isPossible(int level) {
	for (int i = 0; i < level; i++) {
		if (
			// 같은 라인에 있는지
			rows[level] == rows[i]
			// 아니면 대각선에 있는지
			|| abs(i - level) == abs(rows[i] - rows[level])
			) {
			return false;
		}
	}
	return true;
}

void dfs(int level) {
	if (level == n) {
		ans++;
		return;
	}

	for (int i = 0; i < n; i++) {
		rows[level] = i;
		if (isPossible(level)) {
			dfs(level + 1);
		}
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> n;

	dfs(0);

	cout << ans;
}