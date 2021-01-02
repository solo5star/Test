#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <utility>
#include <algorithm>
#include <math.h>
#include <queue>

using namespace std;

char map[20][20];
int width, height;

bool alphabets[255];

int best = 0;

int append(int mask, char alphabet) {
	return mask |= 1 << (alphabet - 'A');
}

int remove(int mask, char alphabet) {
	return mask &= ~(1 << (alphabet - 'A'));
}

int contains(int mask, char alphabet) {
	return mask & (1 << (alphabet - 'A'));
}

void printMask(int mask) {
	int i = 0;
	while (mask) {
		if (mask & 1) cout << (char)('A' + i);

		mask >>= 1;
		i++;
	}
}

void dfs(int x, int y, int depth = 0, int mask = 0) {
	if (x < 0 || x >= width || y < 0 || y >= height || contains(mask, map[y][x])) {
		if (depth > best) {
			// cout << "NEW BEST RECORD (depth=" << depth << "): ";
			// printMask(mask);
			// cout << "\n";
			best = depth;
		}
		return;
	}

	depth++;
	mask = append(mask, map[y][x]);

	dfs(x - 1, y, depth, mask);
	dfs(x + 1, y, depth, mask);
	dfs(x, y - 1, depth, mask);
	dfs(x, y + 1, depth, mask);
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> height >> width;

	for (int y = 0; y < height; y++) {
		for (int x = 0; x < width; x++) {
			cin >> map[y][x];
		}
	}

	dfs(0, 0);
	cout << best;
}