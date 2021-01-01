#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <utility>
#include <algorithm>
#include <math.h>

using namespace std;

char str[1000001];
bool explodes[256];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	string explode;
	cin >> str >> explode;

	int len = explode.length();
	for (int i = 0; i < len; i++) {
		explodes[explode[i]] = true;
	}

	int modifyIdx = 0;
	int searchIdx = 0;
	while (str[searchIdx] != '\0') {
		if (explodes[str[searchIdx]]) {
			searchIdx++;
			continue;
		}

		// skip explode character
		str[modifyIdx] = str[searchIdx];

		modifyIdx++;
		searchIdx++;
	}
	str[modifyIdx] = '\0';

	cout << (modifyIdx ? str : "FRULA");
}