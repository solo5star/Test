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

typedef struct {
	int x;
	int y;
} point;

int map[25][25];
int width;

int floodfill(int x, int y) {
	queue<point> q;

	q.push({ x, y });

	int count = 0;
	while (!q.empty()) {
		point p = q.front();
		q.pop();

		int x = p.x;
		int y = p.y;

		if (x < 0 || x >= width || y < 0 || y >= width) continue;

		if (map[y][x] == 0) continue;

		map[y][x] = 0;
		count++;

		q.push({ x - 1, y });
		q.push({ x + 1, y });
		q.push({ x, y - 1 });
		q.push({ x, y + 1 });
	}

	return count;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	cin >> width;
	
	char ch;
	for (int y = 0; y < width; y++) {
		for (int x = 0; x < width; x++) {
			cin >> ch;

			map[y][x] = ch - '0';
		}
	}

	vector<int> houses;
	for (int y = 0; y < width; y++) {
		for (int x = 0; x < width; x++) {
			if (map[y][x] == 1) houses.push_back(floodfill(x, y));
		}
	}

	sort(houses.begin(), houses.end());

	cout << houses.size() << "\n";

	for (int n : houses) {
		cout << n << "\n";
	}
}