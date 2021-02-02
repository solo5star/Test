#define _CRT_SECURE_NO_WARNINGS

#include <bits/stdc++.h>

using namespace std;

using point = struct {
	int x;
	int y;
	int time;
};

const int STONE = -1;
const int DEST = -2;
const int SRC = -3;

int board[50][50];
int height, width;

queue<point> waters;

void flood() {
	while (!waters.empty()) {
		point water = waters.front();
		waters.pop();

		// out of bound
		if (water.x < 0 || water.y < 0 || water.x >= width || water.y >= height) continue;

		// check can through (-1, -2, -3 is special tile)
		if (board[water.y][water.x] < 0) continue;

		// already flooded
		if (board[water.y][water.x] != 0 && board[water.y][water.x] <= water.time) continue;

		board[water.y][water.x] = water.time;

		water.time++;

		waters.push({ water.x + 1, water.y, water.time });
		waters.push({ water.x - 1, water.y, water.time });
		waters.push({ water.x, water.y + 1, water.time });
		waters.push({ water.x, water.y - 1, water.time });
	}
}

int findRoutes(point source) {
	queue<point> q;

	source.time = 1;
	q.push(source);

	while (!q.empty()) {
		point current = q.front();
		q.pop();

		// out of bound
		if (current.x < 0 || current.y < 0 || current.x >= width || current.y >= height) continue;

		// check can through
		if (board[current.y][current.x] == STONE) continue;

		// check is goal
		if (board[current.y][current.x] == DEST) return current.time - 1;

		// check current tile is flooded
		if (board[current.y][current.x] > 0 && current.time >= board[current.y][current.x]) continue;

		// use STONE instead of visited flag
		board[current.y][current.x] = STONE;

		current.time++;

		q.push({ current.x + 1, current.y, current.time });
		q.push({ current.x - 1, current.y, current.time });
		q.push({ current.x, current.y + 1, current.time });
		q.push({ current.x, current.y - 1, current.time });
	}
	return -1;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	cin >> height >> width;

	char tile;
	point source;

	for (int y = 0; y < height; y++) {
		for (int x = 0; x < width; x++) {
			cin >> tile;

			switch (tile) {
			case 'D': board[y][x] = DEST; break;
			case 'S': board[y][x] = SRC; source = { x, y }; break;
			case 'X': board[y][x] = STONE; break;
			case '*': waters.push({ x, y, 1 }); break;
			}
		}
	}

	flood();

	int cost = findRoutes(source);

	if (cost == -1) {
		cout << "KAKTUS";
	}
	else {
		cout << cost;
	}
}