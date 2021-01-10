#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <utility>
#include <algorithm>
#include <string>
#include <math.h>
#include <vector>

using namespace std;

string text;
string pattern;
int pi[1000000];

vector<int> result;

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

	getline(cin, text);
	getline(cin, pattern);

	calculatePi();

	int count = 0;
	int len = text.length();
	int j = 0;
	for (int i = 0; i < len; i++) {
		while (j > 0 && text[i] != pattern[j]) {
			j = pi[j - 1];
		}

		if (text[i] == pattern[j]) {
			if (j == pattern.length() - 1) {
				count++;
				result.push_back(i - j + 1);
				j = pi[j];
			}
			else {
				j++;
			}
		}
	}

	cout << count << "\n";

	for (auto idx : result) {
		cout << idx << "\n";
	}
}