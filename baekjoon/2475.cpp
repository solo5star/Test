#include <iostream>
#include <utility>
#include <algorithm>
#include <math.h>

using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int a, b, c, d, e;
	cin >> a >> b >> c >> d >> e;
	cout << ((
		a * a
		+ b * b
		+ c * c
		+ d * d
		+ e * e
	) % 10);
}