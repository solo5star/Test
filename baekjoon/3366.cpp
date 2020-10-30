#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <utility>
#include <algorithm>
#include <math.h>
#include <unordered_map>
#include <string>
#include <math.h>

using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int n, number, prev, acc = 0;
	cin >> n;

	for (int i = 0; i < n; i++) {
		cin >> number;

		if (i != 0) {
			acc += max(prev, number);
		}

		prev = number;
	}

	cout << acc;
}