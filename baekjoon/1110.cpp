#define _CRT_SECURE_NO_WARNINGS

#include <bits/stdc++.h>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	int origin;
	cin >> origin;

	int next = origin;
	int cycle = 0;

	do {
		next = ((next % 10) * 10) + ((next % 10 + next / 10) % 10);

		cycle++;
	} while (origin != next);

	cout << cycle;
}