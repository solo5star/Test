#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <utility>
#include <algorithm>
#include <math.h>
#include <unordered_map>
#include <string>
#include <math.h>

using namespace std;

int units[10];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int n, k;
	cin >> n >> k;

	for (int i = n - 1; i >= 0; i--) {
		cin >> units[i];
	}

	int remain = k;
	int coins = 0;
	for(int i = 0; i < n; i++) {
		int currentCoins = remain / units[i];
		remain -= currentCoins * units[i];
		coins += currentCoins;

		if (remain == 0) break;
	}
	cout << coins;
}