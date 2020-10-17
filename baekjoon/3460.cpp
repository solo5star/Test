#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <utility>
#include <algorithm>
#include <queue>
#include <math.h>

using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int n, k, j;
	cin >> n;

	for (int i = 0; i < n; i++) {
		cin >> k;
		j = 0;
		bool p = false;
		while (k) {
			if (k & 1) {
				if (p) cout << " ";
				cout << j;
				p = true;
			}
			k = k >> 1;
			j++;
		}
	}
}