#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <utility>
#include <algorithm>
#include <string.h>
#include <math.h>

using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int n;
	cin >> n;

	int divideBy = 2;
	while (n >= divideBy) {
		if (n % divideBy == 0) {
			cout << divideBy << "\n";
			n = n / divideBy;
		}
		else {
			divideBy++;
		}
	}
}