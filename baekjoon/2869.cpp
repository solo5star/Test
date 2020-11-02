#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <utility>
#include <algorithm>
#include <math.h>
#include <unordered_map>
#include <string>
#include <math.h>

using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int current = 0, a, b, v, days = 1;
	cin >> a >> b >> v;

	while (true) {
		current += a;
		if (current >= v) break;
		current -= b;
		days++;
	}

	cout << days;
}