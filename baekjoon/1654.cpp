#define _CRT_SECURE_NO_WARNINGS

#include <bits/stdc++.h>

using namespace std;

typedef long long data_t;

int cables[10000];
int cableCount;
int goal;

int getCurrentCount(int length) {
	int result = 0;
	for (int i = 0; i < cableCount; i++) {
		result += cables[i] / length;
	}
	return result;
}

data_t maxLength = 0;

void parametricSearch(data_t left = 1, data_t right = 1000000) {
	data_t length = (left + right) / 2;

	data_t current = getCurrentCount(length);

#ifdef DEBUG
	cout << "CHECK left=" << left << ", right=" << right << ", length=" << length << ", " << "current=" << current << "\n";
#endif

	if (current >= goal) {
		maxLength = max(maxLength, length);

		if (left == right) return;

		parametricSearch(length + 1, right);
	}
	else {
		if (left == right) return;

		parametricSearch(left, length);
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	cin >> cableCount >> goal;

	for (int i = 0; i < cableCount; i++) {
		cin >> cables[i];
	}

	parametricSearch();

	cout << maxLength;
}