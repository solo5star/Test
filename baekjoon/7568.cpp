#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <utility>
#include <algorithm>
#include <math.h>

using namespace std;

pair<int, int> points[100001];

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

	for (int i = 0; i < n; i++) {
		int rank = 1;
		for (int j = 0; j < n; j++) {
			if (points[i].first < points[j].first
				&& points[i].second < points[j].second) {
				rank++;
			}
		}
		cout << rank << " ";
	}
}