#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <utility>
#include <algorithm>
#include <string.h>
#include <math.h>

using namespace std;

typedef unsigned long long uint_64;

uint_64 base;
int n;
uint_64 modBy;
uint_64 memo[100000];
int memoIndex = 1;

// n is exponent of 2 (2^n)
uint_64 power(int n) {
	while (memoIndex <= n) {
		memo[memoIndex] = (memo[memoIndex - 1] * memo[memoIndex - 1]) % modBy;

		memoIndex++;
	}

	return memo[n];
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
	cin >> base >> n >> modBy;

	memo[0] = base % modBy;

	int expOf2 = 0;
	uint_64 acc = 1;
	while (n > (1 << expOf2)) {
		if (n & (1 << expOf2)) {
			acc = (acc * power(expOf2)) % modBy;
		}

		expOf2++;
	}

	cout << (acc % modBy);
}