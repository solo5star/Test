#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <utility>
#include <algorithm>
#include <string>
#include <math.h>
#include <queue>
#include <unordered_map>
#include <set>

using namespace std;

int from, to;

bool baseNumbers[1000001];
bool che[1000001];
int cheCount;

bool inChe(int n) {
	if (!(from <= n && n <= to)) return false;

	return che[n - from];
}

void addChe(int n) {
	if (!(from <= n && n <= to)) return;

	if (che[n - from]) return;

	che[n - from] = true;
	cheCount--;

	// cout << n << "\n";
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> from >> to;
	cheCount = to - from + 1;

	int maxN = (int)sqrt(to) + 1;

	for (int i = 2; i < maxN; i++) {
		int squared = i * i;
		int startN = max(1, from / squared) * squared;

		if (inChe(startN)) continue;

		for (int j = 0; ; j++) {
			int squaredX = startN + squared * j;

			if (squaredX > to) break;

			addChe(squaredX);
		}
	}

	cout << cheCount;
}