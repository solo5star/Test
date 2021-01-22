#define _CRT_SECURE_NO_WARNINGS

#include <bits/stdc++.h>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	int n;
	cin >> n;

	n = 1000 - n;

	int count = 0;
	count += n / 500;
	n %= 500;

	count += n / 100;
	n %= 100;

	count += n / 50;
	n %= 50;

	count += n / 10;
	n %= 10;

	count += n / 5;
	n %= 5;

	count += n / 1;
	n %= 1;

	cout << count;
}