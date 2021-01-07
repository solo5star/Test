#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <utility>
#include <algorithm>
#include <string.h>
#include <math.h>

using namespace std;

// true = not prime
// false = prime
bool numbers[10001];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int m, n;
	cin >> m >> n;

	for (int i = 2; i <= n; i++) {
		if (numbers[i] == true) continue;

		for (int j = 2 * i; j <= n; j += i) {
			numbers[j] = true;
		}
	}

	int acc = 0;
	int minPrime = 0;
	for (int i = m; i <= n; i++) {
		if (numbers[i] == true) continue;

		acc += i;
		if (minPrime == 0) minPrime = i;
	}

	if (minPrime) cout << acc << "\n" << minPrime;

	else cout << -1;
}