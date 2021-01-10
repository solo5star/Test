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
	int parent;
	int left;
	int right;
	int x;
} node;

node nodes[10001];

int maxLevel = 1;
struct { int min; int max; int width; } levels[10001];

int x_acc = 1;

void walk(int id, int level = 1) {
	if (nodes[id].left) walk(nodes[id].left, level + 1);

	int x = x_acc++;

	nodes[id].x = x;

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

int getRoot() {
	node current = nodes[1];

	while (current.parent) {
		current = nodes[current.parent];
	}

	return current.id;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int n, id, left, right;
	cin >> n;

	for (int i = 0; i < n; i++) {
		cin >> id >> left >> right;

		nodes[id].id = id;

		if (left != -1) {
			nodes[id].left = left;
			nodes[left].parent = id;
		}
		if (right != -1) {
			nodes[id].right = right;
			nodes[right].parent = id;
		}
	}

	walk(getRoot());

	cout << maxLevel << " " << levels[maxLevel].width;
}