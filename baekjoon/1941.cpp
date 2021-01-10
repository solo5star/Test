#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <utility>
#include <algorithm>
#include <string>
#include <math.h>
#include <queue>

using namespace std;

typedef struct { int x; int y; } point;

struct { char value; bool visited; } map[5][5];

int result = 0;

point points[25];

inline bool isAdjacent(point& p) {
	int x = p.x;
	int y = p.y;

	return (x > 0 && map[y][x - 1].visited)
		|| (x < 4 && map[y][x + 1].visited)
		|| (y > 0 && map[y - 1][x].visited)
		|| (y < 4 && map[y + 1][x].visited);
}

bool validate() {
	queue<point> q;

	for (int y = 0; y < 5; y++) {
		for (int x = 0; x < 5; x++) {
			if (map[y][x].visited) {
				q.push({ x, y });
				x = 5;
				y = 5;
			}
		}
	}

	int count = 0;
	bool checked[5][5];
	memset(checked, false, sizeof(checked));

	while (!q.empty()) {
		point p = q.front();
		q.pop();

		if (p.x < 0 || p.y < 0 || p.x > 4 || p.y > 4) continue;
		if (checked[p.y][p.x]) continue;
		checked[p.y][p.x] = true;

		if (map[p.y][p.x].visited) {
			count++;

			q.push({ p.x + 1, p.y });
			q.push({ p.x - 1, p.y });
			q.push({ p.x, p.y + 1 });
			q.push({ p.x, p.y - 1 });
		}
	}

	return count >= 7;
}

void dfs(int i, int depth = 1, int Y = 0) {
	int x = points[i].x;
	int y = points[i].y;

	map[y][x].visited = true;

	Y += map[y][x].value == 'Y';

	// STACK START
	if (Y < 4) {
		if (depth == 7) {
			if (validate()) {
				result++;

#ifdef DEBUG
				cout << "FOUND:\n";

				for (int _y = 0; _y < 5; _y++) {
					for (int _x = 0; _x < 5; _x++) {
						cout << (map[_y][_x].visited ? map[_y][_x].value : '*');
					}
					cout << "\n";
				}
				cout << "\n";
#endif
			}
		}
		else {
			for (int j = i + 1; j < 25; j++) {
				dfs(j, depth + 1, Y);
			}
		}
	}
	// STACK END

	map[y][x].visited = false;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int i = 0;
	for (int y = 0; y < 5; y++) {
		for (int x = 0; x < 5; x++) {
			cin >> map[y][x].value;

			points[i++] = { x, y };
		}
	}

	for (int i = 0; i < 25; i++) {
		dfs(i);
	}

	cout << result;
}