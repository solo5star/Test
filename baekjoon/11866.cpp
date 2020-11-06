#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <utility>
#include <algorithm>
#include <string>
#include <math.h>
#include <queue>

using namespace std;

queue<int> q;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int n, k;
	cin >> n >> k;

	for (int i = 1; i <= n; i++) {
		q.push(i);
	}

	cout << "<";
	bool printComma = false;

	int a = 0;
	while (!q.empty()) {
		a++;
		if (a == k) {
			a = 0;

			if (printComma) cout << ", ";
			printComma = true;

			cout << q.front();
			q.pop();
		}
		else {
			q.push(q.front());
			q.pop();
		}
	}

	cout << ">";
}