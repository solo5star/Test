#define _CRT_SECURE_NO_WARNINGS

#include <bits/stdc++.h>

using namespace std;

typedef struct {
	int x; int y;
} point;

int width;

vector<point> points;
vector<point> bishops;

int _dfs(bool odd, int i) {
	if (i >= points.size()) return 0;

	point& p = points[i];

	if ((p.x + p.y) % 2 == odd) return 0;

	for (point& b : bishops) {
		if (abs(p.x - b.x) == abs(p.y - b.y)) return 0;
	}

	bishops.push_back(p);
	
	int maxCount = bishops.size();

	for (i++; i < points.size(); i++) {
		maxCount = max(maxCount, _dfs(odd, i));
	}

	bishops.pop_back();

	return maxCount;
}

int dfs() {
	int sum = 0;

	int maxCount = 0;
	for (int i = 0; i < points.size(); i++) maxCount = max(maxCount, _dfs(true, i));
	sum += maxCount;

	maxCount = 0;
	for (int i = 0; i < points.size(); i++) maxCount = max(maxCount, _dfs(false, i));
	sum += maxCount;

	return sum;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	cin >> width;

	int canPlaceBishop;
	for (int y = 0; y < width; y++) {
		for (int x = 0; x < width; x++) {
			cin >> canPlaceBishop;

			if (canPlaceBishop) points.push_back({ x, y });
		}
	}

	cout << dfs();
}