#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <utility>
#include <algorithm>
#include <string>
#include <math.h>

using namespace std;

typedef unsigned long long uint_64;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int t, h, w, n;
	cin >> t;
	while (t--) {
		cin >> h >> w >> n;

		int result = ((n - 1) % h + 1) * 100 + ((n - 1) / h + 1);

		cout << result << "\n";
	}
}