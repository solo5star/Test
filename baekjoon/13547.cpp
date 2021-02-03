#define _CRT_SECURE_NO_WARNINGS

#include <bits/stdc++.h>

using namespace std;

using query = struct {
	int left;
	int right;
	int index;
};

vector<int> nums;
vector<query> queries;

int results[100000];

int differentNumbers = 0;
int counts[1000001];

void add(int position) {
	if (counts[nums[position]]++ == 0) differentNumbers++;
}

void remove(int position) {
	if (--counts[nums[position]] == 0) differentNumbers--;
}

query current;

int go_query(query q) {
	q.left--;

	// Inflate range
	while (q.left < current.left) {
		current.left--;
		add(current.left);
	}

	// Inflate range
	while (current.right < q.right) {
		add(current.right);
		current.right++;
	}

	// Deflate range
	while (current.left < q.left) {
		remove(current.left);
		current.left++;
	}

	// Deflate range
	while (q.right < current.right) {
		current.right--;
		remove(current.right);
	}

	return differentNumbers;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	int n, m, a, b;
	cin >> n;

	for (int i = 0; i < n; i++) {
		cin >> a;
		nums.push_back(a);
	}

	cin >> m;
	for (int i = 0; i < m; i++) {
		cin >> a >> b;
		queries.push_back({ a, b, i });
	}

	int divBy = sqrt(nums.size());
	sort(queries.begin(), queries.end(), [divBy](const query& a, const query& b) -> bool {
		int aPos = a.left / divBy;
		int bPos = b.left / divBy;

		return aPos != bPos ? aPos < bPos : a.right < b.right;
	});

	for (int i = 0; i < m; i++) {
		results[queries[i].index] = go_query(queries[i]);
	}

	for (int i = 0; i < m; i++) {
		cout << results[i] << "\n";
	}
}