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
bool occupation[10][10];
int width;

vector<point> points;

bool oddMode = true;

int maxCount = 0;

void dfs(int i = 0, int count = 0) {
	if (i >= points.size()) return;

	point& p = points[i];

	if ((p.x + p.y) % 2 == (oddMode ? 1 : 0)) return;

	point edges[4] = {
		{ p.x - abs(p.x - p.y), p.y - abs(p.x - p.y) },
		{ min(p.x + p.y, width - 1), (p.x + p.y) % (width - 1) }
	};
	edges[2] = { edges[0].y, edges[0].x };
	edges[3] = { edges[1].y, edges[1].x };

	for (int i = 0; i < 4; i++) {
		if (occupation[edges[i].y][edges[i].x]) return;
	}

	for (int i = 0; i < 4; i++) {
		occupation[edges[i].y][edges[i].x] = true;
	}

	count++;
	maxCount = max(maxCount, count);

	for (i++; i < points.size(); i++) {
		dfs(i, count);
	}

	for (int i = 0; i < 4; i++) {
		occupation[edges[i].y][edges[i].x] = false;
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	cin >> width;
	for (int y = 0; y < width; y++) {
		for (int x = 0; x < width; x++) {
			cin >> map[y][x];
			//map[y][x] = 1;

			if (map[y][x] == 1) points.push_back({ x, y });
		}
	}

	int sum = 0;

	oddMode = true;
	for(int i = 0; i < points.size(); i++) dfs(i);
	sum += maxCount;

	maxCount = 0;
	oddMode = false;
	for (int i = 0; i < points.size(); i++) dfs(i);
	sum += maxCount;

	cout << sum;
}