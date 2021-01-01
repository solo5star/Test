#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <utility>
#include <algorithm>
#include <math.h>
#include <queue>

using namespace std;

int map[1001][1001];
int width, height;
int remain = 0;

queue<pair<int, int>> q;

bool canGoThrough(int x, int y) {
	return x >= 0 && x < width&& y >= 0 && y < height&& map[y][x] == 0;
}

void push(int x, int y) {
	if (canGoThrough(x, y)) q.push(make_pair(x, y));
}

void propagate(int x, int y) {
	if (map[y][x] != 0) return;

	map[y][x] = 1;
	remain--;

	push(x - 1, y);
	push(x + 1, y);
	push(x, y - 1);
	push(x, y + 1);
}


void printMap() {
	// for (int y = 0; y < height; y++) {
	// 	for (int x = 0; x < width; x++) {
	// 		cout << map[y][x] << " ";
	// 	}
	// 	cout << "\n";
	// }
	// cout << "remain: " << remain << "\n";
	// cout << "\n";
}

void bfs() {
	int len = q.size();
	for (int i = 0; i < len; i++) {
		int x = q.front().first;
		int y = q.front().second;

		q.pop();

		propagate(x, y);
	}
	printMap();
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int block;
	cin >> width >> height;

	for (int y = 0; y < height; y++) {
		for (int x = 0; x < width; x++) {
			cin >> block;

			switch (block) {
			case 1:
				propagate(x, y);
			case 0:
				remain++;
				break;
			case -1:
				map[y][x] = -1;
				break;
			}
		}
	}

	int yearElapsed = 0;
	while (remain > 0) {
		bfs();
		yearElapsed++;

		if (q.empty()) break;
	}

	cout << (remain ? -1 : yearElapsed);
}