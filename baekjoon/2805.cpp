#define _CRT_SECURE_NO_WARNINGS

#include <bits/stdc++.h>

using namespace std;

typedef long long data_t;

data_t tree[1000000];
data_t treeCount;

data_t getRemain(data_t length) {
	data_t remain = 0;
	for (int i = 0; i < treeCount; i++) {
		remain += max((data_t)0, tree[i] - length);
	}
	return remain;
}

data_t parametricSearch(data_t goal) {
	data_t left = 0, right = 2000000000;

	data_t maxLength;

	while (left < right) {
		data_t mid = (left + right) / 2;

		if (getRemain(mid) >= goal) {
			maxLength = max(maxLength, mid);

			left = mid + 1;
		}
		else {
			right = mid;
		}
	}
	return maxLength;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	data_t goal;
	cin >> treeCount >> goal;

	for (int i = 0; i < treeCount; i++) {
		cin >> tree[i];
	}

	cout << parametricSearch(goal);
}