#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <utility>
#include <algorithm>
#include <string>
#include <vector>
#include <math.h>
#include <cstring>
#include <sstream>

using namespace std;

string text;
string pattern;
int pi[1000000];

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

	int n, m;
	cin >> n >> m >> text;

	stringstream ss;
	ss << "I";
	for (int i = 0; i < n; i++) {
		ss << "OI";
	}
	pattern = ss.str();

	calculatePi();

	int found = 0;
	int j = 0;
	for (int i = 0; i < m; i++) {
		while (j > 0 && text[i] != pattern[j]) {
			j = pi[j - 1];
		}
		if (text[i] == pattern[j]) {
			if (j == pattern.length() - 1) {
				found++;
				j = pi[j];
			}
			else {
				j++;
			}
		}
	}

	cout << found;
}