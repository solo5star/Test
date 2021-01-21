#define _CRT_SECURE_NO_WARNINGS

#include <bits/stdc++.h>

using namespace std;

int arr[300];
int dp[300];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	int n;
	cin >> n;
	
	for (int i = 0; i < n; i++) {
		cin >> arr[i];
	}

	dp[0] = arr[0];
	if (n > 1) dp[1] = arr[1] + arr[0];
	if (n > 2) dp[2] = arr[2] + max(arr[0], arr[1]);

	for (int i = 3; i < n; i++) {
		dp[i] = arr[i] + max(arr[i - 1] + dp[i - 3], dp[i - 2]);
	}

	cout << dp[n - 1];
}