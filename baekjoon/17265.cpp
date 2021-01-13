#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <utility>
#include <algorithm>
#include <string>
#include <vector>
#include <math.h>
#include <queue>
#include <limits>

using namespace std;

typedef struct {
	int x;
	int y;
} point;

bool visited[5][5];
int map[5][5];
struct { int min; int max; } dp[5][5];
int width;

queue<point> q;

void add(int x, int y) {
	if (x < 0 || y < 0 || x >= width || y >= width) return;

	if (visited[y][x]) return;
	visited[y][x] = true;

	q.push({ x, y });
}

void propagate() {
	int n = q.size();

	while (n--) {
		point p = q.front();
		q.pop();

		add(p.x, p.y + 1);
		add(p.x + 1, p.y);
	}
}

int calc(int a, int op, int b) {
	switch (op) {
	case '*': return a * b;
	case '+': return a + b;
	case '-': return a - b;
	}
	// unexpected
	return 0;
}

void update(int x, int y) {
	if (x > 0 && y > 0) {
		dp[y][x].min = min(dp[y][x].min, calc(dp[y - 1][x - 1].min, map[y - 1][x], map[y][x]));
		dp[y][x].max = max(dp[y][x].max, calc(dp[y - 1][x - 1].max, map[y - 1][x], map[y][x]));
		dp[y][x].min = min(dp[y][x].min, calc(dp[y - 1][x - 1].min, map[y][x - 1], map[y][x]));
		dp[y][x].max = max(dp[y][x].max, calc(dp[y - 1][x - 1].max, map[y][x - 1], map[y][x]));
	}
	if (x > 1) {
		dp[y][x].min = min(dp[y][x].min, calc(dp[y][x - 2].min, map[y][x - 1], map[y][x]));
		dp[y][x].max = max(dp[y][x].max, calc(dp[y][x - 2].max, map[y][x - 1], map[y][x]));
	}
	if (y > 1) {
		dp[y][x].min = min(dp[y][x].min, calc(dp[y - 2][x].min, map[y - 1][x], map[y][x]));
		dp[y][x].max = max(dp[y][x].max, calc(dp[y - 2][x].max, map[y - 1][x], map[y][x]));
	}
}

void bfs() {
	dp[0][0].min = dp[0][0].max = map[0][0];

	q.push({ 0, 0 });
	propagate();

	while (!q.empty()) {
		propagate();

		int n = q.size();
		while (n--) {
			point p = q.front();
			q.pop();

			update(p.x, p.y);

			// cout << "CALC: " << p.x << "," << p.y << " => min=" << dp[p.y][p.x].min << ", max=" << dp[p.y][p.x].max << "\n";

			q.push(p);
		}

		propagate();
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	cin >> width;

	char c;
	bool isOp = false;
	for (int y = 0; y < width; y++) {
		for (int x = 0; x < width; x++) {
			if (isOp) {
				cin >> c;
				map[y][x] = c;
			}
			else {
				cin >> map[y][x];
			}
			isOp = !isOp;

			dp[y][x].min = INT_MAX;
			dp[y][x].max = INT_MIN;
		}
	}

	bfs();

	cout << dp[width - 1][width - 1].max << " " << dp[width - 1][width - 1].min;
}