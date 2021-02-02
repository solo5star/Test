#define _CRT_SECURE_NO_WARNINGS

#include <bits/stdc++.h>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	int n;
	string str;
	cin >> n >> str;

	int l = 0;
	for (int i = 0; i < n; i++) {
		if (str[i] == 'L') {
			l++;
			i++;
		}
	}

	if (l > 1) {
		cout << n - l + 1;
	}
	else {
		cout << n;
	}
}