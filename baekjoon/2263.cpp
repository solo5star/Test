#define _CRT_SECURE_NO_WARNINGS

#include <bits/stdc++.h>

using namespace std;

// index and value are "reversed"
// i.e. in[1] = 5 => in[5] = 1
int in[100001];
int post[100000];
int pre[100000];

int preIndex = 0;

void tree(int left, int right, int rightOffset = 0) {
	if (left > right) return;

	int root = post[right];
	int mid = in[root] - rightOffset;

	pre[preIndex++] = root;

	if (left == right) return;

	//cout << "SEARCH: " << left << "~" << mid - 1 << " AND " << mid << "~" << right - 1 << "\n";

	// left subtree
	tree(left, mid - 1);

	// right subtree
	tree(mid, right - 1, rightOffset + 1);
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	int n, num;
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> num;

		// reverse
		in[num] = i;
	}

	for (int i = 0; i < n; i++) {
		cin >> post[i];
	}

	tree(0, n - 1);

	for (int i = 0; i < n; i++) {
		cout << pre[i] << " ";
	}
}