#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <utility>
#include <algorithm>
#include <string>
#include <vector>
#include <math.h>

using namespace std;

string text;
string pattern;
int pi[200000];

void calculatePi() {
	int len = pattern.length();
	int j = 0;
	for (int i = 1; i < len; i++) {
		while (j > 0 && pattern[j] != pattern[i]) {
			j = pi[j - 1];
		}
		if (pattern[j] == pattern[i]) {
			pi[i] = ++j;
		}
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> text;
	cin >> pattern;

	int len = text.length();
	int j = 0;
	bool found = false;
	for (int i = 0; i < len; i++) {
		while ('0' <= text[i] && text[i] <= '9') {
			i++;
			if (i >= len) break;
		}

		while (j > 0 && text[i] != pattern[j]) {
			j = pi[j - 1];
		}

		if (text[i] == pattern[j]) {
			if (j == pattern.length() - 1) {
				found = true;
				break;
			}
			else {
				j++;
			}
		}
	}

	cout << (found ? 1 : 0);
}