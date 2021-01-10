#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <utility>
#include <algorithm>
#include <string>
#include <vector>
#include <math.h>
#include <cstring>
#include <queue>

using namespace std;

typedef struct { int x; int y; } point;

typedef struct { int x; int y; int distance; } location;

point locationOfBabyShark;

int width = 0;
int map[20][20];

int sizeOfBabyShark = 2;
int fishEaten = 0;
int fishRemain = 0;

int timeElapsed = 0;

// returns fish remains
bool eatFishAt(location p) {
	fishEaten++;
	locationOfBabyShark = { p.x, p.y };
	map[p.y][p.x] = 0;
	timeElapsed += p.distance;

	// UPGRADE BABY SHARK
	if (fishEaten == sizeOfBabyShark) {
		fishEaten = 0;
		sizeOfBabyShark++;
	}

#ifdef DEBUG
	cout << "\n";
	for (int _y = 0; _y < width; _y++) {
		for (int _x = 0; _x < width; _x++) {
			if (p.x == _x && p.y == _y) {
				cout << "* ";
			}
			else {
				cout << map[_y][_x] << " ";
			}
		}
		cout << "\n";
	}
	cout << "\n";
#endif

	fishRemain--;
	if (fishRemain == 0) return false;

	return true;
}

// returns can continue on
bool eatNext() {
	queue<location> q;

	bool visited[20][20] = { 0, };

	vector<location> availableFishes;
	int currentDistance = 0;

	q.push({
		locationOfBabyShark.x,
		locationOfBabyShark.y,
		0
	});

	while (!q.empty()) {
		int x = q.front().x;
		int y = q.front().y;
		int distance = q.front().distance;
		q.pop();

		if (!availableFishes.empty() && distance != currentDistance) {
			break;
		}
		currentDistance = distance;

		// CHECK OUT OF BOUNDS
		if (x < 0 || y < 0 || x >= width || y >= width) continue;

		// CHECK VISITED
		if (visited[y][x]) continue;
		visited[y][x] = true;

		// CHECK SIZE
		if (map[y][x] > sizeOfBabyShark) continue;

		if (map[y][x] != 0 && map[y][x] < sizeOfBabyShark) {
			availableFishes.push_back({ x, y, distance });
		}
		else {
			distance++;

			q.push({ x, y + 1, distance });
			q.push({ x, y - 1, distance });
			q.push({ x - 1, y, distance });
			q.push({ x + 1, y, distance });
		}
	}

	// DIDNT EAT FISH
	if (availableFishes.empty()) return false;

	location best = availableFishes[0];
	for (location p : availableFishes) {
		if (best.y > p.y) best = p;
		else if (best.y == p.y && best.x > p.x) best = p;
	}

	return eatFishAt(best);
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int n;

	cin >> width;
	for (int y = 0; y < width; y++) {
		for (int x = 0; x < width; x++) {
			cin >> n;

			if (n == 9) {
				locationOfBabyShark = { x, y };
			}
			else if (n != 0) {
				map[y][x] = n;

				fishRemain++;
			}
		}
	}

	while (eatNext());

	cout << timeElapsed;
}