#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <utility>
#include <algorithm>
#include <math.h>

using namespace std;

int fibonacci(int n) {
	if (n == 0) return 0;
	if (n == 1) return 1;
	if (n == 2) return 1;

	n -= 2;

	int a = 1, b = 1;
	int current = 2;
	while (n) {
		current = a + b;
		a = b;
		b = current;
		n--;
	}
	return current;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int n;
	cin >> n;

	cout << fibonacci(n);
}