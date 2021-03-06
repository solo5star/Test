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

typedef unsigned long long uint_64;

const uint_64 MOD_BY = 1000000007;

uint_64 tree[2097152];
uint_64 nums[1000000];
int length;

uint_64 _init(int node, int start, int end) {
	if (start == end) return tree[node] = nums[start];

	int mid = (start + end) / 2;

	return tree[node] = _init(node * 2, start, mid) * _init(node * 2 + 1, mid + 1, end) % MOD_BY;
}

void init() {
	_init(1, 0, length - 1);
}

uint_64 _update(int node, int start, int end, int index) {
	// out of bounds
	if (index < start || end < index) return tree[node];

	if (start == end) return tree[node] = nums[index];

	// in bounds
	int mid = (start + end) / 2;

	return tree[node] = _update(node * 2, start, mid, index) * _update(node * 2 + 1, mid + 1, end, index) % MOD_BY;
}

void update(int index, uint_64 value) {
	nums[index] = value;

	_update(1, 0, length - 1, index);
}

uint_64 _mul(int node, int start, int end, int left, int right) {
	// out of bounds
	if (start > right || end < left) return 1;

	if (left <= start && end <= right) return tree[node];

	int mid = (start + end) / 2;

	return _mul(node * 2, start, mid, left, right) * _mul(node * 2 + 1, mid + 1, end, left, right) % MOD_BY;
}

uint_64 mul(int from, int to) {
	return _mul(1, 0, length - 1, from, to);
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
	uint_64 a, b;
	k += m;
	while (k--) {
		cin >> op >> a >> b;

		if (op == 1) {
			update(a - 1, b);
		}
		else if (op == 2) {
			cout << mul(a - 1, b - 1) << "\n";
		}
	}
}