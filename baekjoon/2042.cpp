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

typedef long long int_64;

int_64 tree[2097152];
int_64 nums[1000000];
int length;

int_64 _init(int node, int start, int end) {
	if (start == end) return tree[node] = nums[start];

	int mid = (start + end) / 2;

	return tree[node] = _init(node * 2, start, mid) + _init(node * 2 + 1, mid + 1, end);
}

void init() {
	_init(1, 0, length - 1);
}

void _update(int node, int start, int end, int index, int_64 diff) {
	// out of bounds
	if (index < start || end < index) return;

	// in bounds
	tree[node] += diff;

	if (start == end) return;

	int mid = (start + end) / 2;

	_update(node * 2, start, mid, index, diff);
	_update(node * 2 + 1, mid + 1, end, index, diff);
}

void update(int index, int_64 value) {
	_update(1, 0, length - 1, index, value - nums[index]);
}

int_64 _sum(int node, int start, int end, int left, int right) {
	// out of bounds
	if (start > right || end < left) return 0;

	if (left <= start && end <= right) return tree[node];

	int mid = (start + end) / 2;

	return _sum(node * 2, start, mid, left, right) + _sum(node * 2 + 1, mid + 1, end, left, right);
}

int_64 sum(int from, int to) {
	return _sum(1, 0, length - 1, from, to);
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	int m, k;
	cin >> length >> m >> k;

	for (int i = 0; i < length; i++) {
		cin >> nums[i];
	}

	init();

	int op;
	int_64 a, b;
	k += m;
	while (k--) {
		cin >> op >> a >> b;

		if (op == 1) {
			update(a - 1, b);
		}
		else if (op == 2) {
			cout << sum(a - 1, b - 1) << "\n";
		}
	}
}