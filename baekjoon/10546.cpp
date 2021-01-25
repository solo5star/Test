#define _CRT_SECURE_NO_WARNINGS

#include <bits/stdc++.h>
#include <unordered_map>

using namespace std;

unordered_map<string, int> names;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	int n;
	cin >> n;

	string name;
	for (int i = 0; i < n; i++) {
		cin >> name;

		if (names.count(name)) names[name] += 1;
		else names[name] = 1;
	}

	for (int i = 0; i < n - 1; i++) {
		cin >> name;

		names[name]--;
		if (names[name] == 0) names.erase(name);
	}

	for (auto& it : names) {
		cout << it.first;
	}
}