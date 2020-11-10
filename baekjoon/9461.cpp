#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <utility>
#include <algorithm>
#include <math.h>

using namespace std;

int lens[101] = { 0, 1, 1, 1, 2, 2, 3, 4, 5, 7, 9 };

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int t, n;
	cin >> t;

	for (int i = 0; i < t; i++) {
		cin >> n;

		if (lens[n]) {
			cout << lens[n] << "\n";
		}
		for (int j = 6; j <= n; j++) {
			lens[j] = lens[j - 1] + lens[j - 5];
		}

		cout << lens[n] << "\n";
	}
}