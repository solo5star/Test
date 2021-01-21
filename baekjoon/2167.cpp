#define _CRT_SECURE_NO_WARNINGS

#include <bits/stdc++.h>

using namespace std;

int arr[301][301];
int width;
int height;

int sum(int x1, int y1, int x2, int y2) {
	x1--;
	y1--;

	return arr[y2][x2] - (arr[y2][x1] + arr[y1][x2] - arr[y1][x1]);
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	cin >> height >> width;
	for (int y = 1; y <= height; y++) {
		for (int x = 1; x <= width; x++) {
			cin >> arr[y][x];

			arr[y][x] += arr[y - 1][x] + arr[y][x - 1] - arr[y - 1][x - 1];
		}
	}

	int k;
	cin >> k;

	int x1, y1, x2, y2;
	while (k--) {
		cin >> y1 >> x1 >> y2 >> x2;

		cout << sum(x1, y1, x2, y2) << "\n";
	}
}