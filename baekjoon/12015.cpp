#define _CRT_SECURE_NO_WARNINGS

#include <bits/stdc++.h>

using namespace std;

int arr[1000000];
int x[1000000];
int x_length;

int lower_bound(int num, int size) {
	int left = 0, right = size - 1;

	while (left < right) {
		int mid = (left + right) / 2;

		if (x[mid] < num) {
			left = mid + 1;
		}
		else {
			right = mid;
		}
		//cout << "B-SEARCH: " << left << "~" << right << "\n";
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
	x_length = 1;

	for (int i = 1; i < n; i++) {
		cin >> arr[i];

		int low = lower_bound(arr[i], x_length);

		if (x[low] < arr[i]) {
			if (low == x_length - 1) x_length++;

			x[low + 1] = arr[i];
		}
		else if (arr[i] < x[low]) {
			x[low] = arr[i];
		}
 	}

#ifdef DEBUG
	cout << "x[] = {";
	for (int i = 0; i < x_length; i++) {
		cout << x[i] << " ";
	}
	cout << "}\n";
#endif

	cout << x_length;
}