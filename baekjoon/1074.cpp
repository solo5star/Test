#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <utility>
#include <algorithm>
#include <math.h>
#include <unordered_map>
#include <string>

using namespace std;

int divAndConquer(int n, int r, int c) {
	int half = n / 2;
	int area = 3;

	if (r < half) area -= 1;
	if (c < half) area -= 2;

	if (r >= half) r -= half;
	if (c >= half) c -= half;

	return area * half * half + (half > 1 ? divAndConquer(half, r, c) : 0);
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
	int n, r, c;
	cin >> n >> r >> c;

	cout << divAndConquer(pow(2, n), c, r);
}