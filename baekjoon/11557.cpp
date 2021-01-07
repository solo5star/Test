#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <utility>
#include <algorithm>
#include <string.h>
#include <math.h>

using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int t, n;
	cin >> t;

	string current;
	int currentCost;
	string best;
	int bestCost = 0;

	while (t--) {
		cin >> n;

		for (int i = 0; i < n; i++) {
			cin >> current;
			cin >> currentCost;

			if (currentCost > bestCost) {
				best = current;
				bestCost = currentCost;
			}
		}

		cout << best << "\n";
	}
}