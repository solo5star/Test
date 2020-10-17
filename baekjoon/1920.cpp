#include <iostream>
#include <utility>
#include <algorithm>
#include <math.h>

using namespace std;

bool nums[100001];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int n, m, a;
	cin >> n;

	for (int i = 0; i < n; i++) {
		cin >> a;
		nums[a] = true;
	}

	cin >> m;

	for (int i = 0; i < n; i++) {
		cin >> a;
		cout << (nums[a] ? 1 : 0) << "\n";
	}
}