#define _CRT_SECURE_NO_WARNINGS

#include <bits/stdc++.h>

using namespace std;

vector<int> nums;
vector<int> L;
vector<int> P;

int lower_bound(int n) {
	int left = 0, right = L.size();

	while (left < right) {
		int mid = (left + right) / 2;

		if (L[mid] < n) {
			left = mid + 1;
		}
		else {
			right = mid;
		}
	}

	return left;
}

// p: index of P (p.size() - 1 to 0)
// l: length of longest subsequence
void backtrace(int p, int l) {
	if (p == -1) return;

	if (P[p] == l) {
		backtrace(p - 1, l - 1);
		cout << nums[p] << " ";
	}
	else {
		backtrace(p - 1, l);
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	int n, num;
	cin >> n;
	while (n--) {
		cin >> num;
		nums.push_back(num);

		int i = lower_bound(num);

		if (i == L.size()) {
			L.push_back(num);
		}
		else {
			L[i] = num;
		}

		P.push_back(i);
	}

	cout << L.size() << "\n";

	backtrace(P.size() - 1, L.size() - 1);
}