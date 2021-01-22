#define _CRT_SECURE_NO_WARNINGS

#include <bits/stdc++.h>

using namespace std;

typedef int data_t;

data_t tree[1048576];
data_t nums[500000];
int length;

void _update(int node, int left, int right, int start, int end, data_t value) {
	if (right < start || end < left) return;

	if (start <= left && right <= end) {
		tree[node] ^= value;
		return;
	}

	int mid = (left + right) / 2;

	_update(node * 2, left, mid, start, end, value);
	_update(node * 2 + 1, mid + 1, right, start, end, value);
}

void update(int start, int end, data_t value) {
	_update(1, 0, length - 1, start, end, value);
}

data_t _query(int node, int left, int right, int index) {
	if (index < left || right < index) return 0;

	if (left == right) return tree[node];

	int mid = (left + right) / 2;

	return tree[node] ^ _query(node * 2, left, mid, index) ^ _query(node * 2 + 1, mid + 1, right, index);
}

data_t query(int index) {
	return nums[index] ^ _query(1, 0, length - 1, index);
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	//freopen("1.in", "r", stdin);

	cin >> length;

	for (int i = 0; i < length; i++) {
		cin >> nums[i];
	}

	int queries, operation, op1, op2, op3;
	cin >> queries;

	for (int i = 0; i < queries; i++) {
		cin >> operation >> op1;

		switch (operation) {
		case 1:
			cin >> op2 >> op3;
			update(op1, op2, op3);
			break;

		case 2:
			cout << query(op1) << "\n";
			break;
		}
	}
}