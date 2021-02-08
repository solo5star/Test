#define _CRT_SECURE_NO_WARNINGS

#include <bits/stdc++.h>

using namespace std;

struct {
	int num;
	int queriesAccumulated;
} tree[262144];
int nums[100000];
int length;

const int Q_UPDATE = 1;
const int Q_QUERY = 2;

void update(int node, int left, int right, int begin, int end) {
	if (end < left || right < begin) return;

	if (begin <= left && right <= end) {
		tree[node].num += left - begin + 1;
		tree[node].queriesAccumulated++;

		//cout << "UPDATE (" << left << "~" << right << ") num=" << tree[node].num << ", queriesAccumulated=" << tree[node].queriesAccumulated << "\n";

		return;
	}

	int mid = (left + right) / 2;

	update(node * 2, left, mid, begin, end);
	update(node * 2 + 1, mid + 1, right, begin, end);
}

void update(int begin, int end) {
	update(1, 0, length - 1, begin, end);
}

int query(int node, int left, int right, int index) {
	if (index < left || right < index) return 0;

	if (left == right) return tree[node].num;

	int mid = (left + right) / 2;

	return tree[node].num + (tree[node].queriesAccumulated * (index - left))
		+ query(node * 2, left, mid, index)
		+ query(node * 2 + 1, mid + 1, right, index);
}

int query(int index) {
	return nums[index] + query(1, 0, length - 1, index);
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	cin >> length;
	for (int i = 0; i < length; i++) {
		cin >> nums[i];
	}

	int queries;
	cin >> queries;

	int operation, a, b;
	for (int i = 0; i < queries; i++) {
		cin >> operation;

		switch (operation) {
		case Q_UPDATE:
			cin >> a >> b;
			update(a - 1, b - 1);
			break;
			
		case Q_QUERY:
			cin >> a;
			cout << query(a - 1) << "\n";
			break;
		}
	}
}