#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <utility>
#include <algorithm>
#include <math.h>

using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int n, level;
	string ps;
	bool vps;

	cin >> n;

	for (int i = 0; i < n; i++) {
		cin >> ps;
		level = 0;
		vps = true;

		for (int j = 0; j < ps.length(); j++) {
			if (ps[j] == '(') {
				level++;
			}
			else {
				level--;
				if (level < 0) {
					// Unexpected token ')', expected '('
					vps = false;
					break;
				}
			}
		}

		// Unexpected end of character, expected ')'
		if (level > 0) vps = false;

		cout << (vps ? "YES" : "NO") << "\n";
	}
}