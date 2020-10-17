#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <utility>
#include <algorithm>
#include <queue>
#include <math.h>

using namespace std;

int nums[300000];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int n, m, d, sum;
	cin >> n >> m;

	int minDiff = m;

	for (int i = 0; i < n; i++) {
		cin >> d;
		nums[i] = d;
	}

	for (int i = 0; i < n; i++) {
		for (int j = i + 1; j < n; j++) {
			for (int k = j + 1; k < n; k++) {
				sum = nums[i] + nums[j] + nums[k];
				if (m >= sum && m - sum < minDiff) minDiff = m - sum;
			}
		}
	}

	cout << m - minDiff;
}