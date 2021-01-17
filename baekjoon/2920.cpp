#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <utility>
#include <algorithm>
#include <string>
#include <vector>
#include <math.h>
#include <queue>
#include <stack>
#include <limits.h>

using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	bool ascending = false, descending = false;

	int num[8];
	for (int i = 0; i < 8; i++) {
		cin >> num[i];

		if (i > 0) {
			ascending |= num[i] > num[i - 1];
			descending |= num[i] < num[i - 1];
		}
	}

	cout << (ascending && descending ? "mixed" : ascending ? "ascending" : "descending");
}