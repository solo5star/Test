#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <utility>
#include <algorithm>
#include <queue>
#include <math.h>

using namespace std;

int f(int n) {
	int ft = 1;
	for (int i = 1; i <= n; i++)
		ft *= i;

	return ft;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int n, k;
	cin >> n >> k;

	cout << (f(n) / f(n - k) / f(k));
}