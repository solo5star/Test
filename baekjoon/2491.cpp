#define _CRT_SECURE_NO_WARNINGS

#include <bits/stdc++.h>

using namespace std;

int increase[100000];
int decrease[100000];

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	int n, prev, num;
	cin >> n;

	cin >> prev;
	increase[0] = 1;
	decrease[0] = 1;

	int maxValue = 0;

	for (int i = 1; i < n; i++) {
		cin >> num;

		if (prev <= num) maxValue = max(maxValue, increase[i] = increase[i - 1] + 1);
		else maxValue = max(maxValue, decrease[i] = decrease[i - 1] + 1);

		prev = num;
	}

	cout << maxValue;
}