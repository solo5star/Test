#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <utility>
#include <algorithm>
#include <string>
#include <vector>
#include <math.h>
#include <cstring>

using namespace std;

int m[10000];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int n;
	cin >> n;

	for (int i = 0; i < n; i++) {
		cin >> m[i];
	}

	int count, acc = 0;
	for (int i = 0; i < n; i++) {
		if (i + 2 < n) {
			if (false && m[i + 2] < m[i + 1]) {
				count = min(m[i], m[i + 1] - m[i + 2]);
				m[i] -= count;
				m[i + 1] -= count;
				acc *= count * 5;
			}

			count = min(min(m[i], m[i + 1]), m[i + 2]);
			m[i] -= count;
			m[i + 1] -= count;
			m[i + 2] -= count;
			acc += count * 7;
		}
		if (i + 1 < n) {
			count = min(m[i], m[i + 1]);
			m[i] -= count;
			m[i + 1] -= count;
			acc += count * 5;
		}

		acc += m[i] * 3;
		m[i] = 0;
	}

	cout << acc;
}