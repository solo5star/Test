#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <utility>
#include <algorithm>
#include <math.h>
#include <unordered_map>
#include <string>

using namespace std;

unordered_map<string, string> passwords;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int n, m;
	string site, password;
	cin >> n >> m;

	for (int i = 0; i < n; i++) {
		cin >> site >> password;
		passwords[site] = password;
	}

	for (int i = 0; i < m; i++) {
		cin >> site;
		cout << passwords[site] << "\n";
	}
}