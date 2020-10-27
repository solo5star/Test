#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <utility>
#include <algorithm>
#include <math.h>

using namespace std;

short numbers[10000000];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int n;
	short number;
	cin >> n;

	for (int i = 0; i < n; i++) {
		cin >> number;
		numbers[i] = number;
	}

	sort(numbers, numbers + n);

	for (int i = 0; i < n; i++) {
		cout << numbers[i] << "\n";
	}
}