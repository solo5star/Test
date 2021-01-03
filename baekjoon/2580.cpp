#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <utility>
#include <algorithm>
#include <math.h>

using namespace std;

int mask_rows[9];
int mask_cols[9];
int mask_block[3][3];

int map[9][9];

struct {
	int x;
	int y;
} blanks[81];

int blankCount = 0;

int mask_add(int mask, int n) {
	return mask | 1 << n;
}

int mask_remove(int mask, int n) {
	return mask & ~(1 << n);
}

int mask_contains(int mask, int n) {
	return mask & (1 << n);
}

bool fitAt(int x, int y, int value) {
	return !mask_contains(mask_rows[y], value)
		&& !mask_contains(mask_cols[x], value)
		&& !mask_contains(mask_block[y / 3][x / 3], value);
}

void add(int x, int y, int value) {
	mask_rows[y] = mask_add(mask_rows[y], value);
	mask_cols[x] = mask_add(mask_cols[x], value);
	mask_block[y / 3][x / 3] = mask_add(mask_block[y / 3][x / 3], value);
	map[y][x] = value;
}

void remove(int x, int y, int value) {
	mask_rows[y] = mask_remove(mask_rows[y], value);
	mask_cols[x] = mask_remove(mask_cols[x], value);
	mask_block[y / 3][x / 3] = mask_remove(mask_block[y / 3][x / 3], value);
	map[y][x] = 0;
}

bool dfs(int blankIndex) {
	if (blankIndex >= blankCount) return true;

	int x = blanks[blankIndex].x;
	int y = blanks[blankIndex].y;
	bool solved = false;

	for (int i = 1; i <= 9; i++) {
		if (fitAt(x, y, i)) {
			add(x, y, i);
			solved = dfs(blankIndex + 1);
			
			if (solved) break;

			remove(x, y, i);
		}
	}

	return solved;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int num;

	for (int y = 0; y < 9; y++) {
		for (int x = 0; x < 9; x++) {
			cin >> num;

			if (num > 0) {
				add(x, y, num);
			}
			else if (num == 0) {
				blanks[blankCount++] = { x, y };
			}
		}
	}

	dfs(0);

	for (int y = 0; y < 9; y++) {
		for (int x = 0; x < 9; x++) {
			cout << map[y][x] << (x == 8 ? "\n" : " ");
		}
	}
}