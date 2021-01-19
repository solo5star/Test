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

int map[1000][1000];
int width, height;

typedef struct {
	int x;
	int y;
	int chance;
	int distance;
} state;

queue<state> q;

bool visited[2][1000][1000];

void push(state s) {
	if (s.x < 0 || s.y < 0 || s.x >= width || s.y >= height) return;

	if (visited[s.chance][s.y][s.x]) return;
	visited[s.chance][s.y][s.x] = true;

	q.push(s);
}

int getShortestPath(int x, int y, int chance) {
	q.push({ x, y, chance, 0 });

	int minDistance = -1;

	while (!q.empty()) {
		state s = q.front();
		q.pop();

		s.distance++;

		if (map[s.y][s.x] == 1) {
			// can't break the wall
			if (s.chance == 0) continue;

			s.chance--;
		}

		// goal
		if (s.x == width - 1 && s.y == height - 1) {
			minDistance = s.distance;
			break;
		}

		push({ s.x - 1, s.y, s.chance, s.distance });
		push({ s.x + 1, s.y, s.chance, s.distance });
		push({ s.x, s.y - 1, s.chance, s.distance });
		push({ s.x, s.y + 1, s.chance, s.distance });
	}

	return minDistance;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	cin >> height >> width;

	char ch;
	for (int y = 0; y < height; y++) {
		for (int x = 0; x < width; x++) {
			cin >> ch;

			map[y][x] = ch - '0';
		}
	}

	cout << getShortestPath(0, 0, 1);
}