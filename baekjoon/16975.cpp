#define _CRT_SECURE_NO_WARNINGS

#include <bits/stdc++.h>

using namespace std;

typedef int data_t;

data_t tree[262144];
int arr[100000];
int length;

inline data_t getValue(int index) {
	return 0;
}

data_t merge(const data_t& a, const data_t& b) {
	return a + b;
}

inline data_t outOfRange() {
	return 0;
}

data_t _init(int node, int left, int right) {
	if (left == right) return tree[node] = getValue(left);

	int mid = (left + right) / 2;

	return tree[node] = merge(_init(node * 2, left, mid), _init(node * 2 + 1, mid + 1, right));
}

void init() {
	_init(1, 0, length - 1);
}

/*
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
*/

void _update(int node, int left, int right, int start, int end, int value) {
	if (end < left || right < start) return;

	if (start <= left && right <= end) {
		tree[node] += value;
		return;
	}

	int mid = (left + right) / 2;

	_update(node * 2, left, mid, start, end, value);
	_update(node * 2 + 1, mid + 1, right, start, end, value);
}

void update(int start, int end, int value) {
	_update(1, 0, length - 1, start, end, value);
}

/*
data_t _query(int node, int left, int right, int start, int end) {
	if (end < left || right < start) return outOfRange();

	if (start <= left && right <= end) return tree[node];

	int mid = (left + right) / 2;

	return merge(_query(node * 2, left, mid, start, end), _query(node * 2 + 1, mid + 1, right, start, end));
}

data_t query(int start, int end) {
	return _query(1, 0, length - 1, start, end);
}
*/

data_t _query(int node, int left, int right, int index) {
	if (index < left || right < index) return outOfRange();

	if (left == right) return tree[node];

	int mid = (left + right) / 2;

	return merge(tree[node], merge(_query(node * 2, left, mid, index), _query(node * 2 + 1, mid + 1, right, index)));
}

data_t query(int index) {
	return arr[index] + _query(1, 0, length - 1, index);
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	cin >> length;
	for (int i = 0; i < length; i++) {
		cin >> arr[i];
	}

	int queries, operation, op1, op2, op3;
	cin >> queries;

	for (int i = 0; i < queries; i++) {
		cin >> operation;

		if (operation == 1) {
			cin >> op1 >> op2 >> op3;
			op1--; op2--;

			update(op1, op2, op3);
		}
		else if (operation == 2) {
			cin >> op1;
			op1--;

			cout << query(op1) << "\n";
		}
	}
}