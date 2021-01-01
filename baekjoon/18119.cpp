#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <utility>
#include <algorithm>
#include <math.h>

using namespace std;

int words[10000];

int getMask(string& word) {
	int len = word.length();
	int mask = 0;
	for (int i = 0; i < len; i++) {
		mask |= 1 << (word[i] - 'a');
	}
	return mask;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int n, m, o;
	char x;
	string temp;
	cin >> n >> m;

	for (int i = 0; i < n; i++) {
		cin >> temp;

		words[i] = getMask(temp);
	}

	int query = ~0;
	int matches = 0;
	for (int i = 0; i < m; i++) {
		cin >> o >> x;
		if (o == 1) {
			query &= ~(1 << (x - 'a'));
		}
		else if (o == 2) {
			query |= 1 << (x - 'a');
		}

		for (int j = 0; j < n; j++) {
			if ((words[j] & query) == words[j]) {
				matches++;
			}
		}
		cout << matches << "\n";
		matches = 0;
	}
}