#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <utility>
#include <algorithm>
#include <string>
#include <vector>
#include <math.h>
#include <queue>
#include <stack>
#include <limits.h>

using namespace std;

typedef struct {
	int x; int y;
} point;

int map[10][10];
int width;

vector<point> points;
vector<point> bishops;

int maxCount = 0;

void dfs(int i = 0, int count = 0) {
	if (i >= points.size()) return;

	point& p = points[i];

	for (point& b : bishops) {
		if (abs(p.x - b.x) == abs(p.y - b.y)) return;
	}

	bishops.push_back(p);

	count++;
	maxCount = max(maxCount, count);

	for (i++; i < points.size(); i++) {
		dfs(i, count);
	}

	bishops.pop_back();
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	cin >> width;
	for (int y = 0; y < width; y++) {
		for (int x = 0; x < width; x++) {
			cin >> map[y][x];

			if (map[y][x] == 1) points.push_back({ x, y });
		}
	}

	dfs();

	cout << maxCount;
}