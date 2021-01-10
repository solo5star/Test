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

	int n, m;
	cin >> m >> n;

	int mSqrooted = ceil(sqrt(m));
	int nSqrooted = sqrt(n);
	int acc = 0;
	for (int i = mSqrooted; i <= nSqrooted; i++) {
		acc += i * i;
	}
	if (acc == 0) {
		cout << -1;
	}
	else {
		cout << acc << "\n" << mSqrooted * mSqrooted;
	}
}