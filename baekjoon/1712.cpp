#include <iostream>
#include <utility>
#include <algorithm>
#include <math.h>

using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int a, b, c;

	cin >> a >> b >> c;

	if (c <= b) cout << -1;

	else cout << (a / (c - b)) + 1;
}