#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <utility>
#include <algorithm>
#include <math.h>
#include <unordered_map>

using namespace std;

unordered_map<int, int> numbers;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int n, m;
	int number;

	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> number;
		if (numbers.count(number)) {
			numbers[number]++;
		}
		else {
			numbers[number] = 1;
		}
	}

	cin >> m;
	for (int i = 0; i < m; i++) {
		cin >> number;
		if (numbers.count(number)) {
			cout << numbers[number] << " ";
		}
		else {
			cout << 0 << " ";
		}
	}
}