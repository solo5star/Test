#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <utility>
#include <algorithm>
#include <string>
#include <vector>
#include <math.h>
#include <cstring>

using namespace std;

int pi[1000000];
string text;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	while (true) {
		cin >> text;
		if (text == ".") break;

		int len = text.length();

		memset(pi, 0, len);

		int j = 0;
		for (int i = 1; i < len; i++) {
			while (j > 0 && text[j] != text[i]) {
				j = pi[j - 1];
			}
			if (text[j] == text[i]) {
				pi[i] = ++j;
			}
		}

		int patternLength = len - pi[len - 1];

		bool validated = len % patternLength == 0;
		if(validated) for (int i = 0; i < len; i++) {
			if (text[i % patternLength] != text[i]) {
				validated = false;
				break;
			}
		}

		cout << (validated ? len / patternLength : 1) << "\n";
	}
}