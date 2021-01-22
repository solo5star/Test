#define _CRT_SECURE_NO_WARNINGS

#include <bits/stdc++.h>

using namespace std;

int arr[100000];

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	int n;
	cin >> n;

	for (int i = 0; i < n; i++) {
		cin >> arr[i];
	}

	sort(arr, arr + n, greater<int>());

	int best = 0;
	for (int i = 0; i < n; i++) {
		int z = arr[i] * (i + 1);
		if (z > best) {
			best = z;
		}
		else {
			break;
		}
	}

	cout << best;
}