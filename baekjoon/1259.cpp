#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <utility>
#include <algorithm>
#include <queue>
#include <math.h>

using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	string n;

	while (true) {
		cin >> n;
		if (n == "0") break;

		int mid = n.length() / 2;
		bool d = true;
		for (int i = 0; i < mid; i++) {
			if (n[i] != n[n.length() - i - 1]) {
				d = false;
				break;
			}
		}

		cout << (d ? "yes" : "no") << "\n";
	}
}