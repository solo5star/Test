#define _CRT_SECURE_NO_WARNINGS

#include <bits/stdc++.h>

using namespace std;

typedef long long data_t;

data_t arr[1000000];
data_t x[1000000];
data_t x_size;

int lower_bound(int num) {
	int left = 0, right = x_size - 1;

	while (left < right) {
		int mid = (left + right) / 2;

		if (x[mid] < num) {
			left = mid + 1;
		}
		else {
			right = mid;
		}
	}
	return left;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	int n;
	cin >> n;

	cin >> arr[0];
	x[0] = arr[0];
	x_size = 1;

	for (int i = 1; i < n; i++) {
		cin >> arr[i];

		int low = lower_bound(arr[i]);

		if (arr[i] < x[low]) {
			x[low] = arr[i];
		}
		else if (x[low] < arr[i]) {
			x[low + 1] = arr[i];
			x_size++;
		}
	}

	cout << x_size;
}