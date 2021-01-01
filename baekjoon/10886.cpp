#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <utility>
#include <algorithm>
#include <math.h>

using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int agree = 0;
	int disagree = 0;

	int n, s;
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> s;
		if (s == 0) disagree++;
		else agree++;
	}

	cout << (agree > disagree ? "Junhee is cute!" : "Junhee is not cute!");
}