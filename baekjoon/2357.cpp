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

typedef struct {
	int min;
	int max;
} data_t;

const data_t DATA_ERROR = { -1, -1 };

data_t tree[262144];
int nums[100000];
int length;

bool isError(data_t d) {
	return d.min == -1 && d.max == -1;
}

data_t merge(const data_t& a, const data_t& b) {
	return {
		min(a.min, b.min),
		max(a.max, b.max)
	};
}

data_t _init(int node, int start, int end) {
	if (start == end) return tree[node] = { nums[start], nums[start] };

	int mid = (start + end) / 2;
	return tree[node] = merge(_init(node * 2, start, mid), _init(node * 2 + 1, mid + 1, end));
}

void init() {
	_init(1, 0, length - 1);
}

data_t _update(int node, int start, int end, int index, data_t value) {
	if (index < start || end < index) return tree[node];

	if (start == end) return tree[node] = value;

	int mid = (start + end) / 2;
	return tree[node] = merge(_update(node * 2, start, mid, index, value), _update(node * 2 + 1, mid + 1, end, index, value));
}

//void update(int index, data_t value) {
//	nums[index] = value;
//
//	_update(1, 0, length - 1, index, value);
//}

data_t _range(int node, int start, int end, int left, int right) {
	if (end < left || right < start) return DATA_ERROR;

	if (left <= start && end <= right) return tree[node];

	int mid = (start + end) / 2;

	data_t a = _range(node * 2, start, mid, left, right);
	data_t b = _range(node * 2 + 1, mid + 1, end, left, right);

	if (isError(a)) return b;
	if (isError(b)) return a;

	return merge(a, b);
}

data_t range(int from, int to) {
	return _range(1, 0, length - 1, from, to);
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
	while (m--) {
		cin >> from >> to;

		data_t result = range(from - 1, to - 1);

		cout << result.min << " " << result.max << "\n";
	}
}