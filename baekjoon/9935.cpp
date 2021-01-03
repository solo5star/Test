#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <utility>
#include <algorithm>
#include <string.h>
#include <math.h>

using namespace std;

char str[1000001];
char delim[37];

int rIndex = 0;
int mIndex = 0;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> str;
	cin >> delim;

	int len_str = strlen(str);
	int len_delim = strlen(delim);
	int matches;

	while(mIndex < len_str) {
		str[rIndex] = str[mIndex];

		matches = 0;
		for (int i = 0; i < len_delim; i++) {
			if (rIndex - i < 0) break;

			if (str[rIndex - i] != delim[len_delim - i - 1]) break;
			
			matches++;
		}

		if (matches == len_delim) {
			rIndex -= len_delim;
		}

		rIndex++;
		mIndex++;
	}
	str[rIndex] = '\0';

	cout << (str[0] ? str : "FRULA");
}