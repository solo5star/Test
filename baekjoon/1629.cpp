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

// n is exponent of 2 (2^n)
uint_64 power(int n) {
	if (n == 0) return base;
	if (memo[n] != 0) return memo[n];

	uint_64 powered = power(n - 1);

	return memo[n] = (powered * powered) % modBy;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
	cin >> base >> n >> modBy;

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