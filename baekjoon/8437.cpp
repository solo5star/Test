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

	unsigned long long a, b;
	cin >> a >> b;

	cout << ((a + b) / 2) << "\n";
	cout << ((a - b) / 2);
}