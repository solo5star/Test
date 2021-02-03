#define _CRT_SECURE_NO_WARNINGS

#include <bits/stdc++.h>
#include <unordered_map>

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

int numsLengthSqrt;

query cachedQuery;
data_t cachedResult;
unordered_map<data_t, int> cachedNums;
unordered_map<data_t, int> cachedNumsDiff;

data_t calculate_query(query& q) {
	// Recalculate vs Using cache
	if (q.right - q.left < abs(cachedQuery.left - q.left) + abs(cachedQuery.right - q.right)) {
		cachedQuery = { 0, 0 };
		cachedResult = 0;
		cachedNums.clear();
	}

	int num;

	while (cachedQuery.left != q.left) {
		num = nums[cachedQuery.left];
		if (cachedNumsDiff.count(num) == 0) cachedNumsDiff[num] = 0;

		// shrink to right (Delete nums)
		if (cachedQuery.left < q.left) {
			cachedNumsDiff[num]--;
			cachedQuery.left++;
		}
		// extending to left (Add nums)
		else {
			cachedNumsDiff[num]++;
			cachedQuery.left--;
		}
	}

	while (q.right != cachedQuery.right) {
		num = nums[cachedQuery.right];
		if (cachedNumsDiff.count(num) == 0) cachedNumsDiff[num] = 0;

		// extending to right (Add nums)
		if (cachedQuery.right < q.right) {
			cachedNumsDiff[num]++;
			cachedQuery.right++;
		}
		// shrink to left (Delete nums)
		else {
			cachedNumsDiff[num]--;
			cachedQuery.right--;
		}
	}

	for (auto& it : cachedNumsDiff) {
		if (cachedNums.count(it.first) != 0) {
			cachedResult -= pow(cachedNums[it.first], 2) * it.first;
			it.second += cachedNums[it.first];
		}

		if (it.second == 0) {
			cachedNums.erase(it.first);
		}
		else {
			cachedResult += pow(it.second, 2) * it.first;
			cachedNums[it.first] = it.second;
		}
	}

#ifdef DEBUG
	cout << "QUERY " << q.left << "~" << q.right << ": " << cachedResult << "\n";
	cout << "  Numbers: ";
	for (auto& it : cachedNumsDiff) {
		cout << it.first << "(" << it.second << ") ";
	}
	cout << "\n";
#endif

	cachedNumsDiff.clear();

	return cachedResult;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	int n, t, a, b;
	cin >> n >> t;

	numsLengthSqrt = sqrt(n);
	for (int i = 0; i < n; i++) {
		cin >> a;
		nums.push_back(a);
	}

	for (int i = 0; i < t; i++) {
		cin >> a >> b;
		queries.push_back({ a - 1, b, i });
	}

	// sqrt decomposition (sort)
	sort(queries.begin(), queries.end(), [](const query& a, const query& b) -> bool {
		int aSqrt = a.left / numsLengthSqrt;
		int bSqrt = b.left / numsLengthSqrt;

		if (aSqrt != bSqrt) return aSqrt < bSqrt;

		return a.right < b.right;
	});

	for (auto& query : queries) {
		results[query.index] = calculate_query(query);
	}

	for (int i = 0; i < queries.size(); i++) {
		cout << results[i] << "\n";
	}
}