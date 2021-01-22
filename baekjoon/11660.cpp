#define _CRT_SECURE_NO_WARNINGS

#include <bits/stdc++.h>

using namespace std;

int nums[1025][1025];
int width;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	int num, operations;
	cin >> width >> operations;
	for (int y = 1; y <= width; y++) {
		for (int x = 1; x <= width; x++) {
			cin >> num;

			nums[y][x] = num + nums[y - 1][x] + nums[y][x - 1] - nums[y - 1][x - 1];
		}
	}

	int x1, y1, x2, y2;
	for (int i = 0; i < operations; i++) {
		cin >> y1 >> x1 >> y2 >> x2;

		cout << nums[y2][x2] - (nums[y1 - 1][x2] + nums[y2][x1 - 1] - nums[y1 - 1][x1 - 1]) << "\n";
	}
}