#include <iostream>
#include <utility>
#include <algorithm>
#include <math.h>

using namespace std;

// 0 : not searched
// 1 : prime number
// 2 : not prime number
int arr[1000001];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int n, m;

	cin >> n >> m;

	for (int i = 2; i <= m; i++) {
		if (arr[i] != 0) continue;

		int j = ((n / i + (n % i ? 1 : 0)) * i);
		if (j == i) arr[j] = 1;
		else arr[j] = 2;

		// filtering not prime number
		for (int k = j + i; k <= m; k += i) {
			arr[k] = 2;
		}
	}

	for (int i = n; i <= m; i++) {
		if (arr[i] == 1) cout << i << "\n";
	}
}