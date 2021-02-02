#define _CRT_SECURE_NO_WARNINGS

#include <bits/stdc++.h>

using namespace std;

using point = struct {
	int x;
	int y;
};

const int STONE = -1;
const int DEST = -2;
const int SRC = -3;

int board[50][50];
int height, width;

void flood(vector<point>& waters) {
	// water, time
	queue<pair<point, int>> q;

	for (point& water : waters) {
		q.push({ water, 1 });
	}

	while (!q.empty()) {
		point water = q.front().first;
		int elapsedTime = q.front().second;
		q.pop();

		// out of bound
		if (water.x < 0 || water.y < 0 || water.x >= width || water.y >= height) continue;

		// check can through (-1, -2, -3 is special tile)
		if (board[water.y][water.x] < 0) continue;

		// already flooded
		if (board[water.y][water.x] != 0 && board[water.y][water.x] < elapsedTime) continue;

		board[water.y][water.x] = elapsedTime;

		q.push({ { water.x + 1, water.y }, elapsedTime + 1 });
		q.push({ { water.x - 1, water.y }, elapsedTime + 1 });
		q.push({ { water.x, water.y + 1 }, elapsedTime + 1 });
		q.push({ { water.x, water.y - 1 }, elapsedTime + 1 });
	}
}

int findRoutes(point source) {
	queue<pair<point, int>> q;

	q.push({ source, 0 });

	while (!q.empty()) {
		point current = q.front().first;
		int elapsedTime = q.front().second;
		q.pop();

		// out of bound
		if (current.x < 0 || current.y < 0 || current.x >= width || current.y >= height) continue;

		// check can through
		if (board[current.y][current.x] == STONE) continue;

		// check is goal
		if (board[current.y][current.x] == DEST) return elapsedTime;

		// check if flooded
		if (board[current.y][current.x] >= 0 && elapsedTime + 1 >= board[current.y][current.x]) continue;

		// use STONE instead of visited flag
		board[current.y][current.x] = STONE;

		q.push({ { current.x + 1, current.y }, elapsedTime + 1 });
		q.push({ { current.x - 1, current.y }, elapsedTime + 1 });
		q.push({ { current.x, current.y + 1 }, elapsedTime + 1 });
		q.push({ { current.x, current.y - 1 }, elapsedTime + 1 });
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
	vector<point> waters;

	for (int y = 0; y < height; y++) {
		for (int x = 0; x < width; x++) {
			cin >> tile;

			switch (tile) {
			case 'D': board[y][x] = DEST; break;
			case 'S': board[y][x] = SRC; source = { x, y }; break;
			case 'X': board[y][x] = STONE; break;
			case '*': waters.push_back({ x, y }); break;
			}
		}
	}

	flood(waters);

	int cost = findRoutes(source);

	if (cost == -1) {
		cout << "KAKTUS";
	}
	else {
		cout << cost;
	}
}