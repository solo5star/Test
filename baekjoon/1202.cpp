#define _CRT_SECURE_NO_WARNINGS

#include <bits/stdc++.h>

using namespace std;

using jewelry = struct {
	int weight;
	int price;
};

jewelry jewelries[300000];
multiset<int> bags;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	int n, k, a;
	cin >> n >> k;

	for (int i = 0; i < n; i++) {
		cin >> jewelries[i].weight >> jewelries[i].price;
	}

	for (int i = 0; i < k; i++) {
		cin >> a;
		bags.insert(a);
	}

	sort(jewelries, jewelries + n, [](const jewelry& a, const jewelry& b) -> bool {
		return a.price != b.price ? a.price > b.price : a.weight < b.weight;
	});

	int sum = 0;

	for (int i = 0; i < k; i++) {
		auto it = lower_bound(bags.begin(), bags.end(), jewelries[i].weight);

		if (*it < jewelries[i].weight) continue;

		sum += jewelries[i].price;
		bags.erase(it);
	}

	cout << sum;
}