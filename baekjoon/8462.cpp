#define _CRT_SECURE_NO_WARNINGS

#include <bits/stdc++.h>

using namespace std;

using data_t = long long;

using query = struct {
	int left;
	int right;
	int index;
};

vector<data_t> nums;
vector<query> queries;
data_t results[100000];

query cachedQuery = { 0, 0 };
data_t cachedResult = 0;
int cachedCounts[1000001];

void add(int position) {
	data_t num = nums[position];

	cachedResult -= num * cachedCounts[num] * cachedCounts[num];
	cachedCounts[num]++;
	cachedResult += num * cachedCounts[num] * cachedCounts[num];

#ifdef DEBUG
	cout << "+" << num << " ";
#endif
}

void remove(int position) {
	data_t num = nums[position];

	cachedResult -= num * cachedCounts[num] * cachedCounts[num];
	cachedCounts[num]--;
	cachedResult += num * cachedCounts[num] * cachedCounts[num];

#ifdef DEBUG
	cout << "-" << num << " ";
#endif
}

data_t go_query(query q) {
#ifdef DEBUG
	cout << "QUERY " << q.left << "~" << q.right << "\n";
	cout << "  NUMBERS: ";
#endif

	q.left--;

	// extending to left (Add nums)
	while (q.left < cachedQuery.left) {
		cachedQuery.left--;
		add(cachedQuery.left);
	}

	// extending to right (Add nums)
	while (cachedQuery.right < q.right) {
		add(cachedQuery.right);
		cachedQuery.right++;
	}

	// shrink to right (Delete nums)
	while (cachedQuery.left < q.left) {
		remove(cachedQuery.left);
		cachedQuery.left++;
	}

	// shrink to left (Delete nums)
	while (q.right < cachedQuery.right) {
		cachedQuery.right--;
		remove(cachedQuery.right);
	}

#ifdef DEBUG
	cout << "\n  RESULT: " << cachedResult << "\n";
#endif

	return cachedResult;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	int n, t, a, b;
	cin >> n >> t;

	for (int i = 0; i < n; i++) {
		cin >> a;
		nums.push_back(a);
	}

	for (int i = 0; i < t; i++) {
		cin >> a >> b;
		queries.push_back({ a, b, i });
	}

	// sqrt decomposition (sort)
	int numsLengthSqrt = sqrt(nums.size());
	sort(queries.begin(), queries.end(), [numsLengthSqrt](const query& a, const query& b) -> bool {
		int aSqrt = a.left / numsLengthSqrt;
		int bSqrt = b.left / numsLengthSqrt;

		return aSqrt != bSqrt ? aSqrt < bSqrt : a.right < b.right;
	});

	for (auto& query : queries) {
		results[query.index] = go_query(query);
	}

	for (int i = 0; i < t; i++) {
		cout << results[i] << "\n";
	}
}