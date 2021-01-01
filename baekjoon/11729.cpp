#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <utility>
#include <algorithm>
#include <math.h>

using namespace std;

void move(int from, int to) {
	cout << from << " " << to << "\n";
}

void hanoi(int num, int from, int to, int mid) {
	if (num == 1) {
		move(from, to);
		return;
	}
	hanoi(num - 1, from, mid, to);
	move(from, to);
	hanoi(num - 1, mid, to, from);
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int n;
	cin >> n;

	cout << (int)pow(2, n) - 1 << "\n";
	hanoi(n, 1, 3, 2);
}