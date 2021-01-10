#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <utility>
#include <algorithm>
#include <string>
#include <vector>
#include <math.h>
#include <cstring>

using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int n;
	cin >> n;

	int three = 0;
	while (n > 0 && n % 5 != 0) {
		n -= 3;
		three++;
	}

	if (n < 0) {
		cout << -1;
	}
	else {
		cout << (n / 5) + three;
	}
}