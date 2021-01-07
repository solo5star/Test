#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <utility>
#include <algorithm>
#include <string.h>
#include <math.h>

using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	string str;
	cin >> str;

	int len = str.length();
	int half = len >> 1;

	bool palindrome = true;
	for (int i = 0; i <= half; i++) {
		if (str[i] != str[len - i - 1]) {
			palindrome = false;
			break;
		}
	}

	cout << (palindrome ? 1 : 0);
}