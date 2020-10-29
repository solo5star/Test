#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <utility>
#include <algorithm>
#include <math.h>
#include <unordered_map>
#include <string>

using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int n, step = 1, i = 666, title = 666;
	cin >> n;

	while (step != n) {
		i++;

		int curr = i;
		while (curr) {
			if ((curr % 1000) == 666) {
				title = i;
				step++;
				break;
			}
			curr /= 10;
		}
	}

	cout << title;
}