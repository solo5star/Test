#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <utility>
#include <algorithm>
#include <math.h>

using namespace std;

pair<int, int> points[100001];

bool compare(const pair<int, int> a, const pair<int, int> b) {
	if (a.second == b.second) {
		return a.first < b.first;
	}

	return a.second < b.second;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int n, x, y;
	cin >> n;

	for (int i = 0; i < n; i++) {
		cin >> x >> y;
		points[i] = make_pair(x, y);
	}

	sort(points, points + n, compare);

	for (int i = 0; i < n; i++) {
		cout << points[i].first << " " << points[i].second << "\n";
	}
}