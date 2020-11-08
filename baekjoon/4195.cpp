#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <utility>
#include <algorithm>
#include <string>
#include <math.h>
#include <queue>
#include <unordered_map>

using namespace std;

unordered_map<string, string> parents;
unordered_map<string, int> relations;

string find(const string& a) {
	// NIL is self (parent)
	if (parents.count(a) == 0) {
		return a;
	}

	return parents[a] = find(parents[a]);
}

void merge(const string& a, const string& b) {
	string _a = find(a);
	string _b = find(b);

	if (_a == _b) return;

	// Update relations
	if (relations.count(_a) == 0) {
		relations[_a] = 1;
	}
	if (relations.count(_b) == 0) {
		relations[_b] = 1;
	}

	// Hey, join my group and union our members!
	relations[_a] += relations[_b];

	// Now, _a is parent (Leader)
	parents[_b] = _a;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int t, n;
	cin >> t;

	string a, b;
	for (int i = 0; i < t; i++) {
		cin >> n;
		for (int j = 0; j < n; j++) {
			cin >> a >> b;

			merge(a, b);
			cout << relations[find(a)] << "\n";
		}

		parents.clear();
		relations.clear();
	}
}