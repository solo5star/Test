#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <utility>
#include <algorithm>
#include <math.h>

using namespace std;

// 0 : not searched
// 1 : not prime
// 2 : prime
int nums[500001];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int n;
	cin >> n;

	for (int i = 0; i < n; i++) {
		nums[i] = i + 1;
	}

	int i = 0;
	int w = 1;
	int c = n;
	bool remove = true;

	int previos = nums[i];
	int first = 0;

	while(true) {
		if (remove) {
			nums[i] = 0;
			c--;

			if (i == first) {
				first += w;
			}

			if (c == 1) {
				break;
			}
		}

		previos = nums[i];

		i += w;
		if (i >= n || nums[i] == 0) {
			i = first;
			w = w << 1;
		}

		for (int j = 0; j < n; j++)
			cout << nums[j] << " ";
		cout << "\n";

		for (int j = 0; j < n; j++)
			cout << (i == j ? remove ? "'" : "^" : " ") << " ";
		cout << "\n";

		remove = !remove;
	}

	cout << previos;
}