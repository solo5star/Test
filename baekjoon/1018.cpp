#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <utility>
#include <algorithm>
#include <math.h>
#include <unordered_map>
#include <string>
#include <math.h>

using namespace std;

bool chessmap_a[50][50]; // WBWBWB ...
bool chessmap_b[50][50]; // BWBWBW ...

int sumAt(int x, int y) {
	int a = 0;
	int b = 0;

	for (int i = 0; i < 8; i++) {
		for (int j = 0; j < 8; j++) {
			if (chessmap_a[i + y][j + x]) a++;
			if (chessmap_b[i + y][j + x]) b++;
		}
	}

	return a > b ? b : a;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int n, m;
	cin >> n >> m;

	string line;
	for (int i = 0; i < n; i++) {
		cin >> line;
		for (int j = 0; j < m; j++) {
			char expected = (i + j) % 2 ? 'B' : 'W';

			if (line[j] == expected) {
				chessmap_b[i][j] = true;
			}
			else {
				chessmap_a[i][j] = true;
			}
		}
	}

	int min = 8 * 8;

	for (int i = 0; i + 7 < n; i++) {
		for (int j = 0; j + 7 < m; j++) {
			int sum = sumAt(j, i);

			min = sum < min ? sum : min;
		}
	}

	cout << min;
}