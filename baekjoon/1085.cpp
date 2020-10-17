#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <utility>
#include <algorithm>
#include <queue>
#include <math.h>

using namespace std;

queue<int> q;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int x, y, w, h;
	cin >> x >> y >> w >> h;

	cout << (min(min(h - y, y), min(w - x, x)));
}