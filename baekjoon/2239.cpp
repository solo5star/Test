#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <utility>
#include <algorithm>
#include <string>
#include <vector>
#include <math.h>

using namespace std;

int map[9][9];
bool horizontal[9][10];
bool vertical[9][10];
bool square[3][3][10];

struct { int x; int y; } blanks[81];
int blanksCount = 0;

bool canAdd(int x, int y, int n) {
	return !(horizontal[y][n] || vertical[x][n] || square[y / 3][x / 3][n]);
}

void add(int x, int y, int n) {
	map[y][x] = n;
	horizontal[y][n] = true;
	vertical[x][n] = true;
	square[y / 3][x / 3][n] = true;
}

void remove(int x, int y, int n) {
	map[y][x] = 0;
	horizontal[y][n] = false;
	vertical[x][n] = false;
	square[y / 3][x / 3][n] = false;
}

bool dfs(int i = 0) {
	if (i == blanksCount) return true;

	int x = blanks[i].x;
	int y = blanks[i].y;

	for (int n = 1; n <= 9; n++) {
		if (!canAdd(x, y, n)) continue;

		add(x, y, n);
		
		if (dfs(i + 1)) return true;

		remove(x, y, n);
	}
	return false;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	char c;
	for (int y = 0; y < 9; y++) {
		for (int x = 0; x < 9; x++) {
			cin >> c;
			c -= '0';
			if (c == 0) {
				blanks[blanksCount++] = { x, y };
			}
			else {
				add(x, y, c);
			}
		}
	}

	dfs();

	for (int y = 0; y < 9; y++) {
		for (int x = 0; x < 9; x++) {
			cout << map[y][x];
		}
		cout << "\n";
	}
}