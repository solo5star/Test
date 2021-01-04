#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <utility>
#include <algorithm>
#include <string.h>
#include <math.h>

using namespace std;

typedef unsigned long long uint_64;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	uint_64 a, b;
	int count = 0;
	cin >> a >> b;

	while (a < b) {
		if (b % 10 == 1) {
			b /= 10;
		}
		else if (b % 2 == 0) {
			b /= 2;
		}
		else {
			break;
		}
		count++;
	}

	count = a == b ? count + 1 : -1;

	cout << count;
}