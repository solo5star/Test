#define _CRT_SECURE_NO_WARNINGS

#include <bits/stdc++.h>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	int x, y, w, h;
	cin >> x >> y >> w >> h;
	cout << min({ w - x, h - y, x, y });
}