#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <iomanip>
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
	int x;
	int y;
} point;

const char UP = 'U';
const char DOWN = 'D';
const char LEFT = 'L';
const char RIGHT = 'R';

char map[1000][1000];
int width, height;
bool visited[1000][1000];

queue<point> q;

void floodTo(point origin, point to, char direction) {
	if (to.x < 0 || to.x >= width || to.y < 0 || to.y >= height) return;

	if (visited[to.y][to.x]) return;

	if (
		map[origin.y][origin.x] == direction
		|| direction == UP && map[to.y][to.x] == DOWN
		|| direction == DOWN && map[to.y][to.x] == UP
		|| direction == RIGHT && map[to.y][to.x] == LEFT
		|| direction == LEFT && map[to.y][to.x] == RIGHT
	) {
		visited[to.y][to.x] = true;

		q.push(to);
	}
}

int floodfill(point origin) {
	if (visited[origin.y][origin.x]) return 0;

	q.push(origin);
	visited[origin.y][origin.x] = true;

	while (!q.empty()) {
		point p = q.front();
		q.pop();

		floodTo(p, { p.x, p.y + 1 }, DOWN);
		floodTo(p, { p.x, p.y - 1 }, UP);
		floodTo(p, { p.x + 1, p.y }, RIGHT);
		floodTo(p, { p.x - 1, p.y }, LEFT);
	}

	return 1;
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

	int safeZone = 0;
	for (int y = 0; y < height; y++) {
		for (int x = 0; x < width; x++) {
			safeZone += floodfill({ x, y });
		}
	}

	cout << safeZone;
}