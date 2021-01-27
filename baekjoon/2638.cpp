#define _CRT_SECURE_NO_WARNINGS

#include <bits/stdc++.h>

using namespace std;

typedef struct {
	int x;
	int y;
} point;

const int AIR_SAFE = 0;
const int CHEESE = 1;
const int AIR = 2;

int board[100][100];
int refsByAir[100][100];
int width, height;

int cheeseCount;

queue<point> airs;

void floodfillSafeAirToAir(int x, int y) {
	queue<point> q;

	q.push({ x, y });

	// floodfill
	while (!q.empty()) {
		point p = q.front();
		q.pop();

		if (p.x < 0 || p.y < 0 || p.x >= width || p.y >= height) continue;

		if (board[p.y][p.x] != AIR_SAFE) continue;
		board[p.y][p.x] = AIR;

		airs.push(p);
		
		q.push({ p.x - 1, p.y });
		q.push({ p.x + 1, p.y });
		q.push({ p.x, p.y - 1 });
		q.push({ p.x, p.y + 1 });
	}
}

void increaseRef(int x, int y) {
	if (x < 0 || y < 0 || x >= width || y >= height) return;

	// if already meltdown, do not process about
	if (board[y][x] != CHEESE) return;

	refsByAir[y][x]++;

	if (refsByAir[y][x] >= 2) {
		cheeseCount--;
		board[y][x] = AIR_SAFE;

		floodfillSafeAirToAir(x, y);
	}
}

void processMeltdown() {
	int currentAirs = airs.size();

	while (currentAirs--) {
		point p = airs.front();
		airs.pop();

		increaseRef(p.x - 1, p.y);
		increaseRef(p.x + 1, p.y);
		increaseRef(p.x, p.y - 1);
		increaseRef(p.x, p.y + 1);
	}
}

void print() {
#ifdef DEBUG
	cout << "\n";
	for (int y = 0; y < height; y++) {
		for (int x = 0; x < width; x++) {
			cout << board[y][x] << " ";
		}
		cout << "\n";
	}
#endif
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	cin >> height >> width;

	for (int y = 0; y < height; y++) {
		for (int x = 0; x < width; x++) {
			cin >> board[y][x];

			if (board[y][x] == CHEESE) cheeseCount++;
		}
	}

	floodfillSafeAirToAir(0, 0);

	int hoursElapsed = 0;
	while (cheeseCount) {
		processMeltdown();
		hoursElapsed++;

		print();
	}

	cout << hoursElapsed;
}