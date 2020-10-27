#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <utility>
#include <algorithm>
#include <math.h>

using namespace std;

int numbers[10001];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int n;
	int number;
	cin >> n;

	for (int i = 0; i < n; i++) {
		cin >> number;
		numbers[number]++;
	}

	for (int i = 1; i <= n; i++) {
		for(int j = 0; j < numbers[i]; j++)
			cout << i << "\n";
	}
}