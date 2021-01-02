#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <utility>
#include <algorithm>
#include <math.h>

using namespace std;

typedef unsigned long long uint_64;

uint_64 offset = 0;
uint_64 from = 0;
uint_64 to = 0;
uint_64 length = 0;

int counter = 0;
bool visited[1000001];
bool numbers[1000001];

uint_64 nearest(uint_64 n) {
	return (offset / n + (offset % n != 0)) * n;
}

int addr(uint_64 n) {
	return n - offset;
}

void che(uint_64 n) {
	if (visited[n]) return;

	visited[n] = true;

	uint_64 squared = n * n;
	uint_64 base = nearest(squared);
	int multiplier = 0;

	uint_64 current;

#ifdef DEBUG
	cout << "che(" << n << "): base=" << base << ", squared=" << squared << "\n";
#endif

	while (true) {
		current = base + squared * multiplier;

		if (!(current <= to)) break;

		visited[n * multiplier] = true;

		if (!numbers[addr(current)]) {
#ifdef DEBUG
			cout << current << " is ㅇㅇ" << "\n";
#endif
			numbers[addr(current)] = true;
			counter--;
		}

		multiplier++;
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> from >> to;
	offset = from;
	length = to - from + 1;
	counter = length;

	uint_64 squaredRoot = sqrt(to);

	for (uint_64 n = 2; n <= squaredRoot; n++) {
		che(n);
	}

#ifdef DEBUG
	for (int i = 0; i < length; i++) {
		cout << (i + offset) << ":" << (numbers[i] ? "ㅇㅇ" : "ㄴㄴ") << "\n";
	}
#endif

	cout << counter;
}