#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <utility>
#include <algorithm>
#include <math.h>

using namespace std;

pair<int, int> arr[500001];

bool compare(const pair<int, int>& a, const pair<int, int>& b) {
	return a.second < b.second;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int n;
	cin >> n;

	for (int i = 0; i < n; i++) {
		arr[i].first = i;
		cin >> arr[i].second;
	}

	stable_sort(arr, arr + n, compare);

	int max = 1;
	for (int i = 0; i < n; i++) {
		int diff = arr[i].first - i + 1;
		if (diff > max) max = diff;
	}

	cout << max;
}