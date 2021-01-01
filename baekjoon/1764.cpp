#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <utility>
#include <algorithm>
#include <math.h>
#include <unordered_set>

using namespace std;

unordered_set<string> names;
string find_names[500000];
int result = 0;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int n, m;
	string name;
	cin >> n >> m;

	for (int i = 0; i < n; i++) {
		cin >> name;
		names.insert(name);
	}

	for (int i = 0; i < m; i++) {
		cin >> name;
		if (names.count(name)) find_names[result++] = name;
	}

	sort(find_names, find_names + result);

	cout << result << "\n";

	for (int i = 0; i < result; i++) {
		cout << find_names[i] << "\n";
	}
}