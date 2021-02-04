#define _CRT_SECURE_NO_WARNINGS

#include <bits/stdc++.h>

using namespace std;

using meet = struct {
	int start;
	int end;
};

meet meets[100000];

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	int n;
	cin >> n;

	for (int i = 0; i < n; i++) {
		cin >> meets[i].start >> meets[i].end;
	}

	sort(meets, meets + n, [](const meet& a, const meet& b) -> bool {
		return a.end < b.end;
	});

	meet previous = { -1,-1 };
	int available = 0;
	for (int i = 0; i < n; i++) {
		if (previous.end < meets[i].start) {
			previous = meets[i];
			available++;
		}
	}

	cout << available;
}