#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <utility>
#include <algorithm>
#include <string.h>
#include <math.h>

using namespace std;

typedef struct {
	int white;
	int blue;
} origami;

int map[128][128];

origami getOrigamiAt(int x, int y, int length) {
	origami result = { 0, 0 };

	if (length == 2) {
		for(int _y = y; _y < y+2; _y++)
			for (int _x = x; _x < x+2; _x++) {
				if (map[_y][_x] == 1) result.blue++;
				else if (map[_y][_x] == 0) result.white++;
			}
	}
	else {
		for (int i = 0; i < 2; i++) {
			for (int j = 0; j < 2; j++) {
				origami child = getOrigamiAt(x + i * (length / 2), y + j * (length / 2), length / 2);

				result.blue += child.blue;
				result.white += child.white;
			}
		}
	}

	if (result.blue == 0) result.white = 1;
	else if (result.white == 0) result.blue = 1;

	return result;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int n;
	cin >> n;

	for (int y = 0; y < n; y++) {
		for (int x = 0; x < n; x++) {
			cin >> map[y][x];
		}
	}

	origami result = getOrigamiAt(0, 0, n);

	cout << result.white << "\n" << result.blue;
}