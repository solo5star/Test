#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <utility>
#include <algorithm>
#include <string>
#include <vector>
#include <math.h>
#include <cstring>

using namespace std;

int parents[100001];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int n, a, b;
	cin >> n;

	parents[1] = 1;
	for (int i = 1; i < n; i++) {
		cin >> a >> b;

		// parent of node a is exists
		if (parents[a]) parents[b] = a;

		// parent of node b is exists (may)
		else parents[a] = b;
	}

	for(int i = 2; i <= n; i++) {
		cout << parents[i] << "\n";
	}
}