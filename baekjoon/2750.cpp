#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <utility>
#include <algorithm>
#include <string>
#include <math.h>
#include <queue>

using namespace std;

int nums[2001];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int n, num;
	cin >> n;

	for (int i = 0; i < n; i++) {
		cin >> num;
		nums[num + 1000]++;
	}

	for (int i = 0; i < 2001; i++) {
		for (int j = 0; j < nums[i]; j++) {
			cout << (i - 1000) << "\n";
		}
	}
}