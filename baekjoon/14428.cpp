#define _CRT_SECURE_NO_WARNINGS

#include <bits/stdc++.h>

using namespace std;

typedef struct {
	int index;
	int value;
} data_t;

data_t tree[262144];
int arr[100000];
int length;

inline data_t getValue(int index) {
	return { index, arr[index] };
}

data_t merge(const data_t& a, const data_t& b) {
	if (a.value == b.value) {
		if (a.index < b.index) return { a.index, a.value };
		else return { b.index, b.value };
	}

	if (a.value < b.value) return { a.index, a.value };
	else return { b.index, b.value };
}

inline data_t outOfRange() {
	return { -1, INT_MAX };
}

data_t _init(int node, int left, int right) {
	if (left == right) return tree[node] = getValue(left);

	int mid = (left + right) / 2;

	return tree[node] = merge(_init(node * 2, left, mid), _init(node * 2 + 1, mid + 1, right));
}

void init() {
	_init(1, 0, length - 1);
}

data_t _update(int node, int left, int right, int index) {
	// if out of range, return value without update
	if (index < left || right < index) return tree[node];

	// update
	if (left == right) return tree[node] = getValue(index);

	int mid = (left + right) / 2;

	return tree[node] = merge(_update(node * 2, left, mid, index), _update(node * 2 + 1, mid + 1, right, index));
}

void update(int index, int value) {
	arr[index] = value;

	_update(1, 0, length - 1, index);
}

data_t _query(int node, int left, int right, int start, int end) {
	if (end < left || right < start) return outOfRange();

	if (start <= left && right <= end) return tree[node];

	int mid = (left + right) / 2;

	return merge(_query(node * 2, left, mid, start, end), _query(node * 2 + 1, mid + 1, right, start, end));
}

data_t query(int start, int end) {
	return _query(1, 0, length - 1, start, end);
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	cin >> length;
	for (int i = 0; i < length; i++) {
		cin >> arr[i];
	}

	init();

	int queries, operation, op1, op2;
	cin >> queries;

	for (int i = 0; i < queries; i++) {
		cin >> operation >> op1 >> op2;

		if (operation == 1) {
			op1--;

			update(op1, op2);
		}
		else if (operation == 2) {
			op1--; op2--;
			cout << query(op1, op2).index + 1 << "\n";
		}
	}
}