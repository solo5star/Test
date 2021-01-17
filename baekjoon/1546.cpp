#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <utility>
#include <algorithm>
#include <string>
#include <vector>
#include <math.h>
#include <queue>
#include <stack>
#include <limits.h>

using namespace std;

double scores[1000];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	int n;
	cin >> n;

	double maxValue = 0;
	for (int i = 0; i < n; i++) {
		cin >> scores[i];

		maxValue = max(maxValue, scores[i]);
	}

	double sum = 0;
	for (int i = 0; i < n; i++) {
		sum += scores[i] / maxValue * 100;
	}

	cout.precision(10);
	cout << sum / n;
}