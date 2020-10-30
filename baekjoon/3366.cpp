#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <utility>
#include <algorithm>
#include <math.h>
#include <unordered_map>
#include <string>

using namespace std;

int numbers[1000000];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int n, number, m, acc = 0;
	cin >> n;

	for (int i = 0; i < n; i++) {
		cin >> number;
		if (i == 0) m = number;
		else m = m > number ? number : m;

		acc += number;
	}

	cout << (acc - m);
}