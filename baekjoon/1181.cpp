#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <utility>
#include <algorithm>
#include <math.h>

using namespace std;

string words[20000];

bool wordcmp(const string& a, const string& b) {
	if (a.length() == b.length()) {
		return a < b;
	}
	return a.length() < b.length();
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int n;
	string word, prevWord = "";
	cin >> n;

	for (int i = 0; i < n; i++) {
		cin >> word;
		words[i] = word;
	}

	sort(words, words + n, wordcmp);

	for (int i = 0; i < n; i++) {
		if (prevWord == words[i]) continue;

		cout << words[i] << "\n";
		prevWord = words[i];
	}
}