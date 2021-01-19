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

int tree[262144];
int nums[100000];
int length;

int _init(int node, int start, int end) {
	if (start == end) return tree[node] = nums[start];

	int mid = (start + end) / 2;

	return tree[node] = _init(node * 2, start, mid) + _init(node * 2 + 1, mid + 1, end);
}

void init() {
	_init(1, 0, length - 1);
}

void update(int node, int start, int end, int index, int diff) {
	if (index < start || index > end) return;

	// update diff
	tree[node] += diff;

	if (start == end) return;

	int mid = (start + end) / 2;

	update(node * 2, start, mid, index, diff);
	update(node * 2 + 1, mid + 1, end, index, diff);
}

int _sum(int node, int start, int end, int left, int right) {
	// out of range
	if (left > end || right < start) return 0;

	// include completely
	if (left <= start && end <= right) return tree[node];

	int mid = (start + end) / 2;

	return _sum(node * 2, start, mid, left, right) + _sum(node * 2 + 1, mid + 1, end, left, right);
}

int sum(int from, int to) {
	return _sum(1, 0, length - 1, from, to);
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	int m;
	cin >> length >> m;

	for (int i = 0; i < length; i++) {
		cin >> nums[i];
	}

	init();

	int from, to;
	for (int i = 0; i < m; i++) {
		cin >> from >> to;

		cout << sum(from - 1, to - 1) << "\n";
	}
}