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

char map[250][250];
int width, height;
bool visited[250][250];

int sheep = 0;
int wolf = 0;

queue<point> q;

void floodfill(point p) {
	q.push(p);

	int _sheep = 0;
	int _wolf = 0;

	while (!q.empty()) {
		point p = q.front();
		q.pop();

		if (p.x < 0 || p.y < 0 || p.x >= width || p.y >= height) continue;
		if (visited[p.y][p.x]) continue;
		visited[p.y][p.x] = true;

		if (map[p.y][p.x] == '#') continue;

		if (map[p.y][p.x] == 'o') _sheep++;
		else if (map[p.y][p.x] == 'v') _wolf++;

		q.push({ p.x + 1, p.y });
		q.push({ p.x - 1, p.y });
		q.push({ p.x, p.y + 1 });
		q.push({ p.x, p.y - 1 });
	}

	if (_sheep > _wolf) {
		sheep += _sheep;
	}
	else {
		wolf += _wolf;
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	cin >> height >> width;

	for (int y = 0; y < height; y++) {
		for (int x = 0; x < width; x++) {
			cin >> map[y][x];
		}
	}

	for (int y = 0; y < height; y++) {
		for (int x = 0; x < width; x++) {
			if (!visited[y][x]) floodfill({ x, y });
		}
	}

	cout << sheep << " " << wolf;
}