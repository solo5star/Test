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

query cachedQuery;
data_t cachedResult;
int cachedCounts[1000000];

void add(int position) {
	int num = nums[position];

	cachedResult -= pow(cachedCounts[num], 2) * num;
	cachedCounts[num]++;
	cachedResult += pow(cachedCounts[num], 2) * num;
}

void remove(int position) {
	int num = nums[position];

	cachedResult -= pow(cachedCounts[num], 2) * num;
	cachedCounts[num]--;
	cachedResult += pow(cachedCounts[num], 2) * num;
}

data_t calculate_query(query& q) {
	// shrink to right (Delete nums)
	while (cachedQuery.left < q.left) {
		remove(cachedQuery.left);
		cachedQuery.left++;
	}

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

	// shrink to left (Delete nums)
	while (q.right < cachedQuery.right) {
		cachedQuery.right--;
		remove(cachedQuery.right);
	}

#ifdef DEBUG
	cout << "QUERY " << q.left << "~" << q.right << ": " << cachedResult << "\n";
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
		queries.push_back({ a - 1, b, i });
	}

	// sqrt decomposition (sort)
	int numsLengthSqrt = sqrt(nums.size());
	sort(queries.begin(), queries.end(), [numsLengthSqrt](const query& a, const query& b) -> bool {
		int aSqrt = a.left / numsLengthSqrt;
		int bSqrt = b.left / numsLengthSqrt;

		return aSqrt != bSqrt ? aSqrt < bSqrt : a.right < b.right;
	});

	for (auto& query : queries) {
		results[query.index] = calculate_query(query);
	}

	for (int i = 0; i < queries.size(); i++) {
		cout << results[i] << "\n";
	}
}