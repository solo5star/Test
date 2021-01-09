#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <utility>
#include <algorithm>
#include <string>
#include <math.h>

using namespace std;

typedef unsigned long long uint_64;

const uint_64 bit = 1;

void print(uint_64 n) {
	for (int i = 63; i >= 0; i--) {
		cout << ((n & (bit << i)) ? 1 : 0);
	}
	cout << "\n";
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	uint_64 x, k, y = 0;
	cin >> x >> k;

	uint_64 kIndex = 0;

#ifdef DEBUG
	cout << "X=";
	print(x);
	cout << "K=";
	print(k);
#endif

	for(uint_64 i = 0; i < 64; i++) {
		while (x & (bit << i)) i++;

		y |= ((k & (bit << kIndex)) ? bit : 0) << i;

		kIndex++;

#ifdef DEBUG
		cout << "STEP " << i << ": ";
		print(y);
#endif
	}

	cout << y;
}