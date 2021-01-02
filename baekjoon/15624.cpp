#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <utility>
#include <algorithm>
#include <math.h>

using namespace std;

typedef unsigned long long uint_64;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int n;
	cin >> n;

	if (n == 0) cout << 0;
	else if (n == 1) cout << 1;
	else {
		int fn_2 = 0, fn_1 = 1, fn = 1;

		for (int i = 2; i <= n; i++) {
			fn = (fn_1 + fn_2) % 1000000007;

			fn_2 = fn_1;
			fn_1 = fn;
		}
		cout << fn;
	}
}