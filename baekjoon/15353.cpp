#define _CRT_SECURE_NO_WARNINGS

#include <bits/stdc++.h>

using namespace std;

typedef unsigned long long data_t;

const data_t THRESHOLD = 17;
const data_t THRESHOLD_MOD_BY = pow(10, THRESHOLD);

typedef struct {
	int index;
	data_t num[1000];
} big_int;

void big_int_constructor(big_int& result, const string& str) {
	data_t multiplier = 1;
	int index = 0;

	for (int i = str.length() - 1; i >= 0; i--) {
		result.num[result.index] += ((data_t)str[i] - '0') * multiplier;

		multiplier *= 10;

		if (multiplier >= THRESHOLD_MOD_BY) {
			multiplier = 1;
			result.index++;

			result.num[result.index] = 0;
		}
	}

	if (result.num[result.index]) result.index++;
}

void big_int_add(big_int& result, const big_int& a, const big_int& b) {
	data_t part, overflow = 0;
	result.index = max(a.index, b.index);

	for (int i = 0; i <= result.index; i++) {
		part = a.num[i] + b.num[i];

		result.num[i] = part % THRESHOLD_MOD_BY + overflow;
		overflow = part >= THRESHOLD_MOD_BY;
	}

	if (result.num[result.index]) result.index++;
}

void big_int_print(big_int& result) {
	if (result.index == 0) {
		cout << "0";
		return;
	}

	bool isHead = true;
	for (int i = result.index - 1; i >= 0; i--) {
		if (!isHead) {
			cout << setfill('0') << setw(THRESHOLD);
		}
		cout << result.num[i];
		isHead = false;
	}
}

string a_str, b_str;
big_int a, b, result;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	cin >> a_str >> b_str;

	big_int_constructor(a, a_str);
	big_int_constructor(b, b_str);

	big_int_add(result, a, b);
	big_int_print(result);
}