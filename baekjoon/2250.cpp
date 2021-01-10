#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <utility>
#include <algorithm>
#include <string>
#include <vector>
#include <math.h>
#include <cstring>

using namespace std;

typedef struct {
	int id;
	int left;
	int right;
	int x, y;
} node;

node nodes[10001];

int maxLevel = 1;
struct { int min; int max; int width; } levels[10001];

int x_acc = 1;

void walk(int id = 1, int level = 1) {
	if (nodes[id].left) walk(nodes[id].left, level + 1);

	int x = x_acc++;

	nodes[id].x = x;
	nodes[id].y = level;

	// UPDATE LEVEL's MIN/MAX
	if (levels[level].min == 0 || x < levels[level].min) levels[level].min = x;
	if (levels[level].max == 0 || levels[level].max < x) levels[level].max = x;

	// UPDATE LEVEL's WIDTH
	if (levels[level].min && levels[level].max) {
		levels[level].width = levels[level].max - levels[level].min + 1;
	}
	else {
		levels[level].width = 1;
	}

	// UPDATE MAXIMUM LEVEL
	if (levels[maxLevel].width == levels[level].width && level < maxLevel) {
		maxLevel = level;
	}
	if (levels[maxLevel].width < levels[level].width) {
		maxLevel = level;
	}

	if (nodes[id].right) walk(nodes[id].right, level + 1);
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int n, id, left, right;
	cin >> n;

	for (int i = 0; i < n; i++) {
		cin >> id >> left >> right;

		nodes[id].left = left == -1 ? 0 : left;
		nodes[id].right = right == -1 ? 0 : right;
	}

	walk();

	cout << maxLevel << " " << levels[maxLevel].width;
}