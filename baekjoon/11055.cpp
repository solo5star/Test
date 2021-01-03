#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <utility>
#include <algorithm>
#include <string.h>
#include <math.h>

using namespace std;

int numbers[1000];
int dp[1000];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int n, maximum = 0;

	cin >> n;

	for (int i = 0; i < n; i++) {
		cin >> numbers[i];
		dp[i] = numbers[i];
		maximum = max(maximum, numbers[i]);

		for (int j = 0; j < i; j++) {
			if (numbers[j] < numbers[i]) {
				dp[i] = max(dp[i], dp[j] + numbers[i]);
				maximum = max(maximum, dp[i]);
			}
		}
	}

	cout << maximum;
}