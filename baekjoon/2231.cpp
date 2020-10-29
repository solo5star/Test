#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <utility>
#include <algorithm>
#include <math.h>
#include <unordered_map>
#include <string>

using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int n, result = 0;
	cin >> n;

	for (int i = 1; i < n; i++) {
		int eachN;
		int currN = i;
		int acc = i;

		do {
			eachN = currN % 10;
			currN /= 10;

			acc += eachN;
		} while (currN);

		if (acc == n) {
			result = i;
			break;
		}
	}

	cout << result;
}