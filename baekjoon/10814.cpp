#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <utility>
#include <algorithm>
#include <queue>
#include <math.h>

using namespace std;

typedef pair<int, string> member;

member members[100000];

bool compare(const member& a, const member& b) {
	return a.first < b.first;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int n, age;
	string name;
	cin >> n;

	for (int i = 0; i < n; i++) {
		cin >> age >> name;
		members[i] = make_pair(age, name);
	}

	stable_sort(members, members + n, compare);

	for (int i = 0; i < n; i++) {
		cout << members[i].first << " " << members[i].second << "\n";
	}
}