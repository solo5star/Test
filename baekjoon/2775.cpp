#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <utility>
#include <algorithm>
#include <math.h>
#include <unordered_map>
#include <string>

using namespace std;

int villegers[15][15];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	for (int i = 0; i < 15; i++) {
		for (int j = 1; j < 15; j++) {
			if (i == 0 || j == 1) {
				villegers[i][j] = j;
			}
			else {
				villegers[i][j] = villegers[i - 1][j] + villegers[i][j - 1];
			}
		}
	}

	int t, k, n;
	cin >> t;
	for (int i = 0; i < t; i++) {
		cin >> k >> n;
		cout << villegers[k][n] << "\n";
	}
}