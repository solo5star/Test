#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <utility>
#include <algorithm>
#include <string>
#include <math.h>
#include <queue>
#include <unordered_map>

using namespace std;

bool world[100][100];
bool visited[100][100];

queue<pair<int, int>> q;
bool complete = false;

int width;
int height;
int cost = 0;

bool canThrough(int x, int y) {
	if (x < 0 || y < 0 || x >= width || y >= height) {
		return false;
	}
	if (visited[y][x]) return false;

	return world[y][x];
}

void pushIfCanThrough(int x, int y) {
	if (!canThrough(x, y)) return;

	visited[y][x] = true;
	
	q.push(make_pair(x, y));
}

void bfs(int x, int y) {
	if (x == width - 1 && y == height - 1) {
		complete = true;
		return;
	}

	pushIfCanThrough(x - 1, y);
	pushIfCanThrough(x + 1, y);
	pushIfCanThrough(x, y - 1);
	pushIfCanThrough(x, y + 1);
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int n, m;
	cin >> n >> m;

	width = m;
	height = n;

	string line;
	for (int i = 0; i < n; i++) {
		cin >> line;
		for (int j = 0; j < m; j++) {
			world[i][j] = line[j] == '1';
		}
	}

	pushIfCanThrough(0, 0);

	while (!complete) {
		int len = q.size();
		if (len == 0) break;

		for (int i = 0; i < len; i++) {
			auto xy = q.front();
			q.pop();

			bfs(xy.first, xy.second);
		}
		cost++;
	}

	cout << cost;
}