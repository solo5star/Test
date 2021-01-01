#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <utility>
#include <algorithm>
#include <math.h>

using namespace std;

int five = 0;
int two = 0;

void count(int num) {
	switch (num) {
	case 0: case 1: case 3: case 7: case 9: return;
	case 2: case 6: two += 1; return;
	case 4: two += 2; return;
	case 5: five += 1; return;
	case 8: two += 3; return;
	}

	while (num % 5 == 0) {
		num /= 5;
		five++;
	}
	while (num % 2 == 0) {
		num /= 2;
		two++;
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int n;
	cin >> n;

	while (n) {
		count(n);
		n--;
	}

	cout << min(five, two);
}