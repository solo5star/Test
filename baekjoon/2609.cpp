#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <utility>
#include <algorithm>
#include <string>
#include <math.h>
#include <queue>
#include <unordered_map>

using namespace std;

int gcd(int a, int b) {
	int tmp;
	if (a < b) {
		tmp = a;
		a = b;
		b = tmp;
	}
	while (b) {
		tmp = a % b;
		a = b;
		b = tmp;
	}
	return a;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int a, b;
	cin >> a >> b;

	int c = gcd(a, b);
	cout << c << "\n" << (a * b) / c;
}