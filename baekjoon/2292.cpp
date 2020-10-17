#include <iostream>
#include <utility>
#include <algorithm>
#include <math.h>

using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int a;

	cin >> a;

	cout << (a == 1 ? 1 : (((int)sqrt(((a - 1) / 6) * 8 + 1) - 1) >> 1) + 2);
}