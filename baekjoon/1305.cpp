#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <utility>
#include <algorithm>
#include <string>
#include <vector>
#include <math.h>
#include <cstring>

using namespace std;

int len;
string text;
int failure[1000000];

void calculateFailure() {
	int j = 0;
	for (int i = 1; i < len; i++) {
		while (j > 0 && text[j] != text[i]) {
			j = failure[j - 1];
		}
		if (text[j] == text[i]) {
			failure[i] = ++j;
		}
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> len >> text;

	calculateFailure();

	int lastCommonLength = failure[len - 1];

	cout << len - lastCommonLength;
}