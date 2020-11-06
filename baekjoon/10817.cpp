#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <utility>
#include <algorithm>
#include <string>
#include <math.h>
#include <queue>

using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int a, b, c, tmp;

	cin >> a >> b >> c;

	if (a < b) {
		tmp = a;
		a = b;
		b = tmp;
	}

	if (b < c) {
		tmp = c;
		c = b;
		b = tmp;
	}

	cout << b;
}