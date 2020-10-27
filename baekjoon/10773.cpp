#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <utility>
#include <algorithm>
#include <math.h>
#include <unordered_map>

using namespace std;

int numbers[100000];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int n, top = 0;
	int number;

	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> number;
		if (number == 0) {
			numbers[top--] = 0;
		}
		else {
			numbers[top++] = number;
		}
	}

	int sum = 0;
	for (int i = 0; i < top; i++) {
		sum += numbers[i];
	}
	cout << sum;
}