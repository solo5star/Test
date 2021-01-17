#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <utility>
#include <algorithm>
#include <string>
#include <vector>
#include <math.h>
#include <queue>
#include <stack>
#include <limits.h>

using namespace std;

double calories[1000];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	int n;
	double basePrice, additionalPrice;
	double baseCalorie;
	double additionalCalorie;

	double baseCaloriePerPrice;

	cin >> n;
	cin >> basePrice >> additionalPrice;
	cin >> baseCalorie;

	baseCaloriePerPrice = baseCalorie / basePrice;

	for (int i = 0; i < n; i++) {
		cin >> calories[i];
	}

	sort(calories, calories + n);

	for (int i = n - 1; i >= 0; i--) {
		additionalCalorie = calories[i];

		if (additionalCalorie / additionalPrice > baseCaloriePerPrice) {
			basePrice += additionalPrice;
			baseCalorie += additionalCalorie;

			baseCaloriePerPrice = baseCalorie / basePrice;
		}
	}

	cout << (int)baseCaloriePerPrice;
}