#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <utility>
#include <algorithm>
#include <queue>
#include <math.h>

using namespace std;

typedef pair<int, int> point;

point nums[100000];

bool compare(const point& a, const point& b) {
	if (a.first != b.first) {
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
		nums[i] = make_pair(x, y);
	}

	sort(nums, nums + n, compare);

	for (int i = 0; i < n; i++) {
		cout << nums[i].first << " " << nums[i].second << "\n";
	}
}