#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <utility>
#include <algorithm>
#include <math.h>

using namespace std;

// 0 : not searched
// 1 : not prime
// 2 : prime
int nums[1001];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	for (int i = 2; i <= 1000; i++) {
		if (nums[i] != 0) continue;

		for (int j = i; j <= 1000; j += i) {
			nums[j] = (j == i) + 1;
		}
	}

	int n, m, c = 0;
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> m;
		if (nums[m] == 2) c++;
	}
	cout << c;
}