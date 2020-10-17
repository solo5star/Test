#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <utility>
#include <algorithm>
#include <queue>

using namespace std;

queue<int> q;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int count;
	cin >> count;

	int h, w, n;
	for (int i = 0; i < count; i++) {
		cin >> h >> w >> n;

		cout << ((n - 1) % h) + 1;
		w = (n / h) + 1;
		if (w < 10) cout << "0";
		cout << w << "\n";
	}
}