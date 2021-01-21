#define _CRT_SECURE_NO_WARNINGS

#include <bits/stdc++.h>

using namespace std;

typedef unsigned long long data_t;

const data_t THRESHOLD = 17;
const data_t THRESHOLD_MOD_BY = pow(10, THRESHOLD);

typedef struct {
	data_t num[1000];
} big_int;

void big_int_constructor(big_int& result, const string& str) {
	data_t multiplier = 1;
	int index = 0;

	for (int i = str.length() - 1; i >= 0; i--) {
		result.num[index] += ((data_t)str[i] - '0') * multiplier;

		multiplier *= 10;

		if (multiplier >= THRESHOLD_MOD_BY) {
			multiplier = 1;
			index++;

			result.num[index] = 0;
		}
	}
}

void add(big_int& result, const big_int& a, const big_int& b) {
	data_t part, overflow = 0;
	for (int i = 0; i < 1000; i++) {
		part = a.num[i] + b.num[i];

		result.num[i] = part % THRESHOLD_MOD_BY + overflow;
		overflow = part >= THRESHOLD_MOD_BY;

		if (part == 0) break;
	}
}

void print(big_int& result) {
	int i = 999;
	while (result.num[i] == 0) i--;

	while (i >= 0) {
		cout << result.num[i--];
	}
}

big_int a, b, result;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	string a_str, b_str;
	cin >> a_str >> b_str;

	big_int_constructor(a, a_str);
	big_int_constructor(b, b_str);

	add(result, a, b);
	print(result);
}