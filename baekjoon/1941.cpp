#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <utility>
#include <algorithm>
#include <string>
#include <math.h>

using namespace std;

const char S = 'S';
const char Y = 'Y';

struct { char value; bool visited; } map[5][5];

int share[255];
int result = 0;

inline bool isAdjacent(int x, int y) {
	return (x != 0 && map[y][x - 1].visited)
		|| (y != 0 && map[y - 1][x].visited)
		|| (x != 4 && map[y][x + 1].visited)
		|| (y != 4 && map[y + 1][x].visited);
}

void dfs(int x = 0, int y = 0, int depth = 1) {
	// CHECK: OUT OF BOUNDS
	// CHECK: VISITED
	if (x < 0 || y < 0 || x >= 5 || y >= 5 || map[y][x].visited) return;

	map[y][x].visited = true;
	share[map[y][x].value]++;

	// STACK START
	if (share[Y] < 4) {
		if (depth == 7) {
			result++;

#ifdef DEBUG
			cout << "FOUND AT=" << x << ", " << y << ". TRACE MAP:\n";

			for (int _y = 0; _y < 5; _y++) {
				for (int _x = 0; _x < 5; _x++) {
					cout << (map[_y][_x].visited ? map[_y][_x].value : '*');
				}
				cout << "\n";
			}
			cout << "\n";
#endif
		}
		else {
			for (int _x = x + 1; _x < 5; _x++) {
				if (isAdjacent(_x, y)) dfs(_x, y, depth + 1);
			}
			for (int _y = y + 1; _y < 5; _y++) {
				for (int _x = 0; _x < 5; _x++) {
					if(isAdjacent(_x, _y)) dfs(_x, _y, depth + 1);
				}
			}
		}
	}
	// STACK END

	map[y][x].visited = false;
	share[map[y][x].value]--;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	for (int y = 0; y < 5; y++) {
		for (int x = 0; x < 5; x++) {
			cin >> map[y][x].value;
		}
	}

	for (int y = 0; y < 5; y++) {
		for (int x = 0; x < 5; x++) {
			dfs(x, y);
		}
	}

	cout << result;
}