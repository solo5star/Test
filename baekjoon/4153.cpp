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

	int n1, n2, n3, tmp;

	while (true) {
		cin >> n1 >> n2 >> n3;

		if ((n1 | n2 | n3) == 0) break;

		if (n1 > n3) {
			tmp = n1;
			n1 = n3;
			n3 = tmp;
		}
		if (n2 > n3) {
			tmp = n2;
			n2 = n3;
			n3 = tmp;
		}

		if (n1 * n1 + n2 * n2 == n3 * n3) {
			cout << "right\n";
		}
		else {
			cout << "wrong\n";
		}
	}
}