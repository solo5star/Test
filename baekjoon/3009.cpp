#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <utility>
#include <algorithm>
#include <string.h>
#include <math.h>

using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int x = 0, y = 0, temp;

	for (int i = 0; i < 3; i++) {
		cin >> temp;
		x ^= temp;

		cin >> temp;
		y ^= temp;
	}

	cout << x << " " << y;
}