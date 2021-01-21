#define _CRT_SECURE_NO_WARNINGS

#include <bits/stdc++.h>

using namespace std;

typedef long double data_t;

typedef struct {
	data_t x;
	data_t y;
} point;

data_t area(point& a, point& b) {
	return (a.x * b.y) - (a.y * b.x);
}

data_t precise_round(data_t n) {
	return floor(n) + ((long long)round(n * 10) % 10) / 10.;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	int n;
	cin >> n;

	point pFirst;
	point p1;
	point p2;

	cin >> pFirst.x >> pFirst.y;
	p1 = pFirst;
	n--;

	data_t sum = 0;

	while (n--) {
		cin >> p2.x >> p2.y;

		sum += area(p1, p2);

		p1 = p2;
	}
	sum += area(p1, pFirst);
	sum = precise_round(abs(sum / 2));

	cout << fixed << setprecision(1) << sum;
}