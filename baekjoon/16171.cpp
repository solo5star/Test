#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <utility>
#include <algorithm>
#include <string>
#include <vector>
#include <math.h>
#include <string.h>

using namespace std;

char text[101];
char pattern[101];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> text;
	cin >> pattern;

	int len = strlen(text);
	int plen = strlen(pattern);

	int modifyIdx = 0;
	for (int i = 0; i < len; i++) {
		if ('0' <= text[i] && text[i] <= '9') continue;

		text[modifyIdx++] = text[i];
	}
	text[modifyIdx] = '\0';

	len = strlen(text);

	bool found = false;

	for (int i = 0; i < len; i++) {
		int count = 0;

		if(plen - 1 <= i) for (int j = 0; j < plen; j++) {
			if (text[i - j] == pattern[plen - j - 1]) {
				count++;

				if (count == plen) {
					found = true;
					break;
				}
			}
			else break;
		}
	}

	cout << (found ? 1 : 0);
}