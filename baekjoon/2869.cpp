#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <utility>
#include <algorithm>
#include <string>
#include <math.h>

using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	double a, b, v;
	cin >> a >> b >> v;

	cout << (a > v ? 1 : (int)ceil((v - a) / (a - b)) + 1);
}